#include "app/inc/PowerApp.h"
#include "driver/inc/PortDriver.h"
#include "driver/inc/UartDriver.h"

static uint8_t u8TxBuffer[60] = {0};

void PowerApp_Sequence(uint8_t u8Action)
{
    switch (u8Action)
    {
    case POWER_ON: //total ms
        /* code */
        break;

    case POWER_OFF: //total ms
        /* code */
        break;

    default:
		// ...
        break;
    }
}

DetectPG PG_P1V2;
DetectPG PG_P3V3;
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

static uint8_t PowerApp_ConsecutiveCheckIO(DetectPG ds)
{
    if (IO_HIGH == PortDrvier_PinRead(ds.Port,ds.PortNumber)){
        ds.ConsecutiveHighCnt += 1;
        ds.ConsecutiveLowCnt = 0;
    }else{
        ds.ConsecutiveHighCnt = 0;
        ds.ConsecutiveLowCnt += 1;
    }

    if (ds.ConsecutiveHighCnt >= ds.Threshlod){
        ds.ConsecutiveHighCnt = ds.Threshlod;
        ds.Status = IO_STATUS_HIGH;
    }else if(ds.ConsecutiveLowCnt >= ds.Threshlod){
        ds.ConsecutiveLowCnt = ds.Threshlod;
        ds.Status = IO_STATUS_LOW;
    }else{
        /* status no change*/
        ds.Status = IO_STATUS_SWIM;
    }
    return ds.Status;
}

void PowerApp_PowerGoodFlow()
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    uint8_t u8Status2 = IO_STATUS_SWIM;
    u8Status1 = PowerApp_ConsecutiveCheckIO(PG_P1V2);
    if(IO_STATUS_HIGH == u8Status1){

    }else if(IO_STATUS_LOW == u8Status1){

    }else{
        /* When voltage at swim state, Do nothing*/
    }
    u8Status2 = PowerApp_ConsecutiveCheckIO(PG_P3V3);
    if(IO_STATUS_HIGH == u8Status2){

    }else if(IO_STATUS_LOW == u8Status2){

    }else{
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"PG FLOW> P1V2 0x%02x > P3V3 0x%02x\r\n",u8Status1,u8Status2);
    //UartDriver_TxWriteString(u8TxBuffer);
}