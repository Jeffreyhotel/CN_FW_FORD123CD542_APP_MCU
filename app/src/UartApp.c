/* ************************************************************************** */

/** Descriptive File Name

  @Company
    AUO

  @File Name
    UartApp.c

  @Summary
    Setup Uart function for Debug Insight GUI usage.

  @Description
    -Design Uart Debug message.
    -Design Uart back door cmd usage for GUI.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "app/inc/UartApp.h"
#include "app/inc/StackTaskApp.h"
#include "app/inc/RegisterApp.h"
#include "driver/inc/I2C4MDriver.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/PortDriver.h"

#define UART_MARK_POS   7U
#define UART_CMD_ADDR_POS       (UART_MARK_POS+1U)
#define UART_CMD_W_DATA_POS     (UART_CMD_ADDR_POS+1U)
#define UART_CMD_R_LEN_POS      (UART_CMD_ADDR_POS+1U)
#define UART_CMD_WR_LEN_POS     (UART_CMD_ADDR_POS+1U)
#define UART_CMD_WR_DATA_POS    (UART_CMD_ADDR_POS+2U)
#define UART_CTRL_SET_POS       8U
#define UART_CTRL_PORT_POS      9U
#define UART_CTRL_PIN_POS       10U
#define UART_REG_CMD_POS        (UART_MARK_POS+1U)
#define UART_REG_R_LEN_POS      (UART_MARK_POS+2U)

bool UartApp_CompareBuffer(char *StringSource, uint8_t rdBuffer[], uint8_t start_pos, uint8_t stop_pos)
{
    bool bresult = false;
    uint8_t u8buffer[255] = {0};
    if(start_pos >= stop_pos)
    {
        for (uint8_t index = 0U;index<(stop_pos-start_pos+1U);index++)
        {
            u8buffer[index] = rdBuffer[index+start_pos];
        }
        if (strcmp(StringSource,(char *)u8buffer) != 0x01U){
            bresult = false;
        }else{
            bresult = true;
        }
    }else{
        bresult = false;
    }
    return bresult;
}

void UartApp_ReadFlow()
{
    uint8_t rdBuffer[255] = {0};
    uint8_t u8ParseTxBuffer[255] = {0};
    uint8_t u8ParseRxBuffer[255] = {0};
    uint8_t u8CmdLength = 0U;
    uint8_t result = UART_RX_EMPTY;
    uint8_t u8i2cstatus = ERROR_FAIL;
    uint8_t u8temp[1] = {0U};
    result = UartDriver_Receive(&rdBuffer[0],sizeof(rdBuffer));
    if(result == UART_SUCCESS)
    {
        if(rdBuffer[0] != 0x00U){
            if(rdBuffer[1]=='{' && rdBuffer[2]=='F' && rdBuffer[3]=='1' && rdBuffer[4]=='2' && rdBuffer[5]=='3' && rdBuffer[6]=='}')
            {
                switch (rdBuffer[UART_MARK_POS])
                {
                case 0x01U:
                    /* Read Register data code */
                    for(uint8_t index = 0U;index < rdBuffer[UART_REG_R_LEN_POS];index ++)
                    {
                        u8ParseRxBuffer[index] = RegisterApp_DHU_Read(rdBuffer[UART_REG_CMD_POS],index);
                    }
                    UartDriver_TxWriteString((uint8_t *)"\r\n[DEBUG]:");
                    /* Return Number# */
                    u8temp[0] = rdBuffer[UART_REG_R_LEN_POS];
                    UartDriver_TxWriteArray(u8temp,1U);
                    /* Return Value */
                    UartDriver_TxWriteArray(u8ParseRxBuffer,rdBuffer[UART_REG_R_LEN_POS]);
                    UartDriver_TxWriteString((uint8_t *)"\r\n");
                    break;

                case 0x02U:
                    /* Write Register data code */
                    u8CmdLength = rdBuffer[0] - UART_CMD_W_DATA_POS;
                    for(uint8_t index = 0U; index < u8CmdLength;index++)
                    {
                        RegisterApp_DHU_Setup(rdBuffer[UART_CMD_ADDR_POS],index+1,rdBuffer[index+UART_CMD_W_DATA_POS]);
                    }
                    uint8_t u8TxBuffer[30] = {0};
                    sprintf((char *)u8TxBuffer,"Register CMD 0x%02X Set\r\n",rdBuffer[UART_CMD_ADDR_POS]);
                    UartDriver_TxWriteString(u8TxBuffer);
                    break;

                case 0x03U:
                    I2C4MDriver_Initialize();
                    break;

                case 0x57U:
                    /* Write cmd code */
                    u8CmdLength = rdBuffer[0] - UART_CMD_W_DATA_POS;
                    for(uint8_t index = 0U; index < u8CmdLength;index++)
                    {
                        u8ParseTxBuffer[index] = rdBuffer[index+UART_CMD_W_DATA_POS];
                    }
                    u8i2cstatus = I2C4MDriver_Write(rdBuffer[UART_CMD_ADDR_POS],&u8ParseTxBuffer[0],u8CmdLength);
                    if(u8i2cstatus == CY_SCB_I2C_SUCCESS)
                    {

                    }else{
                        uint8_t u8TxBuffer[30] = {0};
                        sprintf((char *)u8TxBuffer,"I2C FAIL> 0x%02x\r\n",u8i2cstatus);
                        UartDriver_TxWriteString(u8TxBuffer);
                    }
                    break;

                case 0x52U:
                    /* Read cmd code */
                    u8i2cstatus = I2C4MDriver_Read(rdBuffer[UART_CMD_ADDR_POS],&u8ParseRxBuffer[0],rdBuffer[UART_CMD_R_LEN_POS]);
                    if(u8i2cstatus == CY_SCB_I2C_SUCCESS)
                    {
                        if(rdBuffer[UART_CMD_R_LEN_POS] > 0U)
                        {
                            u8temp[0] = rdBuffer[UART_CMD_R_LEN_POS];
                            UartDriver_TxWriteString((uint8_t *)"\r\n[DEBUG]:");
                            /* Return Number# */
                            UartDriver_TxWriteArray(u8temp,1U);
                            /* Return Value */
                            UartDriver_TxWriteArray(u8ParseRxBuffer,(uint32_t)rdBuffer[UART_CMD_R_LEN_POS]);
                            UartDriver_TxWriteString((uint8_t *)"\r\n");
                        }else{
                            /* No read need*/
                        }
                    }else{
                        uint8_t u8TxBuffer[30] = {0};
                        sprintf((char *)u8TxBuffer,"I2C FAIL> 0x%02x\r\n",u8i2cstatus);
                        UartDriver_TxWriteString(u8TxBuffer);
                    }
                    break;

                case 0xFEU:
                    /* Control GPIO*/
                    if(rdBuffer[UART_CTRL_PORT_POS] < 7U && rdBuffer[UART_CTRL_PIN_POS] < 8U)
                    {
                        if (rdBuffer[UART_CTRL_SET_POS] == 0x01)
                        {
                            PortDriver_PinSet(((GPIO_PRT_Type*) &GPIO->PRT[rdBuffer[UART_CTRL_PORT_POS]]),(uint32_t)rdBuffer[UART_CTRL_PIN_POS]);
                        }else if(rdBuffer[UART_CTRL_SET_POS] == 0x02){
                            PortDriver_PinClear(((GPIO_PRT_Type*) &GPIO->PRT[rdBuffer[UART_CTRL_PORT_POS]]),(uint32_t)rdBuffer[UART_CTRL_PIN_POS]);
                        }else if(rdBuffer[UART_CTRL_SET_POS] == 0x03){
                            PortDriver_PinToggle(((GPIO_PRT_Type*) &GPIO->PRT[rdBuffer[UART_CTRL_PORT_POS]]),(uint32_t)rdBuffer[UART_CTRL_PIN_POS]);
                        }else if(rdBuffer[UART_CTRL_SET_POS] == 0x04){
                            u8temp[0] = (uint8_t)PortDrvier_PinRead(((GPIO_PRT_Type*) &GPIO->PRT[rdBuffer[UART_CTRL_PORT_POS]]),(uint32_t)rdBuffer[UART_CTRL_PIN_POS]);
                            UartDriver_TxWriteString((uint8_t *)"\r\n[DEBUG]:");
                            /* Return Number# */
                            u8temp[0] = 1;
                            UartDriver_TxWriteArray(u8temp,1U);
                            /* Return Value */
                            u8temp[0] = (uint8_t)PortDrvier_PinRead(((GPIO_PRT_Type*) &GPIO->PRT[rdBuffer[UART_CTRL_PORT_POS]]),(uint32_t)rdBuffer[UART_CTRL_PIN_POS]);
                            UartDriver_TxWriteArray(u8temp,1U);
                            UartDriver_TxWriteString((uint8_t *)"\r\n");
                        }else{
                            /* Do nothing*/
                        }
                    }else{
                        /* Do nothing*/
                    }
                    break;

                case 0xFFU:
                    /* Write-Read code */
                    if(rdBuffer[0] > UART_CMD_WR_DATA_POS)
                    {
                        u8CmdLength = rdBuffer[0] - UART_CMD_WR_DATA_POS;
                        for(uint8_t index = 0U; index < u8CmdLength;index++)
                        {
                            u8ParseTxBuffer[index] = rdBuffer[index+UART_CMD_WR_DATA_POS];
                        }
                        u8i2cstatus = I2C4MDriver_WriteRead(rdBuffer[UART_CMD_ADDR_POS],&u8ParseTxBuffer[0],u8CmdLength,u8ParseRxBuffer,rdBuffer[UART_CMD_WR_LEN_POS]);
                        if(u8i2cstatus == CY_SCB_I2C_SUCCESS)
                        {
                            if(rdBuffer[UART_CMD_WR_LEN_POS] > 0U)
                            {
                                u8temp[0] = rdBuffer[UART_CMD_WR_LEN_POS];
                                UartDriver_TxWriteString((uint8_t *)"\r\n[DEBUG]:");
                                /* Return Number# */
                                UartDriver_TxWriteArray(u8temp,1U);
                                /* Return Value */
                                UartDriver_TxWriteArray(u8ParseRxBuffer,(uint32_t)rdBuffer[UART_CMD_WR_LEN_POS]);
                                UartDriver_TxWriteString((uint8_t *)"\r\n");
                            }else{
                                /* No read need*/
                                UartDriver_TxWriteString((uint8_t *)"Write Only\r\n");
                            }
                        }else{
                            uint8_t u8TxBuffer[30] = {0};
                            sprintf((char *)u8TxBuffer,"I2C FAIL> 0x%02x\r\n",u8i2cstatus);
                            UartDriver_TxWriteString(u8TxBuffer);
                        }
                    }else{
                        /* No read need*/
                    }
                    break;

                default:
                    UartDriver_TxWriteString((uint8_t *)"Wrong Uart Message!\r\n");
                    break;
                }
            }
        }
    }else{
        /* No data received*/
    }
    /* Clean all data buffer*/
    UartDriver_AbortReceive();
}
