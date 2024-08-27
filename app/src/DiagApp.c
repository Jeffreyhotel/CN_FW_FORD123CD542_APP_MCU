#include "app/inc/DiagApp.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/INTBApp.h"
#include "app/inc/PowerApp.h"
#include "app/inc/DisplayChip.h"
#include "driver/inc/PortDriver.h"
#include "driver/inc/UartDriver.h"

static uint8_t u8DiagDispByte0 = 0x00U;
static uint8_t u8DiagDispByte1 = 0x01U;
static uint8_t u8TxBuffer[80] = {0};

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

uint8_t DiagApp_ConsecutiveCheckIO(DiagIO* ds1)
{
    DiagIO ds = *ds1;
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
    *ds1 = ds;
    return ds.Status;
}

uint8_t DiagApp_ConsecutiveCheckRegister(DiagIO* ds1,bool isgood)
{
    DiagIO ds = *ds1;
    if (true == isgood){
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
    *ds1 = ds;
    return ds.Status;
}

DiagIO FAULT_LED;
DiagIO FAULT_LCD;
DiagIO FAULT_BIAS;
DiagIO STATUS_LOCK;
DiagIO STATUS_RFPC;
DiagIO STATUS_LFPC;
void DiagApp_CheckFlowInitial()
{
    FAULT_LED.Status = IO_STATUS_SWIM;
    FAULT_LED.Port = LED_FAULT_PORT;
    FAULT_LED.PortNumber = LED_FAULT_PIN;
    FAULT_LED.Threshlod = 4;
    FAULT_LED.ConsecutiveHighCnt =  0;
    FAULT_LED.ConsecutiveLowCnt = 0;
    FAULT_LED.Report = true;

    FAULT_LCD.Status = IO_STATUS_SWIM;
    FAULT_LCD.Port = DISP_FAULT_PORT;
    FAULT_LCD.PortNumber = DISP_FAULT_PIN;
    FAULT_LCD.Threshlod = 4;
    FAULT_LCD.ConsecutiveHighCnt =  0;
    FAULT_LCD.ConsecutiveLowCnt = 0;
    FAULT_LCD.Report = true;

    FAULT_BIAS.Status = IO_STATUS_SWIM;
    FAULT_BIAS.Port = BIAS_FAULT_PORT;
    FAULT_BIAS.PortNumber = BIAS_FAULT_PIN;
    FAULT_BIAS.Threshlod = 5;
    FAULT_BIAS.ConsecutiveHighCnt =  0;
    FAULT_BIAS.ConsecutiveLowCnt = 0;
    FAULT_BIAS.Report = true;

    STATUS_RFPC.Status = IO_STATUS_SWIM;
    STATUS_RFPC.Port = FPCACHK_RIN_PORT;
    STATUS_RFPC.PortNumber = FPCACHK_RIN_PIN;
    STATUS_RFPC.Threshlod = 5;
    STATUS_RFPC.ConsecutiveHighCnt = 0;
    STATUS_RFPC.ConsecutiveLowCnt = 0;

    STATUS_LFPC.Status = IO_STATUS_SWIM;
    STATUS_LFPC.Port = FPCACHK_LIN_PORT;
    STATUS_LFPC.PortNumber = FPCACHK_LIN_PIN;
    STATUS_LFPC.Threshlod = 5;
    STATUS_LFPC.ConsecutiveHighCnt = 0;
    STATUS_LFPC.ConsecutiveLowCnt = 0;

    STATUS_LOCK.Status = IO_STATUS_SWIM;
    STATUS_LOCK.Port = DES_LOCK_PORT;
    STATUS_LOCK.PortNumber = DES_LOCK_PIN;
    STATUS_LOCK.Threshlod = 4;
    STATUS_LOCK.ConsecutiveHighCnt = 0;
    STATUS_LOCK.ConsecutiveLowCnt = 0;
}

void DiagApp_LcdFaultCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(&FAULT_LCD);
    if(IO_STATUS_HIGH == u8Status1){
        if(IO_HIGH == PortDrvier_PinRead(DISP_FAULT_PORT,DISP_FAULT_PIN))
        {
            DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_LCDERR_MASK);
        }else{/* Do Nothing*/}
        FAULT_LCD.Report = true;
    }else if(IO_STATUS_LOW == u8Status1){
        if(FAULT_LCD.Report == true)
        {
            DisplayChipApp_FaultCheck();
            FAULT_LCD.Report = false;
        }
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_LCDERR_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
        FAULT_LCD.Report = true;
    }
    sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LCD 0x%02x\r\n",u8Status1);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void DiagApp_LedFaultCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(&FAULT_LED);
    if(IO_STATUS_HIGH == u8Status1){
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_BLERR_MASK);
        FAULT_LED.Report = true;
    }else if(IO_STATUS_LOW == u8Status1){
        if(FAULT_LED.Report == true)
        {
            PowerApp_LP8664_FaultCheck();
            FAULT_LED.Report = false;
        }
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_BLERR_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
        FAULT_LED.Report = true;
    }
    sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LED 0x%02x\r\n",u8Status1);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void DiagApp_BiasFaultCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    uint8_t u8Status2 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(&FAULT_BIAS);
    if(IO_STATUS_HIGH == u8Status1){
        /* Recovery mechanism merge to LCD FAULT
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_LCDERR_MASK);
        */
       FAULT_BIAS.Report = true;
    }else if(IO_STATUS_LOW == u8Status1){
        /* Get error info & latch disp status bit*/
        if(FAULT_BIAS.Report == true)
        {
            PowerApp_RTQ6749_FaultCheck();
            FAULT_BIAS.Report = false;
        }
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_LCDERR_MASK);
    }else{
        FAULT_BIAS.Report = true;
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LED 0x%02x LCD 0x%02x\r\n",u8Status1,u8Status2);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void DiagApp_FpcCheckFlow(void)
{
    uint8_t u8StatusR = IO_STATUS_SWIM;
    uint8_t u8StatusL = IO_STATUS_SWIM;
    uint8_t u8Status1 = IO_STATUS_SWIM;
    u8StatusR = DiagApp_ConsecutiveCheckIO(&STATUS_RFPC);
    u8StatusL = DiagApp_ConsecutiveCheckIO(&STATUS_LFPC);
    u8Status1 = (u8StatusR | u8StatusL);
    if(IO_STATUS_SWIM == u8Status1){
        /* When voltage at swim state, Do nothing*/
    }else if(IO_STATUS_HIGH == (u8Status1 & IO_STATUS_HLMASK)){
        DiagApp_DispStatusSet(DISP_STATUS_BYTE0,DISP0_DCERR_MASK);
    }else if(IO_STATUS_LOW == (u8Status1 & IO_STATUS_HLMASK)){
        DiagApp_DispStatusClear(DISP_STATUS_BYTE0,DISP0_DCERR_MASK);
    }else{
        /* When voltage at swim state, Do nothing*/
    }
    sprintf((char *)u8TxBuffer,"FPC CHECK FLOW> STATUS_RFPC 0x%02x,0x%02x STATUS_RFPC 0x%02x,0x%02x\r\n",u8StatusR,STATUS_RFPC.ConsecutiveLowCnt,u8StatusL,STATUS_LFPC.ConsecutiveLowCnt);
    //UartDriver_TxWriteString(u8TxBuffer);
}

void DiagApp_LockCheckFlow(void)
{
    uint8_t u8Status1 = IO_STATUS_SWIM;
    u8Status1 = DiagApp_ConsecutiveCheckIO(&STATUS_LOCK);
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
