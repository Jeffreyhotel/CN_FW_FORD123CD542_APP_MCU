/* ************************************************************************** */
/** Descriptive File Name

  @Company
    AUO

  @File Name
    BatteryApp.c

  @Summary
    Encounter Battery Voltage detection and Battery protection mechanism.

  @Description
    -Polling 10ms 20times moving average for battery protection mechanism.
    -Setup a state machine to behavior the mechanism.
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
#include "app/inc/BatteryApp.h"
#include "app/inc/BacklightApp.h"
#include "driver/inc/AdcDriver.h"
#include "driver/inc/PortDriver.h"
#include "driver/inc/UartDriver.h"
#include "app/inc/TC0App.h"

#define BATT_SAMPLE_CNT  20U
uint8_t guBatteryStatus = BT_NORMAL;
uint8_t guBatterySafeKey= FALSE;
uint8_t gu8BattSampleReady = FALSE;
uint8_t gu8BattSampleCount = 0U;
uint16_t gu16BattVoltSample[BATT_SAMPLE_CNT] = {0U};

/*DTC 240321*/
#define BT_VOLT0   755U
/*5V*/
#define BT_VOLT1   815U    
/*5.4V*/
#define BT_VOLT2   906U    
/*6V-Hysteresis*/
#define BT_VOLT3   2718U    
/*18V*/
#define BT_VOLT4   3020U    
/*20V-Hysteresis*/
#define BT_VOLT5   3322U    
/*22V*/ 
#define BT_VOLT6   4095U    
/*24V*/

#define BT_STAGE0   0x00U
#define BT_STAGE1   0x01U
#define BT_STAGE2   0x02U   
/*Hysteresis*/

#define BT_STAGE3   0x03U   
/*Normal*/

#define BT_STAGE4   0x04U   
/*Hysteresis*/

#define BT_STAGE5   0x05U
#define BT_STAGE6   0x06U

void BatteryApp_PowerMonitor(void)
{
    static uint8_t u8TxBuffer[60] = {0};
    uint16_t BatteryVolt = 0U;
    BatteryVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH2_BATVOLT);
    sprintf((char *)u8TxBuffer,"BAT SENSE %d SAFE KEY %d STATE %d\r\n",BatteryVolt,guBatterySafeKey,guBatteryStatus);
    UartDriver_TxWriteString((uint8_t*)u8TxBuffer);
}

static uint8_t BatteryApp_Normal_Mode(uint8_t STAGE)
{
	uint8_t u8Return = BT_NORMAL;
    /*GO STATE MACHINE*/
    switch (STAGE)
    {
    case BT_STAGE0:
        u8Return = BT_OVERPOWER;
        break;
    
    case BT_STAGE1:
        u8Return = BT_LOWHIGH;
        break;

    case BT_STAGE5:
        u8Return = BT_LOWHIGH;
		break;
		
    case BT_STAGE6:
        u8Return = BT_OVERPOWER;
        break;

    default:
        /*TURN ON(BACKLIGHT PWM)*/
        BacklightApp_BattProtectSet(FALSE);
        u8Return = BT_NORMAL;
        break;
    }
	
	return u8Return;
}

static uint8_t BatteryApp_LowHigh_Mode(uint8_t STAGE)
{
	uint8_t u8Return = BT_LOWHIGH;
	
    /*GO STATE MACHINE*/
    switch (STAGE)
    {
    case BT_STAGE0:
        guBatterySafeKey = FALSE;
        //DiagnositicApp_StatusSet(BYTE0,DIAGMASK_B0_BATTUNDERPOWER);
        u8Return = BT_OVERPOWER;
        break;

    case BT_STAGE3:
        guBatterySafeKey = FALSE;
        u8Return = BT_NORMAL;
        break;
    
    case BT_STAGE6:
        guBatterySafeKey = FALSE;
        //DiagnositicApp_StatusSet(BYTE0,DIAGMASK_B0_BATTOVERPOWER);
        u8Return = BT_OVERPOWER;
        break;

    default:
        /*20 SECOND SAFE KEY CHECK*/
        if (guBatterySafeKey == FALSE){
            /*COUNTER RESET*/
            TC0App_TimerReset(TIMER_BATTERYCOUNT);
            TC0App_BatteryCntStartSet(TRUE);
            guBatterySafeKey = TRUE;
        }else{
            /*IF COUNTER > 20SEC*/
            if(TC0App_TimerReturn(TIMER_BATTERYCOUNT) > 20U)
            {
                TC0App_BatteryCntStartSet(FALSE);
                TC0App_TimerReset(TIMER_BATTERYCOUNT);
                guBatterySafeKey = FALSE;
                if(STAGE == BT_STAGE1 || STAGE == BT_STAGE2)
                {
                    //DiagnositicApp_StatusSet(BYTE0,DIAGMASK_B0_BATTUNDERPOWER);
                }else if(STAGE == BT_STAGE4 || STAGE == BT_STAGE5)
                {
                    //DiagnositicApp_StatusSet(BYTE0,DIAGMASK_B0_BATTOVERPOWER);
                }else{
                    /*DO NOTHING*/
                }
                u8Return = BT_OVERPOWER;
            }else{/* DO NOTHING*/}
        }
        break;
    }
	
	return u8Return;
}

static uint8_t BatteryApp_OverPower_Mode(uint8_t STAGE)
{
	uint8_t u8Return = BT_OVERPOWER;
    /*GO STATE MACHINE*/
    switch (STAGE)
    {
    case BT_STAGE3:
        //DiagnositicApp_StatusClear(BYTE0,DIAGMASK_B0_BATTUNDERPOWER);
        //DiagnositicApp_StatusClear(BYTE0,DIAGMASK_B0_BATTOVERPOWER);
        u8Return = BT_NORMAL;
        break;

    default:
        /*TURN OFF(BACKLIGHT PWM)*/
        BacklightApp_BattProtectSet(TRUE);
        u8Return = BT_OVERPOWER;
        break;
    }
	
	return u8Return;
}

static uint8_t BatteryApp_StageCheck(uint16_t BatteryVolt)
{
	/*SWUV Static Test Need Double Check*/
	// uint32_t 
	uint8_t u8Return = 0xFFU;
    if(BatteryVolt <= BT_VOLT0){
        u8Return = BT_STAGE0;
    }else if(BatteryVolt <= BT_VOLT1){
        u8Return = BT_STAGE1;
    }else if(BatteryVolt <= BT_VOLT2){
        u8Return = BT_STAGE2;
    }else if(BatteryVolt <= BT_VOLT3){
        u8Return = BT_STAGE3;
    }else if(BatteryVolt <= BT_VOLT4){
        u8Return = BT_STAGE4;
    }else if(BatteryVolt <= BT_VOLT5){
        u8Return = BT_STAGE5;
    }else if(BatteryVolt <= BT_VOLT6){
        u8Return = BT_STAGE6;
    }else{
        u8Return = 0xFFU;
    }
	
	return u8Return;
}

static uint16_t BatteryApp_MAcount(uint16_t u16data[])
{
    uint16_t u16MAresult = 0U;
    uint8_t u8count = 0U;
    for(u8count = 0U; u8count<BATT_SAMPLE_CNT; u8count++)
    {
        // u16MAresult = u16MAresult + *(u16data + u8count);
        u16MAresult += u16data[u8count];
    }
    u16MAresult = u16MAresult / BATT_SAMPLE_CNT;
    return u16MAresult;
}

void BatteryApp_Flow(void)
{
    uint8_t CurrentStatus = BT_NORMAL;
	uint8_t VoltStage = 0U;
    uint16_t BatteryVolt = 0U;
	uint16_t u16MABatt = 0U;
    BatteryVolt = AdcDriver_ChannelResultGet(ADC_SAR0_TYPE,ADC_SAR0_CH2_BATVOLT);
    gu16BattVoltSample[gu8BattSampleCount] = BatteryVolt;
    if(gu8BattSampleCount == (BATT_SAMPLE_CNT - 1U)){gu8BattSampleReady = TRUE;}
    gu8BattSampleCount = ((gu8BattSampleCount + 1U) > (BATT_SAMPLE_CNT - 1U)) ? (uint8_t)0U : (uint8_t)(gu8BattSampleCount + 1U);
    if(gu8BattSampleReady == TRUE)
    {
        u16MABatt = BatteryApp_MAcount(gu16BattVoltSample);
        VoltStage = BatteryApp_StageCheck(u16MABatt);
        switch (guBatteryStatus)
        {
        case BT_NORMAL:
            CurrentStatus = BatteryApp_Normal_Mode(VoltStage);
            /* code */
            break;
        
        case BT_LOWHIGH:
            CurrentStatus = BatteryApp_LowHigh_Mode(VoltStage);
            /* code */
            break;
        
        case BT_OVERPOWER:
            CurrentStatus = BatteryApp_OverPower_Mode(VoltStage);
            /* code */
            break;
        
        default:
            CurrentStatus = BatteryApp_Normal_Mode(VoltStage);
            break;
        }
        RegisterApp_DHU_Setup(CMD_DTC,DTC_BATT_VOLT_ADC,(uint8_t)(u16MABatt >> 8));
        RegisterApp_DHU_Setup(CMD_DTC,DTC_BATT_VOLT_ADC+1U,(uint8_t)(u16MABatt));
    }
	else
	{
        /*DO NOTHING*/
	}
    guBatteryStatus = CurrentStatus;
	
	(void)VoltStage;
	(void)u16MABatt;
	
}
/* *****************************************************************************
 End of File
 */
