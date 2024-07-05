#ifndef BACKLIGHTAPP_H__
#define BACKLIGHTAPP_H__

#include "main.h"

#define BLT_PERIOD  19799U
#define BLT_UNITSTEP    ((BLT_PERIOD+1U)/100U)

#define BLT_NORMAL_MODE     0x00U
#define BLT_BURN_MODE       0x01U
#define BLT_BOIL_MODE       0x02U
#define BLT_SCORCH_MODE     0x03U

#define BLT_TEMP80  1862U
#define BLT_TEMP90  1588U
#define BLT_TEMP93  1536U
#define BLT_TEMP105 1229U

void BacklightApp_BattProtectSet(uint8_t u8Set);
void BacklightApp_Initial(void);
void BacklightApp_DimmingControl(void);
void BacklightApp_TempMonitor(void);
void BacklightApp_DeratingFlow(void);

#endif

