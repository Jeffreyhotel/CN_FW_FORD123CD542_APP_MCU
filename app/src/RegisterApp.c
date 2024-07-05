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
    for(counter =0x0000U;counter<0x0050U;counter++){
        address = (uint8_t) counter;
        pRegisterContainer->DHU_0X00_DISP_STATUS[address] = 0x00U;
        pRegisterContainer->DHU_0X01_DISP_ID[address] = 0x00U;
        pRegisterContainer->DHU_0X02_BL_PWM[address] = 0x00U;
        pRegisterContainer->DHU_0X03_DISP_UD[address] = 0x00U;
        pRegisterContainer->DHU_0X04_DISP_EN[address] = 0x00U;
        pRegisterContainer->DHU_0X05_DISP_SHUTD[address] = 0x00U;
        pRegisterContainer->DHU_0X30_ISR_STATUS[address] = 0x00U;
        pRegisterContainer->DHU_0X31_CORE_ASMB[address] = 0x00U;
        pRegisterContainer->DHU_0X32_DELIVER_ASMB[address] = 0x00U;
        pRegisterContainer->DHU_0X33_SW_FPN[address] = 0x00U;
        pRegisterContainer->DHU_0X34_SN[address] = 0x00U;
        pRegisterContainer->DHU_0X35_MC_FPN[address] = 0x00U;
        pRegisterContainer->DHU_0XA3_DTC[address] = 0x00U;

        pRegisterContainer->DHU_0XC0_AB_SWITCH[address] = 0x00U;
        pRegisterContainer->DHU_0XC1_ERASE[address] = 0x00U;
        pRegisterContainer->DHU_0XC2_TRANSFER[address] = 0x00U;
        pRegisterContainer->DHU_0XC3_CRC[address] = 0x00U;
        pRegisterContainer->DHU_0XC4_RESET[address] = 0x00U;
        pRegisterContainer->DHU_0XD0_STATUS_CHECK[address] = 0x00U;
    }
    for(counter =0x0000U;counter<0x0805U;counter++){
        pRegisterContainer->DHU_0XC2_TRANSFER[counter]        =   0x00U;
    }
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

        case CMD_AB_SWITCH:
            pRegisterContainer->DHU_0XC0_AB_SWITCH[RegisterOffset] = RegisterValue;
        break;

        case CMD_ERASE:
            pRegisterContainer->DHU_0XC1_ERASE[RegisterOffset] = RegisterValue;
        break;

        case CMD_TRANSFER:
            pRegisterContainer->DHU_0XC2_TRANSFER[RegisterOffset] = RegisterValue;
        break;

        case CMD_CRC:
            pRegisterContainer->DHU_0XC3_CRC[RegisterOffset] = RegisterValue;
        break;

        case CMD_RESET:
            pRegisterContainer->DHU_0XC4_RESET[RegisterOffset] = RegisterValue;
        break;

        case CMD_STATUS_CHECK:
            pRegisterContainer->DHU_0XD0_STATUS_CHECK[RegisterOffset] = RegisterValue;
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

        case CMD_AB_SWITCH:
            u8Return = pRegisterContainer->DHU_0XC0_AB_SWITCH[RegisterOffset];
        break;

        case CMD_ERASE:
            u8Return = pRegisterContainer->DHU_0XC1_ERASE[RegisterOffset];
        break;

        case CMD_TRANSFER:
            u8Return = pRegisterContainer->DHU_0XC2_TRANSFER[RegisterOffset];
        break;

        case CMD_CRC:
            u8Return = pRegisterContainer->DHU_0XC3_CRC[RegisterOffset];
        break;

        case CMD_RESET:
            u8Return = pRegisterContainer->DHU_0XC4_RESET[RegisterOffset];
        break;

        case CMD_STATUS_CHECK:
            u8Return = pRegisterContainer->DHU_0XD0_STATUS_CHECK[RegisterOffset];
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
