#include "driver/inc/TC0Driver.h"

#if 0
bool TC0Driver_Initial(void)
{
    /* Do nothing*/
}
#endif

bool TC0Driver_TimerStart( void )
{
    bool bresult = true;
    cy_rslt_t result;
    /* Initialize the TCPWM component in timer/counter mode. The return value of the
     * function indicates whether the arguments are valid or not.
     */
    result = Cy_TCPWM_Counter_Init(TC0_TIMER_HW, TC0_TIMER_NUM, &TC0_TIMER_config);
    if(result != CY_TCPWM_SUCCESS)
    {
        bresult = false;
    }

    Cy_TCPWM_Counter_Enable(TC0_TIMER_HW, TC0_TIMER_NUM);

    /* Check if the desired interrupt is enabled prior to triggering */
    if (0UL != (CY_TCPWM_INT_ON_TC & Cy_TCPWM_GetInterruptMask(TC0_TIMER_HW, TC0_TIMER_NUM)))
    {
       Cy_TCPWM_SetInterrupt(TC0_TIMER_HW, TC0_TIMER_NUM, CY_TCPWM_INT_ON_TC);
    }

    /* Set the timer period in milliseconds. To count N cycles, period should be
     * set to N-1.
     */
    Cy_TCPWM_Counter_SetPeriod(TC0_TIMER_HW, TC0_TIMER_NUM, TIMER_PERIOD_MSEC-1 );

    /* Trigger a software start on the counter instance. This is required when
     * no other hardware input signal is connected to the component to act as
     * a trigger source.
     */
    Cy_TCPWM_TriggerStart(TC0_TIMER_HW, TC0_TIMER_MASK);
    return bresult;
}

void TC0Driver_IntFlagClean(void)
{
    Cy_TCPWM_ClearInterrupt(TC0_TIMER_HW, TC0_TIMER_NUM, CY_TCPWM_INT_ON_TC);
}

bool TC0Driver_TimerCallbackRegister(cy_israddress userIsr)
{
    bool bresult = true;
    cy_rslt_t result;
    /* Initialize the interrupt vector table with the timer interrupt handler
     * address and assign priority.
     */
    cy_stc_sysint_t intrCfg =
    {
        /*.intrSrc =*/ TC0_TIMER_IRQ,    /* Interrupt source is Timer interrupt */
        /*.intrPriority =*/ 3UL            /* Interrupt priority is 3 */
    };
    result = Cy_SysInt_Init(&intrCfg, userIsr);
    if(result != CY_SYSINT_SUCCESS)
    {
        bresult = false;
    }

    /* Enable Interrupt */
    NVIC_EnableIRQ(intrCfg.intrSrc);

    return bresult;
}