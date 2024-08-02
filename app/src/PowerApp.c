#include "app/inc/PowerApp.h"
#include "app/inc/TC0App.h"
#include "app/inc/DiagApp.h"
#include "driver/inc/PortDriver.h"
#include "driver/inc/UartDriver.h"

static uint8_t u8TxBuffer[60] = {0};

void PowerApp_Sequence(uint8_t u8Action)
{
    switch (u8Action)
    {
    case POWER_ON: //total ms
        /* code */
        PortDriver_PinSet(VBATT_EN_PORT,VBATT_EN_PIN);
        PortDriver_PinSet(P3V3_EN_PORT,P3V3_EN_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinSet(P1V2_EN_PORT,P1V2_EN_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinSet(DES_PDB_PORT,DES_PDB_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinSet(BIAS_EN_PORT,BIAS_EN_PIN);
        PortDriver_PinSet(DISP_RESX_PORT,DISP_RESX_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinSet(LED_EN_PORT,LED_EN_PIN);
        break;

    case POWER_OFF: //total ms
        /* code */
        PortDriver_PinClear(LED_EN_PORT,LED_EN_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinClear(DISP_RESX_PORT,DISP_RESX_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinClear(DES_PDB_PORT,DES_PDB_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinClear(P1V2_EN_PORT,P1V2_EN_PIN);
        PortDriver_PinClear(BIAS_EN_PORT,BIAS_EN_PIN);
        TC0App_DelayMS(2U);
        PortDriver_PinClear(VBATT_EN_PORT,VBATT_EN_PIN);
        PortDriver_PinClear(P3V3_EN_PORT,P3V3_EN_PIN);
        break;

    default:
		// ...
        break;
    }
}

DiagIO PG_P1V2;
DiagIO PG_P3V3;
void PowerApp_PowerGoodInitial()
{
    PG_P1V2.Status = IO_STATUS_SWIM;
    PG_P1V2.Port = P1V2_PG_PORT;
    PG_P1V2.PortNumber = P1V2_PG_PIN;
    PG_P1V2.Threshlod = 5;
    PG_P1V2.ConsecutiveHighCnt =  0;
    PG_P1V2.ConsecutiveLowCnt = 0;

    PG_P3V3.Status = IO_STATUS_SWIM;
    PG_P3V3.Port = P3V3_PG_PORT;
    PG_P3V3.PortNumber = P3V3_PG_PIN;
    PG_P3V3.Threshlod = 5;
    PG_P3V3.ConsecutiveHighCnt = 0;
    PG_P3V3.ConsecutiveLowCnt = 0;
}

void PowerApp_PowerGoodFlow()
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    uint8_t u8Status2 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(PG_P1V2);
    if(IO_STATUS_HIGH == u8Status1){

    }else if(IO_STATUS_LOW == u8Status1){

    }else{
        /* When voltage at swim state, Do nothing*/
    }
    u8Status2 = DiagApp_ConsecutiveCheckIO(PG_P3V3);
    if(IO_STATUS_HIGH == u8Status2){

    }else if(IO_STATUS_LOW == u8Status2){

    }else{
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"PG FLOW> P1V2 0x%02x > P3V3 0x%02x\r\n",u8Status1,u8Status2);
    //UartDriver_TxWriteString(u8TxBuffer);
}