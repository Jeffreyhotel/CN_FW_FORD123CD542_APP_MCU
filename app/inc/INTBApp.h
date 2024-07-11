#ifndef INTBAPP_H__
#define INTBAPP_H__

#include "main.h"

#define INTB_STATE_INIT     0U
#define INTB_STATE_IDLE     1U
#define INTB_STATE_SET      2U
#define INTB_STATE_HOLD     3U
#define INTB_STATE_DEINIT   4U

#define INTB_INITIAL        1U
#define INTB_DEINITIAL      0U

#define INTB_ERROR_SET      0x01U
#define INTB_ERROR_CLEAR    0x00U

void INTBApp_Flow(void);
void INTBApp_PullErrorSetOrClear(uint8_t u8SetValue);
void INTBApp_InitSwitch(uint8_t u8SetValue);

#endif
