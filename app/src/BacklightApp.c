/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "main.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/StackTaskApp.h"
#include "app/inc/BacklightApp.h"
#include "driver/inc/PwmDriver.h"
#include "driver/inc/AdcDriver.h"
#include "driver/inc/UartDriver.h"
#include "app/inc/TC0App.h"

#define BLT_SAMPLE_CNT  16U
uint8_t gu8Brightness = 0;
uint8_t gu8BLSampleReady = FALSE;
uint8_t gu8BLSampleCount = 0U;

uint16_t gu16TempVoltSample[BLT_SAMPLE_CNT] = {0U};
uint8_t gu8BrightnessUpperLimit = 100U;
uint8_t gu8DeratingEN = FALSE;
uint8_t gu8DeratingReportSwitch = FALSE;
uint8_t guDeratingStatus = BLT_NORMAL_MODE;
uint8_t gu8BatteryProtectionEN = FALSE;
uint8_t gu8GradientValue = 0U;

#define DUTYSTEP 0x0018U

void BacklightApp_BattProtectSet(uint8_t u8Set)
{
    gu8BatteryProtectionEN = u8Set;
}

void BacklightApp_Initial(void)
{
    (void)PwmDriver_Initial();
    (void)PwmDriver_DutySet(0x00U);
    (void)PwmDriver_Start();
}

static void BacklightApp_BrightnessAdgust(uint8_t BrightnessTarget,uint8_t GradientValue)
{
    uint32_t duty=0U;
    if(gu8Brightness == BrightnessTarget){
        /*DO NOTHING*/
    }
    /*TARGET VALUE IS SMALLER THAN OLD BRIGHTNESS*/
    else if(gu8Brightness > BrightnessTarget){
        if((gu8Brightness - BrightnessTarget) < 0x04U){
            gu8Brightness = BrightnessTarget;
        }else{
            if(gu8Brightness >= 0x04U){
                gu8Brightness = gu8Brightness - 0x04U;
            }
			else
			{
                /*Nothing*/
            }
        }
    }
    /*TARGET VALUE IS BIGGER THAN OLD BRIGHTNESS*/
    else
    {
        if((BrightnessTarget - gu8Brightness) < 0x04U){
            gu8Brightness = BrightnessTarget;
        }else{
            gu8Brightness = gu8Brightness + 0x04U;
        }
    }

    if(gu8Brightness >= GradientValue)
    {
        duty = gu8Brightness;
        duty -= GradientValue;
        duty *= BLT_UNITSTEP;
    }
    else
    {
        /*SWUV Static Test Need Double Check*/
		duty = 0U;
    }
	
	duty = ((duty > BLT_PERIOD) ? BLT_PERIOD : duty);

    (void)PwmDriver_DutySet((uint16_t)(duty & 0XFFFFU));
}

void BacklightApp_DimmingControl(void)
{
    uint8_t rdData[6U] = {0U};
    uint8_t BacklightSwitch = 0U;
    uint8_t BrightnessTarget = 0U;
    for (uint8_t count=0U;count<6U;count++){
        rdData[count] = RegisterApp_DHU_Read(0x22U,count);
    }
    BacklightSwitch = rdData[3U];
    BrightnessTarget = rdData[4U];
    BrightnessTarget = ((BrightnessTarget > gu8BrightnessUpperLimit) ? gu8BrightnessUpperLimit : BrightnessTarget);
    if(BacklightSwitch == 0x02U){
        gu8GradientValue = 0U;
        BacklightApp_BrightnessAdgust(BrightnessTarget,0U);
        if(gu8BatteryProtectionEN == FALSE)
        {
            PwmDriver_Start();
        }else{
            PwmDriver_Stop();
        }
    }else if(BacklightSwitch == 0x01U){
        if(gu8GradientValue != BrightnessTarget){
            gu8GradientValue = gu8GradientValue + 4U;
            gu8GradientValue = ((BrightnessTarget >= gu8GradientValue) ? gu8GradientValue : BrightnessTarget);
            BacklightApp_BrightnessAdgust(BrightnessTarget,gu8GradientValue);
            //PwmDriver_Start();
        }else{
            //PwmDriver_Initial();
            BacklightApp_BrightnessAdgust(BrightnessTarget,BrightnessTarget);
            PwmDriver_Stop();
        }
    }else{
        /*ERROR READ FORMAT. NEED CHECK*/
    }

    if(gu8DeratingReportSwitch == TRUE)
    {
        gu8DeratingReportSwitch = FALSE;
        //report Derating
        //StackTaskApp_IRQPush(0x62U);
    }else{/*DO NOTHING*/}
}

static uint8_t BacklightApp_Normal_Mode(uint16_t u16MATemp)
{
	uint8_t u8Return = BLT_NORMAL_MODE;
    gu8DeratingEN = FALSE;
    gu8BrightnessUpperLimit = 100U;
    if(u16MATemp < BLT_TEMP90)
    {
        (void)gu8DeratingEN;
        gu8DeratingEN = TRUE;
        gu8DeratingReportSwitch = TRUE;
        u8Return = BLT_BURN_MODE;
    }else{
        u8Return = BLT_NORMAL_MODE;
    }
	
	return u8Return;
}

static uint8_t BacklightApp_Burn_Mode(uint16_t u16MATemp)
{
    uint8_t u8Return = BLT_BURN_MODE;
    gu8DeratingEN = TRUE;
    gu8BrightnessUpperLimit = 60U;
    if(u16MATemp > BLT_TEMP80)
    {
        TC0App_DerateCntStartSet(TRUE);
        if (TC0App_FlagReturn(FLAG_DERATECOUNT) > 30U)
        {
            TC0App_DerateCntStartSet(FALSE);
            TC0App_FlagReset(FLAG_DERATECOUNT);
			(void)gu8DeratingEN;
            gu8DeratingEN = FALSE;
            gu8DeratingReportSwitch = TRUE;
            u8Return = BLT_NORMAL_MODE;
        }else
        {
            u8Return = BLT_BURN_MODE;
        }
    }else if(u16MATemp < BLT_TEMP93){
        gu8DeratingReportSwitch = TRUE;
        u8Return = BLT_BOIL_MODE;
    }else{
        u8Return = BLT_BURN_MODE;
    }
    return u8Return;
}

static uint8_t BacklightApp_Boil_Mode(uint16_t u16MATemp)
{
	uint8_t u8Return = BLT_BOIL_MODE;
    gu8DeratingEN = TRUE;
    gu8BrightnessUpperLimit = 20U;
    if(u16MATemp > BLT_TEMP80)
    {
        TC0App_DerateCntStartSet(TRUE);
        if (TC0App_FlagReturn(FLAG_DERATECOUNT) > 30U)
        {
            TC0App_DerateCntStartSet(FALSE);
            TC0App_FlagReset(FLAG_DERATECOUNT);
			(void)gu8DeratingEN;
            gu8DeratingEN = FALSE;
            gu8DeratingReportSwitch = TRUE;
            u8Return = BLT_NORMAL_MODE;
        }else
        {
            u8Return = BLT_BOIL_MODE;
        }
    }else if(u16MATemp < BLT_TEMP105){
        gu8DeratingReportSwitch = TRUE;
        u8Return = BLT_SCORCH_MODE;
    }else{
        u8Return = BLT_BOIL_MODE;
    }
	
	return u8Return;
}

static uint8_t BacklightApp_Scorch_Mode(uint16_t u16MATemp)
{
	uint8_t u8Return = BLT_SCORCH_MODE;
    gu8DeratingEN = TRUE;
    gu8BrightnessUpperLimit = 20U;
    if(u16MATemp > BLT_TEMP80)
    {
        TC0App_DerateCntStartSet(TRUE);
        if (TC0App_FlagReturn(FLAG_DERATECOUNT) > 30U)
        {
            TC0App_DerateCntStartSet(FALSE);
            TC0App_FlagReset(FLAG_DERATECOUNT);
			(void)gu8DeratingEN;
            gu8DeratingEN = FALSE;
            gu8DeratingReportSwitch = TRUE;
            u8Return = BLT_NORMAL_MODE;
        }else
        {
            u8Return = BLT_SCORCH_MODE;
        }
    }else{
        u8Return = BLT_SCORCH_MODE;
    }
	return u8Return;
}


/*SWUV Static Test Need Double Check*/
static uint16_t BacklightApp_MAcount(uint16_t u16data[])
{
    uint32_t u32MAresult = 0U;
    for(uint8_t u8count = 0U; u8count<BLT_SAMPLE_CNT; u8count++)
    {
        // u32MAresult = u32MAresult + (uint32_t)(*(u16data + u8count));
        u32MAresult += u16data[u8count];
    }
    u32MAresult = u32MAresult >> 4;
    return (uint16_t)u32MAresult;
}

void BacklightApp_DeratingFlow(void)
{
    uint8_t CurrentStatus = BLT_NORMAL_MODE;
    uint16_t TempVolt = 0U;
    uint16_t u16MATemp = 0U;
    TempVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH1_BLTTEMP);

    gu16TempVoltSample[gu8BLSampleCount] = TempVolt;
    if(gu8BLSampleCount == (BLT_SAMPLE_CNT - 1U)){gu8BLSampleReady = TRUE;}
    gu8BLSampleCount = ((gu8BLSampleCount + 1U) > (BLT_SAMPLE_CNT - 1U)) ? 0U : (gu8BLSampleCount + 1U);
    if(gu8BLSampleReady == TRUE)
    {
        u16MATemp = BacklightApp_MAcount(&gu16TempVoltSample[0]);
        switch (guDeratingStatus)
        {
        case BLT_NORMAL_MODE:
            CurrentStatus = BacklightApp_Normal_Mode(u16MATemp);
            /* code */
            break;
        
        case BLT_BURN_MODE:
            CurrentStatus = BacklightApp_Burn_Mode(u16MATemp);
            /* code */
            break;
        
        case BLT_BOIL_MODE:
            CurrentStatus = BacklightApp_Boil_Mode(u16MATemp);
            /* code */
            break;
        
        case BLT_SCORCH_MODE:
            CurrentStatus = BacklightApp_Scorch_Mode(u16MATemp);
            /* code */
            break;

        default:
            CurrentStatus = BacklightApp_Normal_Mode(u16MATemp);
            break;
        }
    }else{
        /*DO NOTHING*/
    }
    guDeratingStatus = CurrentStatus;
	(void)u16MATemp;
}

void BacklightApp_TempMonitor(void)
{
    static uint8_t u8TxBuffer[60] = {0};
    uint16_t TempVolt = 0U;
    TempVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH1_BLTTEMP);
    sprintf((char *)u8TxBuffer,"TEMP %d DERATE %d STATE %d\r\n",TempVolt,gu8DeratingEN,guDeratingStatus);
    UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
}

/* *****************************************************************************
 End of File
 */
