/* ************************************************************************** */
/** Descriptive File Name

  @Company
    AUO

  @File Name
    BacklightApp.c

  @Summary
    Backlight flow & Dimming setting.

  @Description
    Decrease or Increase the dimming value.
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
#include "app/inc/DiagApp.h"
#include "driver/inc/PwmDriver.h"
#include "driver/inc/AdcDriver.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/PortDriver.h"
#include "app/inc/TC0App.h"

#define BLT_SAMPLE_CNT  16U

uint8_t u8TxBuffer[60] = {0};

uint16_t u16Brightness = 0;
uint8_t u8BLSampleReady = FALSE;
uint8_t u8BLSampleCount = 0U;

uint16_t u16TempVoltSample[BLT_SAMPLE_CNT] = {0U};
uint16_t u16BrightnessUpperLimit = BLT_100P;
uint16_t u16GradientValue = 0U;

uint8_t u8BLT_DERATING_STATUS = BLT_NORMAL_MODE;
uint8_t u8BLT_DERATING_EN = FALSE;
uint8_t u8BLT_DERATING_ALARM_FLAG = FALSE;
uint8_t u8BATT_PROTECT_EN = FALSE;
uint8_t u8RSTRQ_TYPEB_SW = TRUE;

uint16_t u16DimmingStep = 8U;
volatile bool bDimmingUpdateStepFlag = false;

void BacklightApp_BattProtectSet(uint8_t u8Set)
{
    u8BATT_PROTECT_EN = u8Set;
}

void BacklightApp_RstRqSwitchSet(uint8_t u8Set)
{
    u8RSTRQ_TYPEB_SW = u8Set;
}

void BacklightApp_Initial(void)
{
    (void)PwmDriver_Initial();
    (void)PwmDriver_DutySet(0x0000U);
    (void)PwmDriver_Start();
}

void BacklightApp_UpdateDimmingStep(void)
{
    bDimmingUpdateStepFlag = true;
}

static void BacklightApp_BrightnessAdgust(uint16_t BrightnessTarget,uint16_t GradientValue)
{
    uint32_t duty=0U;
    if(u16Brightness == BrightnessTarget){
        /*DO NOTHING*/
    }
    /*TARGET VALUE IS SMALLER THAN OLD BRIGHTNESS*/
    else if(u16Brightness > BrightnessTarget){
        if((u16Brightness - BrightnessTarget) < u16DimmingStep){
            u16Brightness = BrightnessTarget;
        }else{
            if(u16Brightness >= u16DimmingStep){
                u16Brightness = u16Brightness - u16DimmingStep;
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
        if((BrightnessTarget - u16Brightness) < u16DimmingStep){
            u16Brightness = BrightnessTarget;
        }else{
            u16Brightness = u16Brightness + u16DimmingStep;
        }
    }

    if(u16Brightness >= GradientValue)
    {
        duty = u16Brightness;
        duty -= GradientValue;
        duty *= BLT_UNITSTEP;
    }
    else
    {
        /*SWUV Static Test Need Double Check*/
		duty = 0U;
    }
	
    /*Set dimming value to PWM Driver*/
	duty = ((duty > BLT_PERIOD) ? BLT_PERIOD : duty);
    (void)PwmDriver_DutySet((uint16_t)(duty & 0xFFFFU));
    // sprintf((char *)u8TxBuffer,"DUTY %d\r\n",duty);
    // UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
}

static uint8_t BacklightApp_Normal_Mode(uint16_t u16MATemp)
{
	uint8_t u8Return = BLT_NORMAL_MODE;
    u8BLT_DERATING_EN = FALSE;
    u16BrightnessUpperLimit = BLT_100P;
    if(u16MATemp < BLT_TEMP85)
    {
        (void)u8BLT_DERATING_EN;
        u8BLT_DERATING_EN = TRUE;
        u8BLT_DERATING_ALARM_FLAG = TRUE;
        bDimmingUpdateStepFlag = true;
        u8Return = BLT_BURN_MODE;
    }else{
        u8Return = BLT_NORMAL_MODE;
    }
	
	return u8Return;
}

static uint8_t BacklightApp_Burn_Mode(uint16_t u16MATemp)
{
    uint8_t u8Return = BLT_BURN_MODE;
    u8BLT_DERATING_EN = TRUE;
    u16BrightnessUpperLimit = BLT_75P;
    if(u16MATemp > BLT_TEMP80)
    {
        TC0App_DerateCntStartSet(TRUE);
        if (TC0App_TimerReturn(TIMER_DERATECOUNT) > 30U)
        {
            TC0App_DerateCntStartSet(FALSE);
            TC0App_TimerReset(TIMER_DERATECOUNT);
			(void)u8BLT_DERATING_EN;
            u8BLT_DERATING_EN = FALSE;
            u8BLT_DERATING_ALARM_FLAG = TRUE;
            bDimmingUpdateStepFlag = true;
            u8Return = BLT_NORMAL_MODE;
        }else
        {
            u8Return = BLT_BURN_MODE;
        }
    }else if(u16MATemp < BLT_TEMP90){
        u8BLT_DERATING_ALARM_FLAG = TRUE;
        bDimmingUpdateStepFlag = true;
        u8Return = BLT_BOIL_MODE;
    }else{
        u8Return = BLT_BURN_MODE;
    }
    return u8Return;
}

static uint8_t BacklightApp_Boil_Mode(uint16_t u16MATemp)
{
	uint8_t u8Return = BLT_BOIL_MODE;
    u8BLT_DERATING_EN = TRUE;
    u16BrightnessUpperLimit = BLT_40P;
    if(u16MATemp > BLT_TEMP80)
    {
        TC0App_DerateCntStartSet(TRUE);
        if (TC0App_TimerReturn(TIMER_DERATECOUNT) > 30U)
        {
            TC0App_DerateCntStartSet(FALSE);
            TC0App_TimerReset(TIMER_DERATECOUNT);
			(void)u8BLT_DERATING_EN;
            u8BLT_DERATING_EN = FALSE;
            u8BLT_DERATING_ALARM_FLAG = TRUE;
            bDimmingUpdateStepFlag = true;
            u8Return = BLT_NORMAL_MODE;
        }else
        {
            u8Return = BLT_BOIL_MODE;
        }
    }else if(u16MATemp < BLT_TEMP95){
        u8BLT_DERATING_ALARM_FLAG = TRUE;
        bDimmingUpdateStepFlag = true;
        u8Return = BLT_SCORCH_MODE;
    }else{
        u8Return = BLT_BOIL_MODE;
    }
	
	return u8Return;
}

static uint8_t BacklightApp_Scorch_Mode(uint16_t u16MATemp)
{
	uint8_t u8Return = BLT_SCORCH_MODE;
    u8BLT_DERATING_EN = TRUE;
    u16BrightnessUpperLimit = BLT_3P;
    if(u16MATemp > BLT_TEMP80)
    {
        TC0App_DerateCntStartSet(TRUE);
        if (TC0App_TimerReturn(TIMER_DERATECOUNT) > 30U)
        {
            TC0App_DerateCntStartSet(FALSE);
            TC0App_TimerReset(TIMER_DERATECOUNT);
			(void)u8BLT_DERATING_EN;
            u8BLT_DERATING_EN = FALSE;
            u8BLT_DERATING_ALARM_FLAG = TRUE;
            bDimmingUpdateStepFlag = true;
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

void BacklightApp_DimmingControl(void)
{
    uint8_t rdData[3U] = {0U};
    uint8_t BacklightSwitch = 0U;
    uint16_t BrightnessTarget = 0U;

    /*Get DHU command and control the dimming*/
    for (uint8_t count=0U;count<3U;count++){
        rdData[count] = RegisterApp_DHU_Read(CMD_BL_PWM,count);
    }
    /*Backlight On/Off*/
    /* SWRA-01-05: Timer Lock Hold set as 1000ms, avoid rapid-off/on behavior
    ** TIMER_HOLDCOUNT will return 0xFF if hold time > 1000ms
    */
    BacklightSwitch = RegisterApp_DHU_Read(CMD_DISP_EN,CMD_DATA_POS) 
                    & (!RegisterApp_DHU_Read(CMD_DISP_SHUTD,CMD_DATA_POS))
                    & (TC0App_TimerReturn(TIMER_HOLDCOUNT) != 0x00U)
                    & u8RSTRQ_TYPEB_SW
                    & 0x01U ;
    
    /*Dimming target*/
    BrightnessTarget =  ((uint16_t)rdData[CMD_DATA_POS+1U])*256U;
    BrightnessTarget += ((uint16_t)rdData[CMD_DATA_POS])*1U;

    /*Do gradual-dimming function & set threshold value*/
    BrightnessTarget = ((BrightnessTarget > u16BrightnessUpperLimit) ? u16BrightnessUpperLimit : BrightnessTarget);
    
    if(bDimmingUpdateStepFlag == true)
    {
        /* Delta PWM Mod 0x7F (128 dimming step) and plus 1 (at least 1 step a time)*/
        u16DimmingStep = ((BrightnessTarget > u16Brightness) ? (BrightnessTarget - u16Brightness)/0x80 : (u16Brightness - BrightnessTarget)/0x80)
                         + 1U;
        bDimmingUpdateStepFlag = false;
    }
    
    if(BacklightSwitch == BLT_ENABLE){
        /*Check if battery in protection state*/
        if(u8BATT_PROTECT_EN == FALSE)
        {
            PwmDriver_Start();
            u16GradientValue = 0U;
            BacklightApp_BrightnessAdgust(BrightnessTarget,0U);
        }else{
            //PwmDriver_Stop();
            (void)PwmDriver_DutySet((uint16_t)( 0U));
        }
    }else if(BacklightSwitch == BLT_DISABLE){
        /* Directly Close Backlight (PWM set as 0)*/
        u16Brightness = 0U;
        //PwmDriver_Stop();
        (void)PwmDriver_DutySet((uint16_t)( 0U));
    }else{
        /*ERROR READ FORMAT. NEED CHECK*/
    }

    /*Report Derating alarm with one time flag*/
    if(u8BLT_DERATING_ALARM_FLAG == TRUE)
    {
        u8BLT_DERATING_ALARM_FLAG = FALSE;
        //report Derating
        if(u8BLT_DERATING_EN == FALSE)
        {
            DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_TERR_MASK);
        }else if(u8BLT_DERATING_EN == TRUE)
        {
            DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_TERR_MASK);
        }else{
            /* Need To Check*/
        }
    }else{/*DO NOTHING*/}
    // sprintf((char *)u8TxBuffer,"SW %d NOW %02X TARGET %02X GRAD %d BATT_PT %d STEP %d\r\n",BacklightSwitch,u16Brightness,BrightnessTarget,u16GradientValue,u8BATT_PROTECT_EN,u16DimmingStep);
    // UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
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
    TempVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH0_PCBTEMP);

    /* Do check the data base(samples) is ready for result output (BLT_SAMPLE_CNT = 16 times)*/
    u16TempVoltSample[u8BLSampleCount] = TempVolt;
    if(u8BLSampleCount == (BLT_SAMPLE_CNT - 1U)){u8BLSampleReady = TRUE;}
    u8BLSampleCount = ((u8BLSampleCount + 1U) > (BLT_SAMPLE_CNT - 1U)) ? 0U : (u8BLSampleCount + 1U);

    /*Do Backlight stage flow*/
    if(u8BLSampleReady == TRUE)
    {
        u16MATemp = BacklightApp_MAcount(&u16TempVoltSample[0]);
        switch (u8BLT_DERATING_STATUS)
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
        RegisterApp_DHU_Setup(CMD_DTC,DTC_BLT_TEMP_ADC,(uint8_t)(u16MATemp >> 8));
        RegisterApp_DHU_Setup(CMD_DTC,DTC_BLT_TEMP_ADC+1U,(uint8_t)(u16MATemp));
    }else{
        /*DO NOTHING*/
    }
    RegisterApp_DHU_Setup(CMD_DTC,DTC_BKLT_STATE,u8BLT_DERATING_STATUS);
    u8BLT_DERATING_STATUS = CurrentStatus;
    //sprintf((char *)u8TxBuffer,"TEMP %d STATE %d\r\n",u16MATemp,CurrentStatus);
    //UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
	(void)u16MATemp;
}

void BacklightApp_TempMonitor(void)
{
    uint16_t BltTempVolt = 0U;
    uint16_t PcbTempVolt = 0U;
    PcbTempVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH1_BLTTEMP);
    sprintf((char *)u8TxBuffer,"BLT TEMP %d \r\n",PcbTempVolt);
    UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
    RegisterApp_DHU_Setup(CMD_DTC,DTC_PCB_TEMP_ADC,(uint8_t)(PcbTempVolt >> 8));
    RegisterApp_DHU_Setup(CMD_DTC,DTC_PCB_TEMP_ADC+1U,(uint8_t)(PcbTempVolt));

    BltTempVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH0_PCBTEMP);
    sprintf((char *)u8TxBuffer,"PCB TEMP %d DERATE %d STATE %d\r\n",BltTempVolt,u8BLT_DERATING_EN,u8BLT_DERATING_STATUS);
    UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
}

/* *****************************************************************************
 End of File
 */
