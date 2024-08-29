#include "app/inc/DisplayChipApp.h"
#include "driver/inc/I2C4MDriver.h"
#include "driver/inc/UartDriver.h"

#define CHIP_ADDR   0x6FU
static uint8_t u8TxBuffer[80] = {0};

void DisplayChipApp_FaultCheck()
{
    uint8_t u8Status;
    uint8_t u8ASIL[4] = {0};
    uint8_t u8PageCmd[3] = {0x00U,0x1EU,0x22U};
    uint8_t u8ReadRegister0x19[2] = {0x01U,0x19U};
    uint8_t u8ReadRegister0x1A[2] = {0x01U,0x1AU};
    uint8_t u8ReadRegister0x1B[2] = {0x01U,0x1BU};
    uint8_t u8ReadRegister0x1C[2] = {0x01U,0x1CU};
    u8Status = I2C4MDriver_Write(CHIP_ADDR,u8PageCmd,sizeof(u8PageCmd));
    if(u8Status == ERROR_NONE){
        u8Status = I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x19,sizeof(u8ReadRegister0x19),&u8ASIL[0],1U);
        u8Status |= I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x1A,sizeof(u8ReadRegister0x1A),&u8ASIL[1],1U);
        u8Status |= I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x1B,sizeof(u8ReadRegister0x1B),&u8ASIL[2],1U);
        u8Status |= I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x1C,sizeof(u8ReadRegister0x1C),&u8ASIL[3],1U);
        if(u8Status != ERROR_NONE){
            sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LCD I2C ERROR=0x%02x [0x%02x,0x%02x,0x%02x,0x%02x]\r\n",u8Status,u8ASIL[0],u8ASIL[1],u8ASIL[2],u8ASIL[3]);
            UartDriver_TxWriteString(u8TxBuffer);
        }else{
            sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LCD [0x%02x,0x%02x,0x%02x,0x%02x]\r\n",u8ASIL[0],u8ASIL[1],u8ASIL[2],u8ASIL[3]);
            UartDriver_TxWriteString(u8TxBuffer);
        }
    }
}