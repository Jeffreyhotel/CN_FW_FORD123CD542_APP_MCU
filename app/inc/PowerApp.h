#ifndef POWERAPP_H__
#define POWERAPP_H__

#include "main.h"

#define POWER_OFF   0x00U
#define POWER_ON    0x01U

void PowerApp_Sequence(uint8_t u8Action);
void PowerApp_PowerGoodInitial();
void PowerApp_PowerGoodFlow();

#endif
