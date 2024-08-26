#include "app/inc/PowerApp.h"
#include "app/inc/TC0App.h"
#include "app/inc/DiagApp.h"
#include "app/inc/RegisterApp.h"
#include "driver/inc/PortDriver.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/I2C4MDriver.h"

#define BIAS_ADDR   0x6BU
#define LED_ADDR    0x3AU

static uint8_t u8TxBuffer[60] = {0};

void PowerApp_Sequence(uint8_t u8Action)
{
    switch (u8Action)
    {
    case POWER_ON: //total ms
        /* code */
        PortDriver_PinSet(VBATT_EN_PORT,VBATT_EN_PIN);
        TC0App_DelayMS(10U);
        PortDriver_PinSet(P3V3_EN_PORT,P3V3_EN_PIN);
        TC0App_DelayMS(10U);
        PortDriver_PinSet(P1V2_EN_PORT,P1V2_EN_PIN);
        TC0App_DelayMS(10U);
        PortDriver_PinSet(DES_PDB_PORT,DES_PDB_PIN);
        TC0App_DelayMS(10U);
        PortDriver_PinSet(DES_INTB_PORT,DES_INTB_PIN);
        break;

    case POWER_OFF: //total ms
        /* code */
        TC0App_DelayMS(10U);
        PortDriver_PinClear(DES_PDB_PORT,DES_PDB_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinClear(P3V3_EN_PORT,P3V3_EN_PIN);
        PortDriver_PinClear(P1V2_EN_PORT,P1V2_EN_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinClear(VBATT_EN_PORT,VBATT_EN_PIN);
        
        break;

    case LCD_ON:
        PortDriver_PinSet(DISP_RESX_PORT,DISP_RESX_PIN);
        TC0App_DelayMS(10U);
        PortDriver_PinSet(BIAS_EN_PORT,BIAS_EN_PIN);
        TC0App_DelayMS(10U);
        PortDriver_PinSet(DISP_STBY_PORT,DISP_STBY_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinSet(LED_EN_PORT,LED_EN_PIN);
        break;

    case LCD_OFF:
        PortDriver_PinClear(LED_EN_PORT,LED_EN_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinClear(DISP_STBY_PORT,DISP_STBY_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinClear(BIAS_EN_PORT,BIAS_EN_PIN);
        TC0App_DelayMS(5U);
        PortDriver_PinClear(DISP_RESX_PORT,DISP_RESX_PIN);
        break;

    default:
		// ...
        break;
    }
}

DiagIO PG_P1V2;
DiagIO PG_P3V3;
DiagIO FAULT_RTQ6749;
DiagIO FAULT_LP8664;
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

    FAULT_RTQ6749.Status = IO_STATUS_SWIM;
    FAULT_RTQ6749.Threshlod = 3;
    FAULT_RTQ6749.ConsecutiveHighCnt = 0;
    FAULT_RTQ6749.ConsecutiveLowCnt = 0;

    FAULT_LP8664.Status = IO_STATUS_SWIM;
    FAULT_LP8664.Threshlod = 3;
    FAULT_LP8664.ConsecutiveHighCnt = 0;
    FAULT_LP8664.ConsecutiveLowCnt = 0;
}

void PowerApp_PowerGoodFlow()
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    uint8_t u8Status2 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(&PG_P1V2);
    if(IO_STATUS_HIGH == u8Status1){

    }else if(IO_STATUS_LOW == u8Status1){
        /* GO TO SHUTDOWN*/
        RegisterApp_DHU_Setup(CMD_DISP_SHUTD,CMD_DATA_POS,0x01);
    }else{
        /* When voltage at swim state, Do nothing*/
        sprintf((char *)u8TxBuffer,"P1V2 SWIM >> 0x%02x, %d, %d\r\n",u8Status1,PG_P1V2.ConsecutiveHighCnt,PG_P1V2.ConsecutiveLowCnt);
        UartDriver_TxWriteString(u8TxBuffer);
    }
    u8Status2 = DiagApp_ConsecutiveCheckIO(&PG_P3V3);
    if(IO_STATUS_HIGH == u8Status2){

    }else if(IO_STATUS_LOW == u8Status2){
        /* GO TO SHUTDOWN*/
        RegisterApp_DHU_Setup(CMD_DISP_SHUTD,CMD_DATA_POS,0x01);
    }else{
        /* When voltage at swim state, Do nothing*/
        sprintf((char *)u8TxBuffer,"P3V3 SWIM >> 0x%02x, %d, %d\r\n",u8Status2,PG_P3V3.ConsecutiveHighCnt,PG_P3V3.ConsecutiveLowCnt);
        UartDriver_TxWriteString(u8TxBuffer);
    }
    sprintf((char *)u8TxBuffer,"PG FLOW> P1V2 0x%02x > P3V3 0x%02x\r\n",u8Status1,u8Status2);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void PowerApp_RTQ6749_FaultCheck()
{
    uint8_t CMD_ControlMultiRead[2] = {0xFFU,0x00};
    uint8_t CMD_DataAddr[1] = {0x00};
    uint8_t RxBuffer[31] = {0U};
    uint8_t u8fault = 0U;
    uint8_t Status = ERROR_NONE;
    uint8_t u8Status = IO_STATUS_SWIM;
    Status = I2C4MDriver_Write(BIAS_ADDR,CMD_ControlMultiRead,2U);
    Status |= I2C4MDriver_WriteRead(BIAS_ADDR,CMD_DataAddr,1U,RxBuffer,30U);
    if(Status != ERROR_NONE)
    {
        sprintf((char *)u8TxBuffer,"I2C M driver transmit fail >> 0x%02x\r\n",Status);
        UartDriver_TxWriteString(u8TxBuffer);
        u8fault = 0xFFU;
    }else{
        u8fault = RxBuffer[0x1DU];
        sprintf((char *)u8TxBuffer,"RTQ6749 Fault Analysis >> 0x%02x\r\n",u8fault);
        UartDriver_TxWriteString(u8TxBuffer);
    }

    if(u8fault == 0x00U)
    {
        u8Status = DiagApp_ConsecutiveCheckRegister(&FAULT_RTQ6749, true);
    }else{
        u8Status = DiagApp_ConsecutiveCheckRegister(&FAULT_RTQ6749, false);
    }

    if(IO_STATUS_HIGH == u8Status){
        UartDriver_TxWriteString((uint8_t *)"RTQ6749 is Good!\r\n");
    }else if(IO_STATUS_LOW == u8Status){
        UartDriver_TxWriteString((uint8_t *)"RTQ6749 fault happen!\r\n");
    }else{
        /* When voltage at swim state, Do nothing*/
        sprintf((char *)u8TxBuffer,"RTQ6749 SWIM >> 0x%02x, %d, %d\r\n",u8Status,FAULT_RTQ6749.ConsecutiveHighCnt,FAULT_RTQ6749.ConsecutiveLowCnt);
        UartDriver_TxWriteString(u8TxBuffer);
    }
}

void PowerApp_LP8664_FaultCheck()
{
    uint8_t CMD_DataAddr[1] = {0x00};
    uint8_t RxBuffer[31] = {0U};
    uint8_t u8fault[4] = {0U};
    uint8_t Status = ERROR_NONE;
    uint8_t u8Status = IO_STATUS_SWIM;
    Status = I2C4MDriver_WriteRead(LED_ADDR,CMD_DataAddr,1U,RxBuffer,30U);
    if(Status != ERROR_NONE)
    {
        sprintf((char *)u8TxBuffer,"I2C M driver transmit fail >> 0x%02x\r\n",Status);
        UartDriver_TxWriteString(u8TxBuffer);
        u8fault[0] = 0xFFU;
    }else{
        u8fault[1] = RxBuffer[0x0EU];
        u8fault[2] = RxBuffer[0x0FU];
        u8fault[3] = RxBuffer[0x10U];
        u8fault[4] = RxBuffer[0x11U];
        u8fault[5] = RxBuffer[0x12U];
        u8fault[6] = RxBuffer[0x13U];
        u8fault[0] = u8fault[1]|u8fault[2]|u8fault[3]|u8fault[4]|u8fault[5]|u8fault[6];
        sprintf((char *)u8TxBuffer,"LP8664 Fault Analysis >> 0x%02x\r\n",u8fault[0]);
        UartDriver_TxWriteString(u8TxBuffer);
    }

    if(u8fault[0] == 0x00U)
    {
        u8Status = DiagApp_ConsecutiveCheckRegister(&FAULT_LP8664, true);
    }else{
        u8Status = DiagApp_ConsecutiveCheckRegister(&FAULT_LP8664, false);
    }

    if(IO_STATUS_HIGH == u8Status){
        UartDriver_TxWriteString((uint8_t *)"LP8664 is Good!\r\n");
    }else if(IO_STATUS_LOW == u8Status){
        UartDriver_TxWriteString((uint8_t *)"LP8664 fault happen!\r\n");
    }else{
        /* When voltage at swim state, Do nothing*/
        sprintf((char *)u8TxBuffer,"LP8664 SWIM >> 0x%02x, %d, %d\r\n",u8Status,FAULT_LP8664.ConsecutiveHighCnt,FAULT_LP8664.ConsecutiveLowCnt);
        UartDriver_TxWriteString(u8TxBuffer);
    }
}