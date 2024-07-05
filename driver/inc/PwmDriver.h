#ifndef PWMDRIVER_H__
#define PWMDRIVER_H__

#include "main.h"

#define PWM_PERIOD  19799U
#define PWM_UNIT    (PWM_PERIOD+1)/100

void PwmDriver_Initial(void);
void PwmDriver_Start(void);
void PwmDriver_Stop(void);
void PwmDriver_DutySet(uint8_t duty);

#endif