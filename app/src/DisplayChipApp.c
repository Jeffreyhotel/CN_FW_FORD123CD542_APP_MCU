/* ************************************************************************** */
/** Descriptive File Name

  @Company
    AUO

  @File Name
    DisplayChipApp.c

  @Summary
    Setup LCD Driver relevent function for main function to call.

  @Description
    -Setup a function for LCD Fault check.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "app/inc/DisplayChipApp.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/DiagApp.h"
#include "app/inc/TC0App.h"
#include "driver/inc/I2C4MDriver.h"
#include "driver/inc/UartDriver.h"

#define CHIP_ADDR   0x6FU
static uint8_t u8TxBuffer[80] = {0};

void DisplayChipApp_FaultCheck()
{
    uint8_t u8Status;
    uint8_t u8ASIL[4] = {0};
    uint8_t u8PageCmd[2] = {0x1EU,0x22U};
    uint8_t u8ReadRegister0x19[1] = {0x19U};
    uint8_t u8ReadRegister0x1A[1] = {0x1AU};
    uint8_t u8ReadRegister0x1B[1] = {0x1BU};
    uint8_t u8ReadRegister0x1C[1] = {0x1CU};
    u8Status = I2C4MDriver_Write(CHIP_ADDR,u8PageCmd,sizeof(u8PageCmd));
    if(u8Status == ERROR_NONE){
        u8Status = I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x19,sizeof(u8ReadRegister0x19),&u8ASIL[0],1U);
        u8Status |= I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x1A,sizeof(u8ReadRegister0x1A),&u8ASIL[1],1U);
        u8Status |= I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x1B,sizeof(u8ReadRegister0x1B),&u8ASIL[2],1U);
        u8Status |= I2C4MDriver_WriteRead(CHIP_ADDR,u8ReadRegister0x1C,sizeof(u8ReadRegister0x1C),&u8ASIL[3],1U);
        if(u8Status != ERROR_NONE){
            DiagApp_I2CMasterFaultCheck(true,DIAG_I2CM_LCD_MASK);
            sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LCD I2C ERROR=0x%02x [0x%02x,0x%02x,0x%02x,0x%02x]\r\n",u8Status,u8ASIL[0],u8ASIL[1],u8ASIL[2],u8ASIL[3]);
            UartDriver_TxWriteString(u8TxBuffer);
        }else{
            RegisterApp_DHU_Setup(CMD_DTC,DTC_LCD_FAULT_0x19,u8ASIL[0]);
            RegisterApp_DHU_Setup(CMD_DTC,DTC_LCD_FAULT_0x1A,u8ASIL[1]);
            RegisterApp_DHU_Setup(CMD_DTC,DTC_LCD_FAULT_0x1B,u8ASIL[2]);
            RegisterApp_DHU_Setup(CMD_DTC,DTC_LCD_FAULT_0x1C,u8ASIL[3]);
            sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> LCD [0x%02x,0x%02x,0x%02x,0x%02x]\r\n",u8ASIL[0],u8ASIL[1],u8ASIL[2],u8ASIL[3]);
            UartDriver_TxWriteString(u8TxBuffer);
        }
    }else{
      sprintf((char *)u8TxBuffer,"FAULT CHECK FLOW> I2C ERROR = %d\r\n",u8Status);
      UartDriver_TxWriteString(u8TxBuffer);
    }
}