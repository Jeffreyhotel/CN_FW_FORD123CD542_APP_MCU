#ifndef BACKLIGHTAPP_H__
#define BACKLIGHTAPP_H__

#include "main.h"

/*With 100 section*/
// #define BLT_SECTION 100U
// #define BLT_100P    100U
// #define BLT_60P     60U
// #define BLT_20P     20U
// #define BLT_0P      0U
// #define BLT_PERIOD  19799U
// #define BLT_UNITSTEP    ((BLT_PERIOD+1U)/BLT_SECTION)
// #define BLT_GRADUAL_UNIT    0x04U

/*With 3FF section*/
#define BLT_SECTION 0x03FFU
#define BLT_100P    0x03FFU
#define BLT_75P     0x02FFU
#define BLT_60P     0x0266U
#define BLT_40P     0x0199U
#define BLT_20P     0x00CDU
#define BLT_3P      0x001FU
#define BLT_0P      0x0000U
#define BLT_PERIOD  20459U
#define BLT_UNITSTEP    ((BLT_PERIOD+1U)/BLT_SECTION)
#define BLT_GRADUAL_UNIT    40U

/*DHU COMMAND PARA*/
#define BLT_DISABLE 0x00U
#define BLT_ENABLE  0x01U

#define BLT_NORMAL_MODE     0x00U
#define BLT_BURN_MODE       0x01U
#define BLT_BOIL_MODE       0x02U
#define BLT_SCORCH_MODE     0x03U

#define BLT_TEMP80  585U
#define BLT_TEMP85  519U
#define BLT_TEMP90  460U
#define BLT_TEMP95  408U

void BacklightApp_BattProtectSet(uint8_t u8Set);
void BacklightApp_RstRqSwitchSet(uint8_t u8Set);
void BacklightApp_Initial(void);
void BacklightApp_UpdateDimmingStep(void);
void BacklightApp_DimmingControl(void);
void BacklightApp_TempMonitor(void);
void BacklightApp_DeratingFlow(void);

#endif

