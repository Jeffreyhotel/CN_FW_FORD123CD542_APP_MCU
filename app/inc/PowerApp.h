#ifndef POWERAPP_H__
#define POWERAPP_H__

#include "main.h"

#define POWER_OFF   0x00U
#define POWER_ON    0x01U

#define IO_HIGH     1U
#define IO_LOW      0U

#define IO_STATUS_HIGH  0x01U
#define IO_STATUS_LOW   0x00U
#define IO_STATUS_SWIM  0x02U

typedef struct{
    uint8_t Status;
    const GPIO_PRT_Type *Port;
    uint32_t PortNumber;
    uint8_t Threshlod;
    uint8_t ConsecutiveHighCnt;
    uint8_t ConsecutiveLowCnt;
}DetectPG;

void PowerApp_Sequence(uint8_t u8Action);
void PowerApp_PowerGoodInitial();
void PowerApp_PowerGoodFlow();

#endif
