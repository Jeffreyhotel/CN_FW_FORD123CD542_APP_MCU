/* ************************************************************************** */

/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "app/inc/RegisterApp.h"

Register RegisterContainer;

#define UpdateLenPos    0x01U

#if 0
void RegisterApp_DHU_CRCSetup(uint8_t Page, uint16_t Length)
{
    uint8_t CRC = RegisterApp_DHU_Read(Page,OFFSET_CMDID);
    for(uint16_t count = 1U; count < (Length-1U); count++)
    {
        CRC = CRC ^ RegisterApp_DHU_Read(Page,count);
    }

    /*SWUV Static Test Need Double Check*/
    RegisterApp_DHU_Setup(Page,(Length-1U),CRC);
	(void)CRC;
}
#endif

void RegisterApp_ALL_Initial(void)
{
    RegisterApp_Initial(&RegisterContainer);
}

/*  Function: RegisterApp_Initial
**  Callfrom: MainApp.c 
**        Do: Clean Register Container Value
**        Go: No Return
 */
void RegisterApp_Initial(Register* pRegisterContainer)
{
    uint16_t counter = 0x0000U;
    uint8_t address = 0U;
    for(counter =0x0000U;counter<RegisterMaxSize;counter++){
        address = (uint8_t) counter;
        if(address == SUB_ADDR_POS)
        {
            pRegisterContainer->DHU_0X00_DISP_STATUS[address]       = CMD_DISP_STATUS;
            pRegisterContainer->DHU_0X01_DISP_ID[address]           = CMD_DISP_ID;
            pRegisterContainer->DHU_0X02_BL_PWM[address]            = CMD_BL_PWM;
            pRegisterContainer->DHU_0X03_DISP_UD[address]           = CMD_DISP_UD;
            pRegisterContainer->DHU_0X04_DISP_EN[address]           = CMD_DISP_EN;
            pRegisterContainer->DHU_0X05_DISP_SHUTD[address]        = CMD_DISP_SHUTD;
            pRegisterContainer->DHU_0X30_ISR_STATUS[address]        = CMD_ISR_STATUS;
            pRegisterContainer->DHU_0X31_CORE_ASMB[address]         = CMD_CORE_ASMB;
            pRegisterContainer->DHU_0X32_DELIVER_ASMB[address]      = CMD_DELIVER_ASMB;
            pRegisterContainer->DHU_0X33_SW_FPN[address]            = CMD_SW_FPN;
            pRegisterContainer->DHU_0X34_SN[address]                = CMD_SN;
            pRegisterContainer->DHU_0X35_MC_FPN[address]            = CMD_MC_FPN;
            pRegisterContainer->DHU_0XA3_DTC[address]               = CMD_DTC;

            pRegisterContainer->DHU_0XE4_APP_REQ[address]           = CMD_APP_REQ;
            pRegisterContainer->DHU_0XE5_BL_REQ[address]            = CMD_BL_REQ;
            pRegisterContainer->DHU_0XE6_ERASE_REQ[address]         = CMD_ERASE_REQ;
            pRegisterContainer->DHU_0XE7_TRANSFER_REQ[address]      = CMD_TRANSFER_REQ;
            pRegisterContainer->DHU_0XE8_CRC_REQ[address]           = CMD_CRC_REQ;
            pRegisterContainer->DHU_0XE9_UPDATESTATUS_REQ[address]  = CMD_UPDATESTATUS_REQ;
            pRegisterContainer->DHU_0XF4_APP_FB[address]            = CMD_APP_FB;
            pRegisterContainer->DHU_0XF5_BL_FB[address]             = CMD_BL_FB;
            pRegisterContainer->DHU_0XF6_ERASE_FB[address]          = CMD_ERASE_FB;
            pRegisterContainer->DHU_0XF7_TRANSFER_FB[address]       = CMD_TRANSFER_FB;
            pRegisterContainer->DHU_0XF8_CRC_FB[address]            = CMD_CRC_FB;
            pRegisterContainer->DHU_0XF9_UPDATESTATUS_FB[address]   = CMD_UPDATESTATUS_FB;
        }else{
            pRegisterContainer->DHU_0X00_DISP_STATUS[address]       = 0x00U;
            pRegisterContainer->DHU_0X01_DISP_ID[address]           = 0x00U;
            pRegisterContainer->DHU_0X02_BL_PWM[address]            = 0x00U;
            pRegisterContainer->DHU_0X03_DISP_UD[address]           = 0x00U;
            pRegisterContainer->DHU_0X04_DISP_EN[address]           = 0x00U;
            pRegisterContainer->DHU_0X05_DISP_SHUTD[address]        = 0x00U;
            pRegisterContainer->DHU_0X30_ISR_STATUS[address]        = 0x00U;
            pRegisterContainer->DHU_0X31_CORE_ASMB[address]         = 0x00U;
            pRegisterContainer->DHU_0X32_DELIVER_ASMB[address]      = 0x00U;
            pRegisterContainer->DHU_0X33_SW_FPN[address]            = 0x00U;
            pRegisterContainer->DHU_0X34_SN[address]                = 0x00U;
            pRegisterContainer->DHU_0X35_MC_FPN[address]            = 0x00U;
            pRegisterContainer->DHU_0XA3_DTC[address]               = 0x00U;

            pRegisterContainer->DHU_0XE4_APP_REQ[address]           = 0x00U;
            pRegisterContainer->DHU_0XE5_BL_REQ[address]            = 0x00U;
            pRegisterContainer->DHU_0XE6_ERASE_REQ[address]         = 0x00U;
            pRegisterContainer->DHU_0XE7_TRANSFER_REQ[address]      = 0x00U;
            pRegisterContainer->DHU_0XE8_CRC_REQ[address]           = 0x00U;
            pRegisterContainer->DHU_0XE9_UPDATESTATUS_REQ[address]  = 0x00U;
            pRegisterContainer->DHU_0XF4_APP_FB[address]            = 0x00U;
            pRegisterContainer->DHU_0XF5_BL_FB[address]             = 0x00U;
            pRegisterContainer->DHU_0XF6_ERASE_FB[address]          = 0x00U;
            pRegisterContainer->DHU_0XF7_TRANSFER_FB[address]       = 0x00U;
            pRegisterContainer->DHU_0XF8_CRC_FB[address]            = 0x00U;
            pRegisterContainer->DHU_0XF9_UPDATESTATUS_FB[address]   = 0x00U;
        }
    }
    for(counter =0x0001U;counter<WritePageSize;counter++){
        pRegisterContainer->DHU_0XE7_TRANSFER_REQ[counter]        =   0x00U;
    }
    pRegisterContainer->DHU_0XE4_APP_REQ[UpdateLenPos]           = 0x03U;
    pRegisterContainer->DHU_0XE5_BL_REQ[UpdateLenPos]            = 0x03U;
    pRegisterContainer->DHU_0XE6_ERASE_REQ[UpdateLenPos]         = 0x03U;
    pRegisterContainer->DHU_0XE7_TRANSFER_REQ[UpdateLenPos]      = 0x84U;
    pRegisterContainer->DHU_0XE8_CRC_REQ[UpdateLenPos]           = 0x04U;
    pRegisterContainer->DHU_0XE9_UPDATESTATUS_REQ[UpdateLenPos]  = 0x02U;
    pRegisterContainer->DHU_0XF4_APP_FB[UpdateLenPos]            = 0x03U;
    pRegisterContainer->DHU_0XF5_BL_FB[UpdateLenPos]             = 0x03U;
    pRegisterContainer->DHU_0XF6_ERASE_FB[UpdateLenPos]          = 0x03U;
    pRegisterContainer->DHU_0XF7_TRANSFER_FB[UpdateLenPos]       = 0x04U;
    pRegisterContainer->DHU_0XF8_CRC_FB[UpdateLenPos]            = 0x03U;
    pRegisterContainer->DHU_0XF9_UPDATESTATUS_FB[UpdateLenPos]   = 0x03U;
    (void)address;
}

void RegisterApp_DHU_Setup(uint8_t Page,uint16_t RegisterOffset,uint8_t RegisterValue)
{
    RegisterApp_Setup(Page,&RegisterContainer,RegisterOffset,RegisterValue);
}

void RegisterApp_Setup(uint8_t Page,Register* pRegisterContainer,uint16_t RegisterOffset,uint8_t RegisterValue)
{
    switch(Page)
    {
        case CMD_DISP_STATUS:
            pRegisterContainer->DHU_0X00_DISP_STATUS[RegisterOffset] = RegisterValue;
        break;

        case CMD_DISP_ID:
            pRegisterContainer->DHU_0X01_DISP_ID[RegisterOffset] = RegisterValue;
        break;

        case CMD_BL_PWM:
            pRegisterContainer->DHU_0X02_BL_PWM[RegisterOffset] = RegisterValue;
        break;

        case CMD_DISP_UD:
            pRegisterContainer->DHU_0X03_DISP_UD[RegisterOffset] = RegisterValue;
        break;

        case CMD_DISP_EN:
            pRegisterContainer->DHU_0X04_DISP_EN[RegisterOffset] = RegisterValue;
        break;

        case CMD_DISP_SHUTD:
            pRegisterContainer->DHU_0X05_DISP_SHUTD[RegisterOffset] = RegisterValue;
        break;

        case CMD_ISR_STATUS:
            pRegisterContainer->DHU_0X30_ISR_STATUS[RegisterOffset] = RegisterValue;
        break;

        case CMD_CORE_ASMB:
            pRegisterContainer->DHU_0X31_CORE_ASMB[RegisterOffset] = RegisterValue;
        break;

        case CMD_DELIVER_ASMB:
            pRegisterContainer->DHU_0X32_DELIVER_ASMB[RegisterOffset] = RegisterValue;
        break;

        case CMD_SW_FPN:
            pRegisterContainer->DHU_0X33_SW_FPN[RegisterOffset] = RegisterValue;
        break;

        case CMD_SN:
            pRegisterContainer->DHU_0X34_SN[RegisterOffset] = RegisterValue;
        break;

        case CMD_MC_FPN:
            pRegisterContainer->DHU_0X35_MC_FPN[RegisterOffset] = RegisterValue;
        break;

        case CMD_DTC:
            pRegisterContainer->DHU_0XA3_DTC[RegisterOffset] = RegisterValue;
        break;

        case CMD_APP_REQ:
            pRegisterContainer->DHU_0XE4_APP_REQ[RegisterOffset] = RegisterValue;
        break;

        case CMD_BL_REQ:
            pRegisterContainer->DHU_0XE5_BL_REQ[RegisterOffset] = RegisterValue;
        break;

        case CMD_ERASE_REQ:
            pRegisterContainer->DHU_0XE6_ERASE_REQ[RegisterOffset] = RegisterValue;
        break;

        case CMD_TRANSFER_REQ:
            pRegisterContainer->DHU_0XE7_TRANSFER_REQ[RegisterOffset] = RegisterValue;
        break;

        case CMD_CRC_REQ:
            pRegisterContainer->DHU_0XE8_CRC_REQ[RegisterOffset] = RegisterValue;
        break;

        case CMD_UPDATESTATUS_REQ:
            pRegisterContainer->DHU_0XE9_UPDATESTATUS_REQ[RegisterOffset] = RegisterValue;
        break;

        case CMD_APP_FB:
            pRegisterContainer->DHU_0XF4_APP_FB[RegisterOffset] = RegisterValue;
        break;

        case CMD_BL_FB:
            pRegisterContainer->DHU_0XF5_BL_FB[RegisterOffset] = RegisterValue;
        break;

        case CMD_ERASE_FB:
            pRegisterContainer->DHU_0XF6_ERASE_FB[RegisterOffset] = RegisterValue;
        break;

        case CMD_TRANSFER_FB:
            pRegisterContainer->DHU_0XF7_TRANSFER_FB[RegisterOffset] = RegisterValue;
        break;

        case CMD_CRC_FB:
            pRegisterContainer->DHU_0XF8_CRC_FB[RegisterOffset] = RegisterValue;
        break;

        case CMD_UPDATESTATUS_FB:
            pRegisterContainer->DHU_0XF9_UPDATESTATUS_FB[RegisterOffset] = RegisterValue;
        break;

        default:
			// ...
        break;
    }
}

uint8_t RegisterApp_DHU_Read(uint8_t Page,uint16_t RegisterOffset)
{
    return RegisterApp_Read(Page,&RegisterContainer,RegisterOffset);
}

uint8_t RegisterApp_Read(uint8_t Page,Register* pRegisterContainer,uint16_t RegisterOffset)
{
	uint8_t u8Return;
	
    switch(Page)
    {
        case CMD_DISP_STATUS:
            u8Return = pRegisterContainer->DHU_0X00_DISP_STATUS[RegisterOffset];
        break;

        case CMD_DISP_ID:
            u8Return = pRegisterContainer->DHU_0X01_DISP_ID[RegisterOffset];
        break;

        case CMD_BL_PWM:
            u8Return = pRegisterContainer->DHU_0X02_BL_PWM[RegisterOffset];
        break;

        case CMD_DISP_UD:
            u8Return = pRegisterContainer->DHU_0X03_DISP_UD[RegisterOffset];
        break;

        case CMD_DISP_EN:
            u8Return = pRegisterContainer->DHU_0X04_DISP_EN[RegisterOffset];
        break;

        case CMD_DISP_SHUTD:
            u8Return = pRegisterContainer->DHU_0X05_DISP_SHUTD[RegisterOffset];
        break;

        case CMD_ISR_STATUS:
            u8Return = pRegisterContainer->DHU_0X30_ISR_STATUS[RegisterOffset];
        break;

        case CMD_CORE_ASMB:
            u8Return = pRegisterContainer->DHU_0X31_CORE_ASMB[RegisterOffset];
        break;

        case CMD_DELIVER_ASMB:
            u8Return = pRegisterContainer->DHU_0X32_DELIVER_ASMB[RegisterOffset];
        break;

        case CMD_SW_FPN:
            u8Return = pRegisterContainer->DHU_0X33_SW_FPN[RegisterOffset];
        break;

        case CMD_SN:
            u8Return = pRegisterContainer->DHU_0X34_SN[RegisterOffset];
        break;

        case CMD_MC_FPN:
            u8Return = pRegisterContainer->DHU_0X35_MC_FPN[RegisterOffset];
        break;

        case CMD_DTC:
            u8Return = pRegisterContainer->DHU_0XA3_DTC[RegisterOffset];
        break;

        case CMD_APP_REQ:
            u8Return = pRegisterContainer->DHU_0XE4_APP_REQ[RegisterOffset];
        break;

        case CMD_BL_REQ:
            u8Return = pRegisterContainer->DHU_0XE5_BL_REQ[RegisterOffset];
        break;

        case CMD_ERASE_REQ:
            u8Return = pRegisterContainer->DHU_0XE6_ERASE_REQ[RegisterOffset];
        break;

        case CMD_TRANSFER_REQ:
            u8Return = pRegisterContainer->DHU_0XE7_TRANSFER_REQ[RegisterOffset];
        break;

        case CMD_CRC_REQ:
            u8Return = pRegisterContainer->DHU_0XE8_CRC_REQ[RegisterOffset];
        break;

        case CMD_UPDATESTATUS_REQ:
            u8Return = pRegisterContainer->DHU_0XE9_UPDATESTATUS_REQ[RegisterOffset];
        break;

        case CMD_APP_FB:
            u8Return = pRegisterContainer->DHU_0XF4_APP_FB[RegisterOffset];
        break;

        case CMD_BL_FB:
            u8Return = pRegisterContainer->DHU_0XF5_BL_FB[RegisterOffset];
        break;

        case CMD_ERASE_FB:
            u8Return = pRegisterContainer->DHU_0XF6_ERASE_FB[RegisterOffset];
        break;

        case CMD_TRANSFER_FB:
            u8Return = pRegisterContainer->DHU_0XF7_TRANSFER_FB[RegisterOffset];
        break;

        case CMD_CRC_FB:
            u8Return = pRegisterContainer->DHU_0XF8_CRC_FB[RegisterOffset];
        break;

        case CMD_UPDATESTATUS_FB:
            u8Return = pRegisterContainer->DHU_0XF9_UPDATESTATUS_FB[RegisterOffset];
        break;

        default:
            u8Return = 0xFFU;
        break;
    }
	
	return u8Return;
}

/* *****************************************************************************
 End of File
 */
