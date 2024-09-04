/* ************************************************************************** */
/** Descriptive File Name

  @Company
    AUO

  @File Name
    I2CSlaveApp.c

  @Summary
    Design I2c Slave interrupt behavior to fit FORD CD542 FIDM Interface.

  @Description
    -Design the behavior to fit IFS-MMI2C-SR-REQ-XXXXX.
    -Transfer Task to Timer counter App (TC0App).
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "I2C2SlaveApp.h"
#include "I2C2SDriver.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/INTBApp.h"
#include "app/inc/TC0App.h"
#include "app/inc/StackTaskApp.h"
#include "app/inc/BacklightApp.h"

#define DHU_CMD_TOTAL_NUM    25U
#define DHU_WRITE_APPROVED_CMD_NUM    10U
#define DHU_CMD_UPDATE_NUM  12U
#define LENGTH_ZERO 0U
#define LENGTH_ONE  1U
#define ADDR_CMD_NUM    256U

uint8_t i2cReadBuffer [SL_RD_BUFFER_SIZE] = {0};
uint8_t i2cWriteBuffer[SL_WR_BUFFER_SIZE] = {0};
uint8_t TxCmdAddrPassPool[DHU_CMD_TOTAL_NUM] = {
                                CMD_DISP_STATUS,CMD_DISP_ID,CMD_BL_PWM,CMD_DISP_UD,CMD_DISP_EN,
                                CMD_DISP_SHUTD,CMD_ISR_STATUS,CMD_CORE_ASMB,CMD_DELIVER_ASMB,CMD_SW_FPN,
                                CMD_SN,CMD_MC_FPN,CMD_DTC,CMD_APP_REQ,CMD_BL_REQ,
                                CMD_ERASE_REQ,CMD_TRANSFER_REQ,CMD_CRC_REQ,CMD_UPDATESTATUS_REQ,CMD_APP_FB,
                                CMD_BL_FB,CMD_ERASE_FB,CMD_TRANSFER_FB,CMD_CRC_FB,CMD_UPDATESTATUS_FB
                                };
uint8_t TxCmdWritePassPool[DHU_WRITE_APPROVED_CMD_NUM] = {
                                CMD_BL_PWM,CMD_DISP_UD,CMD_DISP_EN,CMD_DISP_SHUTD,CMD_APP_REQ,
                                CMD_BL_REQ,CMD_ERASE_REQ,CMD_TRANSFER_REQ,CMD_CRC_REQ,CMD_UPDATESTATUS_REQ
                                };
uint8_t TxCmdUpdatePool[DHU_CMD_UPDATE_NUM] = {
                                CMD_APP_REQ,CMD_BL_REQ,CMD_ERASE_REQ,CMD_TRANSFER_REQ,CMD_CRC_REQ,
                                CMD_UPDATESTATUS_REQ,CMD_APP_FB,CMD_BL_FB,CMD_ERASE_FB,CMD_TRANSFER_FB,
                                CMD_CRC_FB,CMD_UPDATESTATUS_FB
                                };
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
    CmdSizePool[CMD_MC_FPN]         = 26U;
    CmdSizePool[CMD_DTC]            = 26U;

    CmdSizePool[CMD_APP_REQ]            = 4U;
    CmdSizePool[CMD_BL_REQ]             = 4U;
    CmdSizePool[CMD_ERASE_REQ]          = 4U;
    CmdSizePool[CMD_TRANSFER_REQ]       = 133U;
    CmdSizePool[CMD_CRC_REQ]            = 5U;
    CmdSizePool[CMD_UPDATESTATUS_REQ]   = 3U;
    CmdSizePool[CMD_APP_FB]             = 4U;
    CmdSizePool[CMD_BL_FB]              = 4U;
    CmdSizePool[CMD_ERASE_FB]           = 4U;
    CmdSizePool[CMD_TRANSFER_FB]        = 5U;
    CmdSizePool[CMD_CRC_FB]             = 4U;
    CmdSizePool[CMD_UPDATESTATUS_FB]    = 4U;
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

static bool I2CSlaveApp_SubaddressUpdateCmdCheck(uint8_t subaddr)
{
    bool bresult = false;
    for (uint32_t cnt = 0U; cnt<DHU_CMD_UPDATE_NUM; cnt++)
    {
        if (TxCmdUpdatePool[cnt] == subaddr)
        {
            bresult = true;
            break;
        }else{
            /* Do nothing*/
        }
    }
    return bresult;
}

void I2CSlaveApp_UpdateCmdChecksumSet(uint8_t subaddr)
{
    uint32_t u32ChecksumCounter = 0U;
    uint32_t u32SizeOfCmd = I2CSlaveApp_GetCmdSize(subaddr);
    if(u32SizeOfCmd > 2U && I2CSlaveApp_SubaddressUpdateCmdCheck(subaddr) == true)
    {
        for(uint32_t index = 0U;index<(u32SizeOfCmd-2U);index++)
        {
            u32ChecksumCounter += RegisterApp_DHU_Read(subaddr,index);
        }
        u32ChecksumCounter += 1U;
        RegisterApp_DHU_Setup(subaddr,u32SizeOfCmd-1U,u32ChecksumCounter);
    }else{
        /* Do nothing and ignored*/
    }
}

static void I2CSlaveApp_TxWriteTransferDone(uint8_t subaddr)
{
    bool isUpdateCmdWithCorrectChecksum = false;
    /* Check if Update Cmd Checksum or not*/
    if(I2CSlaveApp_SubaddressUpdateCmdCheck(subaddr) == true)
    {
        uint32_t u32ChecksumCounter = 0U;
        for(uint32_t index = 0U;index<(I2CSlaveApp_GetCmdSize(subaddr)-1U);index++)
        {
            u32ChecksumCounter += i2cWriteBuffer[index];
        }
        if((uint8_t)((u32ChecksumCounter+1U) & 0x000000FFU) == i2cWriteBuffer[I2CSlaveApp_GetCmdSize(subaddr)-1U])
        {
            isUpdateCmdWithCorrectChecksum = true;
        }else{
            /* Do nothing & Ignore Command*/
        }
        if (isUpdateCmdWithCorrectChecksum == true)
        {
            switch (subaddr)
            {
            case CMD_APP_REQ:
                RegisterApp_DHU_Setup(CMD_APP_FB,CMD_UPDATE_DATA_POS,CMD_FB_MCU_OK);
                I2CSlaveApp_UpdateCmdChecksumSet(CMD_APP_FB);
                RegisterApp_DHU_Setup(CMD_UPDATESTATUS_FB,CMD_UPDATE_DATA_POS,CMD_FB_UPDATE_PROGRESSING);
                I2CSlaveApp_UpdateCmdChecksumSet(CMD_UPDATESTATUS_FB);
                break;

            case CMD_BL_REQ:
                RegisterApp_DHU_Setup(CMD_BL_FB,CMD_UPDATE_DATA_POS,CMD_FB_MCU_OK);
                I2CSlaveApp_UpdateCmdChecksumSet(CMD_BL_FB);
                break;

            case CMD_ERASE_REQ:
                /* According to Update protocol, 0x03 : MCU */
                if(RegisterApp_DHU_Read(CMD_ERASE_REQ,CMD_UPDATE_DATA_POS) == CMD_REQ_FOR_MCU)
                {
                    TC0App_DHUTaskPush(TASK_UPDATE_ERASE);
                }else{
                    /* Do nothing*/
                    RegisterApp_DHU_Setup(CMD_ERASE_FB,CMD_UPDATE_DATA_POS,CMD_FB_FAIL);
                    I2CSlaveApp_UpdateCmdChecksumSet(CMD_ERASE_FB);
                }
                break;

            case CMD_TRANSFER_REQ:
                /* code */
                TC0App_DHUTaskPush(TASK_UPDATE_TRANS);
                break;

            case CMD_CRC_REQ:
                /* code */
                TC0App_DHUTaskPush(TASK_UPDATE_CRCSM);
                break;

            case CMD_UPDATESTATUS_REQ:
                break;

            default:
                break;
            }
        }else{
            /* Do nothing*/
        }
    }else{
        /* Do common cmd id task*/
        uint8_t u8temp = 0xFFU;
        switch (subaddr)
        {
        case CMD_DISP_STATUS:
            /* IFS-MMI2C-SR-REQ-140566/D-Reserved Bits*/
            u8temp = RegisterApp_DHU_Read(CMD_DISP_STATUS,CMD_DATA_POS+2U);
            RegisterApp_DHU_Setup(CMD_DISP_STATUS,CMD_DATA_POS+2U,u8temp & 0x00U);
            /* Do task*/
            break;

        case CMD_DISP_ID:
            break;

        case CMD_BL_PWM:
            /* IFS-MMI2C-SR-REQ-140566/D-Reserved Bits*/
            u8temp = RegisterApp_DHU_Read(CMD_BL_PWM,CMD_DATA_POS+1U);
            RegisterApp_DHU_Setup(CMD_BL_PWM,CMD_DATA_POS+1U,u8temp & 0x03U);
            /* Do task*/
            BacklightApp_UpdateDimmingStep();
            break;

        case CMD_DISP_UD:
            /* IFS-MMI2C-SR-REQ-140566/D-Reserved Bits*/
            u8temp = RegisterApp_DHU_Read(CMD_DISP_UD,CMD_DATA_POS);
            RegisterApp_DHU_Setup(CMD_DISP_UD,CMD_DATA_POS,u8temp & 0x03U);
            /* Do task*/
            break;

        case CMD_DISP_EN:
            /* IFS-MMI2C-SR-REQ-140566/D-Reserved Bits*/
            u8temp = RegisterApp_DHU_Read(CMD_DISP_EN,CMD_DATA_POS);
            RegisterApp_DHU_Setup(CMD_DISP_EN,CMD_DATA_POS,u8temp & 0x03U);
            /* Do task*/
            break;

        case CMD_DISP_SHUTD:
            /* IFS-MMI2C-SR-REQ-140566/D-Reserved Bits*/
            u8temp = RegisterApp_DHU_Read(CMD_DISP_SHUTD,CMD_DATA_POS);
            RegisterApp_DHU_Setup(CMD_DISP_SHUTD,CMD_DATA_POS,u8temp & 0x01U);
            /* Do task*/
            break;

        default:
            (void)u8temp;
            break;
        }
    }
}

static void I2CSlaveApp_TxReadTransferDone(uint8_t subaddr)
{
    /* Check the number of bytes read by the master(Tx) is the same of Cmd Length*/
    if (I2CSlaveApp_GetCmdSize(subaddr) == I2C2SDriver_GetTxReadTransferCount())
    {
        switch (subaddr)
        {
        case CMD_DISP_STATUS:
            /* Check the DISP_STATUS has been sent, then Clear INT_ERR*/
            RegisterApp_DHU_Setup(CMD_ISR_STATUS,CMD_DATA_POS,INTB_INT_ERR_CLEAR);
            break;
        
        case CMD_CRC_FB:
            if(RegisterApp_DHU_Read(CMD_CRC_FB,CMD_DATA_POS+1U) == CMD_FB_CHECKSUM_PASS)
            {
                TC0App_DHUTaskPush(TASK_UPDATE_RESET);
            }else{
                /* Do nothing*/
            }
            break;
        
        default:
            break;
        }
    }else{
        /* Command register read is not compeleted*/
        /* Ignore command*/
        /* Error shooting*/
    }
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
            /* Get the number of bytes written by the master(Tx) */
            length = I2C2SDriver_GetTxWriteTransferCount();
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
                            /* Do Cmd task*/
                            I2CSlaveApp_TxWriteTransferDone(u8SubAddr);
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
            uint8_t u8SubAddr = i2cReadBuffer[SUB_ADDR_POS];
            I2CSlaveApp_TxReadTransferDone(u8SubAddr);
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
    I2CSlaveApp_UpdateCmdChecksumSet(CMD_UPDATESTATUS_FB);
    return bresult;
}
