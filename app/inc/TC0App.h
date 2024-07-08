#ifndef TC0App_H__
#define TC0App_H__

#include "main.h"

#define FLAG_CPUCOUNT       0x00U
#define FLAG_IRQCOUNT       0x01U
#define FLAG_HANDSHAKECOUNT 0x02U
#define FLAG_DERATECOUNT    0x03U
#define FLAG_BATTERYCOUNT   0x04U

void TC0App_Initial(void);
void TC0App_DerateCntStartSet(uint8_t SetValue);
void TC0App_BatteryCntStartSet(uint8_t SetValue);
void TC0App_NormalWorkStartSet(uint8_t SetValue);
uint8_t TC0App_FlagReturn(uint8_t Request);
void TC0App_FlagReset(uint8_t Request);
uint8_t TC0App_DelayMS(uint16_t delay);
uint8_t TC0App_DelayUS(uint16_t delay);

#endif