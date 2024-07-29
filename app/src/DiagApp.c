#include "app/inc/DiagApp.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/INTBApp.h"
#include "driver/inc/PortDriver.h"

static uint8_t u8DiagDispByte0 = 0x00U;
static uint8_t u8DiagDispByte1 = 0x01U;
static uint8_t u8TxBuffer[60] = {0};

void DiagApp_DispStatusClear(uint8_t ByteNumber, uint8_t MaskValue)
{
    uint8_t u8OldByte0 = u8DiagDispByte0;
    uint8_t u8OldByte1 = u8DiagDispByte1;
    if(ByteNumber == 0x00U)
    {
        u8DiagDispByte0 &= ~MaskValue;
        RegisterApp_DHU_Setup(CMD_DISP_STATUS,CMD_DATA_POS,u8DiagDispByte0);
    }else if(ByteNumber == 0x01U)
    {
        u8DiagDispByte1 &= ~MaskValue;
        RegisterApp_DHU_Setup(CMD_DISP_STATUS,CMD_DATA_POS+1U,u8DiagDispByte1);
    }else{
        /*DO NOTHING*/
    }

    /* Check if the data is New event (Pull Request Necessary)*/
    if (((u8OldByte0 & DISP0_LATCHED_MASK) != (u8DiagDispByte0 & DISP0_LATCHED_MASK)) || 
        ((u8OldByte1 & DISP1_LATCHED_MASK) != (u8DiagDispByte1 & DISP1_LATCHED_MASK)))
    {
        INTBApp_PullReqSetOrClear(INTB_REQ_SET);
        RegisterApp_DHU_Setup(CMD_ISR_STATUS,CMD_DATA_POS,INTB_INT_ERR_SET);
    }
    (void)u8OldByte0;
    (void)u8OldByte1;
}

void DiagApp_DispStatusSet(uint8_t ByteNumber, uint8_t MaskValue)
{
    uint8_t u8OldByte0 = u8DiagDispByte0;
    uint8_t u8OldByte1 = u8DiagDispByte1;
    if(ByteNumber == 0x00U)
    {
        u8DiagDispByte0 |= MaskValue;
        RegisterApp_DHU_Setup(CMD_DISP_STATUS,CMD_DATA_POS,u8DiagDispByte0);
    }else if(ByteNumber == 0x01U)
    {
        u8DiagDispByte1 |= MaskValue;
        RegisterApp_DHU_Setup(CMD_DISP_STATUS,CMD_DATA_POS+1U,u8DiagDispByte1);
    }else{
        /*DO NOTHING*/
    }

    /* Check if the data is New event (Pull Request Necessary)*/
    if (((u8OldByte0 & DISP0_LATCHED_MASK) != (u8DiagDispByte0 & DISP0_LATCHED_MASK)) || 
        ((u8OldByte1 & DISP1_LATCHED_MASK) != (u8DiagDispByte1 & DISP1_LATCHED_MASK)))
    {
        INTBApp_PullReqSetOrClear(INTB_REQ_SET);
        RegisterApp_DHU_Setup(CMD_ISR_STATUS,CMD_DATA_POS,INTB_INT_ERR_SET);
    }
    (void)u8OldByte0;
    (void)u8OldByte1;
}

uint8_t DiagApp_ConsecutiveCheckIO(DiagIO ds)
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

DiagIO FAULT_LED;
DiagIO FAULT_LCD;
DiagIO STATUS_LOCK;
DiagIO STATUS_FPC;
void DiagApp_CheckFlowInitial()
{
    FAULT_LED.Status = IO_STATUS_SWIM;
    FAULT_LED.Port = LED_FAULT_PORT;
    FAULT_LED.PortNumber = LED_FAULT_PIN;
    FAULT_LED.Threshlod = 5;
    FAULT_LED.ConsecutiveHighCnt =  0;
    FAULT_LED.ConsecutiveLowCnt = 0;

    FAULT_LCD.Status = IO_STATUS_SWIM;
    FAULT_LCD.Port = LED_FAULT_PORT;
    FAULT_LCD.PortNumber = LED_FAULT_PIN;
    FAULT_LCD.Threshlod = 5;
    FAULT_LCD.ConsecutiveHighCnt =  0;
    FAULT_LCD.ConsecutiveLowCnt = 0;

    STATUS_FPC.Status = IO_STATUS_SWIM;
    STATUS_FPC.Port = FPCACHK_OUT_PORT;
    STATUS_FPC.PortNumber = FPCACHK_OUT_PIN;
    STATUS_FPC.Threshlod = 5;
    STATUS_FPC.ConsecutiveHighCnt = 0;
    STATUS_FPC.ConsecutiveLowCnt = 0;

    STATUS_LOCK.Status = IO_STATUS_SWIM;
    STATUS_LOCK.Port = DES_LOCK_PORT;
    STATUS_LOCK.PortNumber = DES_LOCK_PIN;
    STATUS_LOCK.Threshlod = 5;
    STATUS_LOCK.ConsecutiveHighCnt = 0;
    STATUS_LOCK.ConsecutiveLowCnt = 0;
}

void DiagApp_FaultCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    uint8_t u8Status2 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(FAULT_LED);
    if(IO_STATUS_HIGH == u8Status1){
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_BLERR_MASK);
    }else if(IO_STATUS_LOW == u8Status1){
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_BLERR_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
    }

    u8Status2 = DiagApp_ConsecutiveCheckIO(FAULT_LCD);
    if(IO_STATUS_HIGH == u8Status2){
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_LCDERR_MASK);
    }else if(IO_STATUS_LOW == u8Status2){
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_LCDERR_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LED 0x%02x LCD 0x%02x\r\n",u8Status1,u8Status2);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void DiagApp_FpcCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(STATUS_FPC);
    if(IO_STATUS_HIGH == u8Status1){
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_DCERR_MASK);
    }else if(IO_STATUS_LOW == u8Status1){
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_DCERR_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"FPC CHECK FLOW> STATUS_FPC 0x%02x\r\n",u8Status1);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void DiagApp_LockCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(STATUS_LOCK);
    if(IO_STATUS_HIGH == u8Status1){
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_LLOSS_MASK);
    }else if(IO_STATUS_LOW == u8Status1){
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_LLOSS_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"LOCK CHECK FLOW> STATUS_LOCK 0x%02x\r\n",u8Status1);
    //UartDriver_TxWriteString(u8TxBuffer);
}