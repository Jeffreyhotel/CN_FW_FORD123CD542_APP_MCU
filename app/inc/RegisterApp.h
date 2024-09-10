#ifndef RegisterApp_H__
#define RegisterApp_H__

#include "main.h"

#define RegisterMaxSize 80U
#define WritePageSize   200U

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
#define CMD_FB_UPDATE_SUCCESS       0x00U
#define CMD_FB_UPDATE_FAIL          0x01U
#define CMD_FB_UPDATE_PROGRESSING   0x02U

/*Flag Register Define*/
#define DTC_SW_VERSION              0x01U
#define DTC_BL_VERSION              0x02U
#define DTC_HW_VERSION              0x03U
#define DTC_DDI_VERSION             0x04U
#define DTC_RESET_CAUSE             0x05U
#define DTC_RST_RQ                  0x06U
#define DTC_BIAS_FAULT_0x1D         0x07U
#define DTC_LED_FAULT_0x0E          0x08U
#define DTC_LED_FAULT_0x0F          0x09U
#define DTC_LED_FAULT_0x10          0x0AU
#define DTC_LED_FAULT_0x11          0x0BU
#define DTC_LED_FAULT_0x12          0x0CU
#define DTC_LED_FAULT_0x13          0x0DU
#define DTC_LCD_FAULT_0x19          0x0EU
#define DTC_LCD_FAULT_0x1A          0x0FU
#define DTC_LCD_FAULT_0x1B          0x10U
#define DTC_LCD_FAULT_0x1C          0x11U
#define DTC_LCD_FAULT_0x1F          0x12U
#define DTC_I2CM_FAULT              0x13U
#define DTC_BATT_VOLT_ADC           0x17U
#define DTC_BLT_TEMP_ADC            0x19U
#define DTC_PCB_TEMP_ADC            0x1BU

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

void RegisterApp_DHU_Setup(uint8_t Page,uint16_t RegisterOffset,uint8_t RegisterValue);
void RegisterApp_Setup(uint8_t Page,Register* pRegisterContainer,uint16_t RegisterOffset,uint8_t RegisterValue);
uint8_t RegisterApp_DHU_Read(uint8_t Page,uint16_t RegisterOffset);
uint8_t RegisterApp_Read(uint8_t Page,Register* pRegisterContainer,uint16_t RegisterOffset);

#endif
