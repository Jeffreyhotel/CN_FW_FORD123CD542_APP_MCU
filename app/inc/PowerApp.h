#ifndef POWERAPP_H__
#define POWERAPP_H__

#include "main.h"

#define POWER_OFF   0x00U
#define POWER_ON    0x01U
#define LCD_OFF     0x02U
#define LCD_ON      0x03U

#define RTQ6749_PAVDD_FAULT_MASK 0x08U
#define RTQ6749_VGL_FAULT_MASK 0x04U
#define RTQ6749_VGH_FAULT_MASK 0x02U
#define RTQ6749_NAVDD_FAULT_MASK 0x01U

void PowerApp_Sequence(uint8_t u8Action);
void PowerApp_PowerGoodInitial();
void PowerApp_PowerGoodFlow();
void PowerApp_RTQ6749_FaultCheck();
void PowerApp_LP8664_FaultCheck();
void PowerApp_LP8664_CurrentSet();

#endif
