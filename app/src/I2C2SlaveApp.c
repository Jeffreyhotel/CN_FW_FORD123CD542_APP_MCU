#include "I2C2SlaveApp.h"
#include "I2C2SDriver.h"
#include "app/inc/RegisterApp.h"

uint8_t i2cReadBuffer [SL_RD_BUFFER_SIZE] = {0};
uint8_t i2cWriteBuffer[SL_WR_BUFFER_SIZE] = {0};

uint8_t flag_i2c2s = 1U;
static void SlaveCallback(uint32_t event)
{
    switch (event)
    {
        case CY_SCB_I2C_SLAVE_READ_EVENT:
            /* Nothing */
            flag_i2c2s = 0U;
        break;

        case CY_SCB_I2C_SLAVE_WRITE_EVENT:
            /* Nothing */
            flag_i2c2s = 0U;
        break;

        case CY_SCB_I2C_SLAVE_RD_IN_FIFO_EVENT:
            /* Nothing */
            flag_i2c2s = 0U;
        break;

        case CY_SCB_I2C_SLAVE_RD_BUF_EMPTY_EVENT:
            /* Nothing */
            flag_i2c2s = 0U;
        break;

        case CY_SCB_I2C_SLAVE_ERR_EVENT:
            /* Nothing */
            flag_i2c2s = 0U;
        break;

        /* Receive data complete */
        case CY_SCB_I2C_SLAVE_WR_CMPLT_EVENT:
            uint32_t index = 0U;
            uint32_t length = 0U;
            length = I2C2SDriver_GetTxCount();
            if(length > 1)
            {
                /* Need to check sub addr is correct*/
                for(index = 0U;index<(length);index++)
                {
                    RegisterApp_DHU_Setup(i2cWriteBuffer[SUB_ADDR_POS],index,i2cWriteBuffer[index]);
                }
                memset(i2cReadBuffer,0xFFU,SL_RD_BUFFER_SIZE);
                /* Need to check the command id*/
                for(index = 0U;index<SL_RD_BUFFER_SIZE;index++)
                {
                    i2cReadBuffer[index] = RegisterApp_DHU_Read(i2cWriteBuffer[SUB_ADDR_POS],index);
                }
            }
            i2cReadBuffer[SUB_ADDR_POS] = i2cWriteBuffer[SUB_ADDR_POS];
            memset(i2cWriteBuffer,0xFFU,SL_WR_BUFFER_SIZE);
            /* Configure write & read buffer */
            I2C2SDriver_ConfigRxBuff(i2cReadBuffer);
            I2C2SDriver_ConfigTxBuff(i2cWriteBuffer);
        break;

        /* Transmit data complete */
        case CY_SCB_I2C_SLAVE_RD_CMPLT_EVENT:
            flag_i2c2s = 0U;
        break;

        case CY_SCB_I2C_MASTER_WR_IN_FIFO_EVENT:
            flag_i2c2s = 0U;
        break;

        default:
        break;
    }
}

bool I2C2SlaveApp_Initial(void)
{
    bool bresult = true;
    bresult = I2C2SDriver_Initial();
    if (bresult == true)
    {
        I2C2SDriver_ConfigRxBuff(i2cReadBuffer);
        I2C2SDriver_ConfigTxBuff(i2cWriteBuffer);
        I2C2SDriver_RegisterCallback(SlaveCallback);
        I2C2SDriver_Enable();
    }else{
        /* Do nothing*/
    }

    return bresult;
}