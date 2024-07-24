#ifndef RegisterApp_H__
#define RegisterApp_H__

#include "main.h"

#define RegisterMaxSize 80U
#define WritePageSize 2053U

/* Command Format*/
#define SUB_ADDR_POS  0x00U
#define CMD_DATA_POS  0x01U
#define CMD_UPDATE_DATA_POS 0x02U

/* Define DHU Command Number*/
#define CMD_DISP_STATUS             0x00U
#define CMD_DISP_ID                 0x01U
#define CMD_BL_PWM                  0x02U
#define CMD_DISP_UD                 0x03U
#define CMD_DISP_EN                 0x04U
#define CMD_DISP_SHUTD              0x05U
#define CMD_ISR_STATUS              0x30U
#define CMD_CORE_ASMB               0x31U
#define CMD_DELIVER_ASMB            0x32U
#define CMD_SW_FPN                  0x33U
#define CMD_SN                      0x34U
#define CMD_MC_FPN                  0x35U
#define CMD_DTC                     0xA3U
#define CMD_APP_REQ                 0xE4U
#define CMD_BL_REQ                  0xE5U
#define CMD_ERASE_REQ               0xE6U
#define CMD_TRANSFER_REQ            0xE7U
#define CMD_CRC_REQ                 0xE8U
#define CMD_UPDATESTATUS_REQ        0xE9U
#define CMD_APP_FB                  0xF4U
#define CMD_BL_FB                   0xF5U
#define CMD_ERASE_FB                0xF6U
#define CMD_TRANSFER_FB             0xF7U
#define CMD_CRC_FB                  0xF8U
#define CMD_UPDATESTATUS_FB         0xF9U

/* Define DHU Update Command reply*/
#define CMD_FB_MCU_OK               0x43U
#define CMD_FB_FAIL                 0x74U
#define CMD_REQ_FOR_TOUCH           0x02U
#define CMD_REQ_FOR_MCU             0x03U
#define CMD_FB_CHECKSUM_PASS        0x00U
#define CMD_FB_CHECKSUM_FAIL        0x01U

/*Flag Register Define*/
#define OFFSET_TOUCHFLAG    0x00U
#define COMP_OFFSET_IRQFLAG      0x01U
#define COMP_OFFSET_DHUOKFLAG    0x02U
#define COMP_OFFSET_BATT    0x03U
#define COMP_OFFSET_TEMP    0x05U
#define COMP_OFFSET_DD_FAILDET    0x07U
#define COMP_OFFSET_TP_FAILDET    0x0AU
#define COMP_OFFSET_TCON_FAILDET    0x0CU
#define COMP_OFFSET_DD_VER    0x0EU
#define COMP_OFFSET_TP_VER    0x0FU
#define COMP_OFFSET_TCON_VER    0x10U
#define COMP_OFFSET_MPQ5613FLT    0x12U
#define COMP_OFFSET_PGSUM    0x13U
#define COMP_OFFSET_ROMCRC  0x18U
#define COMP_OFFSET_MCUPOS  0x1AU
#define COMP_OFFSET_P1V0ADC  0x1BU
#define COMP_OFFSET_TCON1V1ADC  0x1DU
#define COMP_OFFSET_CRCSTATUS   0x1FU
#define COMP_OFFSET_ASILA0      0x21U
#define COMP_OFFSET_DTC65       0x22U
#define COMP_OFFSET_OVERFLOW    0x24U
#define COMP_OFFSET_TPTASKEN    0x25U
#define COMP_OFFSET_TPEICFLAG   0x26U
#define COMP_OFFSET_TPREPORTNG  0x27U
#define COMP_OFFSET_TPDEBUGINFO 0x28U

#define OFFSET_CMDID        0x00U
#define OFFSET_DATALENGTH   0x01U
#define OFFSET_DATA         0x03U

#define CMDID_COMP          0xF3U
#define CMDID_0X21H         0x21U
#define CMDID_0X22H         0x22U

typedef struct{
    volatile uint8_t DHU_0X00_DISP_STATUS[RegisterMaxSize];
    volatile uint8_t DHU_0X01_DISP_ID[RegisterMaxSize];
    volatile uint8_t DHU_0X02_BL_PWM[RegisterMaxSize];
    volatile uint8_t DHU_0X03_DISP_UD[RegisterMaxSize];
    volatile uint8_t DHU_0X04_DISP_EN[RegisterMaxSize];
    volatile uint8_t DHU_0X05_DISP_SHUTD[RegisterMaxSize];
    volatile uint8_t DHU_0X30_ISR_STATUS[RegisterMaxSize];
    volatile uint8_t DHU_0X31_CORE_ASMB[RegisterMaxSize];
    volatile uint8_t DHU_0X32_DELIVER_ASMB[RegisterMaxSize];
    volatile uint8_t DHU_0X33_SW_FPN[RegisterMaxSize];
    volatile uint8_t DHU_0X34_SN[RegisterMaxSize];
    volatile uint8_t DHU_0X35_MC_FPN[RegisterMaxSize];
    volatile uint8_t DHU_0XA3_DTC[RegisterMaxSize];

    volatile uint8_t DHU_0XE4_APP_REQ[RegisterMaxSize];
    volatile uint8_t DHU_0XE5_BL_REQ[RegisterMaxSize];
    volatile uint8_t DHU_0XE6_ERASE_REQ[RegisterMaxSize];
    volatile uint8_t DHU_0XE7_TRANSFER_REQ[WritePageSize];
    volatile uint8_t DHU_0XE8_CRC_REQ[RegisterMaxSize];
    volatile uint8_t DHU_0XE9_UPDATESTATUS_REQ[RegisterMaxSize];

    volatile uint8_t DHU_0XF4_APP_FB[RegisterMaxSize];
    volatile uint8_t DHU_0XF5_BL_FB[RegisterMaxSize];
    volatile uint8_t DHU_0XF6_ERASE_FB[RegisterMaxSize];
    volatile uint8_t DHU_0XF7_TRANSFER_FB[WritePageSize];
    volatile uint8_t DHU_0XF8_CRC_FB[RegisterMaxSize];
    volatile uint8_t DHU_0XF9_UPDATESTATUS_FB[RegisterMaxSize];
    
}Register;

void RegisterApp_ALL_Initial(void);
void RegisterApp_Initial(Register* pRegisterContainer);
void RegisterApp_DHU_CRCSetup(uint8_t Page, uint16_t Length);

void RegisterApp_DHU_Setup(uint8_t Page,uint16_t RegisterOffset,uint8_t RegisterValue);
void RegisterApp_Setup(uint8_t Page,Register* pRegisterContainer,uint16_t RegisterOffset,uint8_t RegisterValue);
uint8_t RegisterApp_DHU_Read(uint8_t Page,uint16_t RegisterOffset);
uint8_t RegisterApp_Read(uint8_t Page,Register* pRegisterContainer,uint16_t RegisterOffset);

#endif
