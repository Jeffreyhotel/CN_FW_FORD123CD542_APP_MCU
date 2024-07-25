#ifndef TC0App_H__
#define TC0App_H__

#include "main.h"

#define TIMER_CPUCOUNT          0x00U
#define TIMER_INT_SET_COUNT     0x01U
#define TIMER_INT_HOLD_COUNT    0x02U
#define TIMER_HANDSHAKECOUNT    0x03U
#define TIMER_DERATECOUNT       0x04U
#define TIMER_BATTERYCOUNT      0x05U
#define TIMER_WDTCOUNT          0x06U

#define DHUCmdBufferSize 256U

void TC0App_Initial(void);
void TC0App_DHUTaskClean(void);
void TC0App_DHUTaskPush(uint8_t DHUCmdID);
void TC0App_DerateCntStartSet(uint8_t SetValue);
void TC0App_BatteryCntStartSet(uint8_t SetValue);
void TC0App_NormalWorkStartSet(uint8_t SetValue);
void TC0App_IntbSetCountStartSet(uint8_t SetValue);
void TC0App_IntbHoldCountStartSet(uint8_t SetValue);
uint8_t TC0App_TimerReturn(uint8_t Request);
void TC0App_TimerReset(uint8_t Request);
uint8_t TC0App_DelayMS(uint16_t delay);
uint8_t TC0App_DelayUS(uint16_t delay);

#endif