#include "PwmDriver.h"

void PwmDriver_Initial(void)
{
    (void) Cy_TCPWM_PWM_Init(TC7_PWM_LED_HW, TC7_PWM_LED_NUM, &TC7_PWM_LED_config);
    //Cy_TCPWM_PWM_SetPeriod0(TC7_PWM_LED_HW,TC7_PWM_LED_NUM,PWM_PERIOD);
    Cy_TCPWM_Enable_Multiple(TC7_PWM_LED_HW, TC7_PWM_LED_MASK);
    Cy_TCPWM_TriggerReloadOrIndex(TC7_PWM_LED_HW, TC7_PWM_LED_MASK);
}

void PwmDriver_Start(void)
{   
    if (0UL != (CY_TCPWM_PWM_STATUS_COUNTER_RUNNING & 
                Cy_TCPWM_PWM_GetStatus(TC7_PWM_LED_HW, TC7_PWM_LED_NUM)))
    {
        /* The Counter is running */
        Cy_TCPWM_Enable_Multiple(TC7_PWM_LED_HW,TC7_PWM_LED_MASK);
    }else{
        Cy_TCPWM_Enable_Multiple(TC7_PWM_LED_HW,TC7_PWM_LED_MASK);
        Cy_TCPWM_TriggerReloadOrIndex(TC7_PWM_LED_HW, TC7_PWM_LED_MASK);
    }
}

void PwmDriver_Stop(void)
{
    Cy_TCPWM_Disable_Multiple(TC7_PWM_LED_HW,TC7_PWM_LED_MASK);
}

void PwmDriver_DutySet(uint16_t duty)
{
    uint32_t cnt = 0U;
    /* Need to double check, the potential take time would cause delay*/
#if 1
    while(duty < Cy_TCPWM_PWM_GetCounter(TC7_PWM_LED_HW,TC7_PWM_LED_NUM) || cnt < (PWM_PERIOD))
    {
        if(Cy_TCPWM_PWM_GetCounter(TC7_PWM_LED_HW,TC7_PWM_LED_NUM) > Cy_TCPWM_PWM_GetCompare0(TC7_PWM_LED_HW,TC7_PWM_LED_NUM)){
            break;
        }
        cnt++;
    }
#endif

/*Do not work (from Sean)*/
#if 0
    Cy_TCPWM_ClearInterrupt(TC7_PWM_LED_HW,TC7_PWM_LED_NUM,CY_TCPWM_INT_ON_CC);
    while(0UL == (CY_TCPWM_INT_ON_CC & Cy_TCPWM_GetInterruptMask(TC7_PWM_LED_HW,TC7_PWM_LED_NUM)));
#endif
    Cy_TCPWM_PWM_SetCompare0(TC7_PWM_LED_HW,TC7_PWM_LED_NUM,(uint32_t)(duty));
}