#include "I2C2SlaveApp.h"
#include "I2C2SDriver.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/INTBApp.h"

#define DHU_CMD_TOTAL_NUM    19U
#define DHU_WRITE_APPROVED_CMD_NUM    10U
#define LENGTH_ZERO 0U
#define LENGTH_ONE  1U
#define ADDR_CMD_NUM    256U

uint8_t i2cReadBuffer [SL_RD_BUFFER_SIZE] = {0};
uint8_t i2cWriteBuffer[SL_WR_BUFFER_SIZE] = {0};
uint8_t TxCmdAddrPassPool[DHU_CMD_TOTAL_NUM] = {
                                CMD_DISP_STATUS,CMD_DISP_ID,CMD_BL_PWM,CMD_DISP_UD,CMD_DISP_EN,
                                CMD_DISP_SHUTD,CMD_ISR_STATUS,CMD_CORE_ASMB,CMD_DELIVER_ASMB,CMD_SW_FPN,
                                CMD_SN,CMD_MC_FPN,CMD_DTC,CMD_AB_SWITCH,CMD_ERASE,
                                CMD_TRANSFER,CMD_CRC,CMD_RESET,CMD_STATUS_CHECK};
uint8_t TxCmdWritePassPool[DHU_WRITE_APPROVED_CMD_NUM] = {
                                CMD_BL_PWM,CMD_DISP_UD,CMD_DISP_EN,CMD_DISP_SHUTD,CMD_AB_SWITCH,
                                CMD_ERASE,CMD_TRANSFER,CMD_CRC,CMD_RESET,CMD_STATUS_CHECK};
uint32_t CmdSizePool[ADDR_CMD_NUM] = {0};

static void I2CSlaveApp_CmdSizeInitial(void)
{
    CmdSizePool[CMD_DISP_STATUS]    = 4U;
    CmdSizePool[CMD_DISP_ID]        = 3U;
    CmdSizePool[CMD_BL_PWM]         = 3U;
    CmdSizePool[CMD_DISP_UD]        = 2U;
    CmdSizePool[CMD_DISP_EN]        = 2U;
    CmdSizePool[CMD_DISP_SHUTD]     = 2U;
    CmdSizePool[CMD_ISR_STATUS]     = 2U;
    CmdSizePool[CMD_CORE_ASMB]      = 26U;
    CmdSizePool[CMD_DELIVER_ASMB]   = 26U;
    CmdSizePool[CMD_SW_FPN]         = 26U;
    CmdSizePool[CMD_SN]             = 26U;
    CmdSizePool[CMD_DTC]            = 4U;
}

static uint32_t I2CSlaveApp_GetCmdSize(uint8_t subaddr)
{
    return CmdSizePool[subaddr];
}

static bool I2CSlaveApp_SubAddrPassCheck(uint8_t subaddr)
{
    bool bresult = false;
    for (uint32_t cnt = 0U; cnt<DHU_CMD_TOTAL_NUM; cnt++)
    {
        if (TxCmdAddrPassPool[cnt] == subaddr)
        {
            bresult = true;
            break;
        }else{
            /* Do nothing*/
        }
    }
    return bresult;
}

static bool I2CSlaveApp_SubAddrWritePassCheck(uint8_t subaddr)
{
    bool bresult = false;
    for (uint32_t cnt = 0U; cnt<DHU_WRITE_APPROVED_CMD_NUM; cnt++)
    {
        if (TxCmdWritePassPool[cnt] == subaddr)
        {
            bresult = true;
            break;
        }else{
            /* Do nothing*/
        }
    }
    return bresult;
}

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
            /* Check command with subaddr*/
            if(length > LENGTH_ZERO)
            {
                uint8_t u8SubAddr = i2cWriteBuffer[SUB_ADDR_POS];
                /* Check command sub addr is correct or not*/
                if (I2CSlaveApp_SubAddrPassCheck(u8SubAddr) == false)
                {
                    /* Clean Buffer and Return Echo (IFS-MMI2C-SR-REQ-140565)*/
                    memset(i2cReadBuffer,0xFFU,SL_RD_BUFFER_SIZE);
                    i2cReadBuffer[SUB_ADDR_POS] = u8SubAddr;
                }else{
                    /* Check the command is Write Available (IFS-MMI2C-SR-REQ-197857)*/
                    if (I2CSlaveApp_SubAddrWritePassCheck(u8SubAddr) == true)
                    {
                        /* Check the write length is overflow/underflow or not (IFS-MMI2C-SR-REQ-140570/IFS-MMI2C-SR-REQ-140569)*/
                        if(length == I2CSlaveApp_GetCmdSize(u8SubAddr))
                        {
                            /* Update DHU Command if Write available */
                            for(index = 0U;index<I2CSlaveApp_GetCmdSize(u8SubAddr);index++)
                            {
                                RegisterApp_DHU_Setup(u8SubAddr,index,i2cWriteBuffer[index]);
                            }
                        }else{
                            /* Ignore data write if command length is wrong*/
                        }
                    }else{
                        /* Do nothing if command belong to read only*/
                    }
                    /* DHU command data update to Rx buffer (IFS-MMI2C-SR-REQ-197875)*/
                    uint32_t CmdSize = I2CSlaveApp_GetCmdSize(u8SubAddr);
                    CmdSize = (CmdSize > SL_RD_BUFFER_SIZE) ? SL_RD_BUFFER_SIZE : CmdSize;
                    memset(i2cReadBuffer,0xFFU,SL_RD_BUFFER_SIZE);
                    for(index = 0U;index<CmdSize;index++)
                    {
                        i2cReadBuffer[index] = RegisterApp_DHU_Read(u8SubAddr,index);
                    }
                }
            }else{
                /* Clean Buffer Return Default High (0xFF)*/
                memset(i2cReadBuffer,0xFFU,SL_RD_BUFFER_SIZE);
            }
            /* Clean Tx Buffer after finish event*/
            memset(i2cWriteBuffer,0xFFU,SL_WR_BUFFER_SIZE);
            /* Configure write & read buffer */
            I2C2SDriver_ConfigRxBuff(i2cReadBuffer);
            I2C2SDriver_ConfigTxBuff(i2cWriteBuffer);
        break;

        /* Transmit data complete */
        case CY_SCB_I2C_SLAVE_RD_CMPLT_EVENT:
            /* Check the DISP_STATUS has been sent & Clear INT_ERR*/
            if(i2cReadBuffer[SUB_ADDR_POS] == CMD_DISP_STATUS)
            {
                RegisterApp_DHU_Setup(CMD_ISR_STATUS,CMD_DATA_POS,INTB_INT_ERR_CLEAR);
            }else{
                /* Do nothing*/
            }
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
    I2CSlaveApp_CmdSizeInitial();
    return bresult;
}