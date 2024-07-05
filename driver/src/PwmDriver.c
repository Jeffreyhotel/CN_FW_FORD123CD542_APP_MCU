#include "PwmDriver.h"

void PwmDriver_Initial(void)
{
    (void) Cy_TCPWM_PWM_Init(TC7_PWM_LED_HW, TC7_PWM_LED_NUM, &TC7_PWM_LED_config);
    Cy_TCPWM_PWM_SetPeriod0(TC7_PWM_LED_HW,TC7_PWM_LED_NUM,PWM_PERIOD);
    Cy_TCPWM_Enable_Multiple(TC7_PWM_LED_HW, TC7_PWM_LED_MASK);
    Cy_TCPWM_TriggerReloadOrIndex(TC7_PWM_LED_HW, TC7_PWM_LED_MASK);
}

void PwmDriver_Start(void)
{
    Cy_TCPWM_Enable_Multiple(TC7_PWM_LED_HW,TC7_PWM_LED_MASK);
}

void PwmDriver_Stop(void)
{
    Cy_TCPWM_Disable_Multiple(TC7_PWM_LED_HW,TC7_PWM_LED_MASK);
}

void PwmDriver_DutySet(uint8_t duty)
{
    if (duty > 100U)
    {
        /* code */
        duty = 100U;
    }
    Cy_TCPWM_PWM_SetCompare0(TC7_PWM_LED_HW,TC7_PWM_LED_NUM,(uint32_t)(duty*PWM_UNIT));
}