#ifndef PWMDRIVER_H__
#define PWMDRIVER_H__

#include "main.h"

#define PWM_PERIOD  20459U

void PwmDriver_Initial(void);
void PwmDriver_Start(void);
void PwmDriver_Stop(void);
void PwmDriver_DutySet(uint16_t duty);

#endif