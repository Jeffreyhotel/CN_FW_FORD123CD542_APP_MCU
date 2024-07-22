#include "app/inc/DeviceApp.h"
#include "app/inc/RegisterApp.h"

/*
**  Ascii to Hex Converter: https://zh-tw.rakko.tools/tools/77/
*/

#define NUM_DISP_ID    2U
static uint8_t DV_DISP_ID[NUM_DISP_ID] = {
    /* EXAMPLE: H1BT-14F180-FA*/
    0x3F,0x01
};
#define NUM_CORE_FPN    25U
static uint8_t DV_CORE_ASSB_FPN[NUM_CORE_FPN] = {
    /* EXAMPLE: H1BT-14F180-FA*/
    0x48,0x31,0x42,0x54,0x2d,0x31,0x34,0x46,0x31,0x38,0x30,0x2d,0x46,0x41
};
#define NUM_DELIVER_FPN    25U
static uint8_t DV_DELIVER_ASSB_FPN[NUM_DELIVER_FPN] = {
    /* EXAMPLE: H1BT-14F180-FA*/
    0x48,0x31,0x42,0x54,0x2d,0x31,0x34,0x46,0x31,0x38,0x30,0x2d,0x46,0x41
};
#define NUM_SW_FPN    25U
static uint8_t DV_SW_FPN[NUM_SW_FPN] = {
    /* EXAMPLE: H1BT-14F180-FA*/
    0x48,0x31,0x42,0x54,0x2d,0x31,0x34,0x46,0x31,0x38,0x30,0x2d,0x46,0x41
};
#define NUM_SERIAL_FPN    25U
static uint8_t DV_SERIAL_FPN[NUM_SERIAL_FPN] = {
    /* EXAMPLE: H1BT-14F180-FA*/
    0x48,0x31,0x42,0x54,0x2d,0x31,0x34,0x46,0x31,0x38,0x30,0x2d,0x46,0x41
};
#define NUM_MAINCAL_FPN    25U
static uint8_t DV_MAINCAL_FPN[NUM_MAINCAL_FPN] = {
    /* EXAMPLE: H1BT-14F180-FA*/
    0x48,0x31,0x42,0x54,0x2d,0x31,0x34,0x46,0x31,0x38,0x30,0x2d,0x46,0x41
};

void DeviceApp_Intial(void)
{
    for(uint16_t index=0;index<NUM_DISP_ID;index++)
    {
        RegisterApp_DHU_Setup(CMD_DISP_ID,CMD_DATA_POS+index,DV_DISP_ID[index]);
    }
    for(uint16_t index=0;index<NUM_CORE_FPN;index++)
    {
        RegisterApp_DHU_Setup(CMD_CORE_ASMB,CMD_DATA_POS+index,DV_CORE_ASSB_FPN[index]);
    }
    for(uint16_t index=0;index<NUM_DELIVER_FPN;index++)
    {
        RegisterApp_DHU_Setup(CMD_DELIVER_ASMB,CMD_DATA_POS+index,DV_DELIVER_ASSB_FPN[index]);
    }
    for(uint16_t index=0;index<NUM_SW_FPN;index++)
    {
        RegisterApp_DHU_Setup(CMD_SW_FPN,CMD_DATA_POS+index,DV_SW_FPN[index]);
    }
    for(uint16_t index=0;index<NUM_SERIAL_FPN;index++)
    {
        RegisterApp_DHU_Setup(CMD_SN,CMD_DATA_POS+index,DV_SERIAL_FPN[index]);
    }
    for(uint16_t index=0;index<NUM_MAINCAL_FPN;index++)
    {
        RegisterApp_DHU_Setup(CMD_MC_FPN,CMD_DATA_POS+index,DV_MAINCAL_FPN[index]);
    }
}