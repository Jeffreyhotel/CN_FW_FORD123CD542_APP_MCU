#include "driver/inc/WdtDriver.h"

/* Set the desired number of ignore bits */
#define IGNORE_BITS                (0U)
/* Waiting time, in milliseconds, for proper start-up of ILO */
#define ILO_START_UP_TIME          (2U)
/* WDT interrupt period in milliseconds.
Max limit is 1698 ms. */
#define WDT_INTERRUPT_INTERVAL_MS  (1500)
/* Define desired delay in microseconds */
#define DESIRED_WDT_INTERVAL       (WDT_INTERRUPT_INTERVAL_MS  * 1000U)
/* WDT interrupt priority */
#define WDT_INTERRUPT_PRIORITY     (0U)

/*****************************************************************************
* Global Variables
*****************************************************************************/
/* WDT interrupt service routine configuration */
const cy_stc_sysint_t wdt_isr_cfg =
{
    .intrSrc = srss_interrupt_wdt_IRQn, /* Interrupt source is WDT interrupt */
    .intrPriority = WDT_INTERRUPT_PRIORITY /* Interrupt priority is 0 */
};

/* Variable to check whether WDT interrupt is triggered */
volatile bool interrupt_flag = false;

/* Variable to store the counts required after ILO compensation */
static uint32_t ilo_compensated_counts = 0U;
static uint32_t temp_ilo_counts = 0U;

cy_stc_sysclk_context_t sysClkContext;

cy_stc_syspm_callback_params_t sysClkCallbackParams =
{
    .base       = NULL,
    .context    = (void*)&sysClkContext
};

/* Callback declaration for Deep Sleep mode */
cy_stc_syspm_callback_t sysClkCallback =
{
    .callback       = &Cy_SysClk_DeepSleepCallback,
    .type           = CY_SYSPM_DEEPSLEEP,
    .skipMode       = 0UL,
    .callbackParams = &sysClkCallbackParams,
    .prevItm        = NULL,
    .nextItm        = NULL,
    .order          = 0
};

bool WdtDriver_Initial(void)
{
    bool bresult = true;

    /* Step 1- Write the ignore bits - operate with full 16 bits */
    Cy_WDT_SetIgnoreBits(IGNORE_BITS);
    if(Cy_WDT_GetIgnoreBits() != IGNORE_BITS)
    {
        bresult = false;
    }

    /* Step 2- Clear match event interrupt, if any */
    Cy_WDT_ClearInterrupt();

    /* Step 3- Enable ILO */
    Cy_SysClk_IloEnable();
    /* Waiting for proper start-up of ILO */
    Cy_SysLib_Delay(ILO_START_UP_TIME);

    /* Starts the ILO accuracy/Trim measurement */
    Cy_SysClk_IloStartMeasurement();
    /* Calculate the count value to set as WDT match since ILO is inaccurate */
    if(CY_SYSCLK_SUCCESS ==\
                Cy_SysClk_IloCompensate(DESIRED_WDT_INTERVAL, &temp_ilo_counts))
    {
        ilo_compensated_counts = (uint32_t)temp_ilo_counts;
    }
    return bresult;
}

bool WdtDriver_SetMatchIfPeriodMode(void)
{
    bool bresult = true;
    /* Step 4- Write match value if periodic interrupt mode selected */
    Cy_WDT_SetMatch(ilo_compensated_counts);
    if(Cy_WDT_GetMatch() != ilo_compensated_counts)
    {
        bresult = false;
    }
    return bresult;
}

void WdtDriver_UpdateMatchCount(void)
{
    /* Step 4- Write match value if periodic interrupt mode selected */
    /* Update the match count */
    Cy_WDT_SetMatch((uint16_t)(Cy_WDT_GetMatch() +\
                                ilo_compensated_counts));
}

bool WdtDriver_RegisterISR(cy_israddress user_isr)
{
    bool bresult = true;
    /* Step 5 - Initialize and enable interrupt if periodic interrupt
        mode selected */
    cy_en_sysint_status_t status = CY_SYSINT_BAD_PARAM;
    status = Cy_SysInt_Init(&wdt_isr_cfg, user_isr);
    if(status != CY_SYSINT_SUCCESS)
    {
        bresult = false;
    }
    NVIC_EnableIRQ(wdt_isr_cfg.intrSrc);
    Cy_WDT_UnmaskInterrupt();
    return bresult;
}

bool WdtDriver_Enable(void)
{
    bool bresult = true;
    Cy_WDT_Enable();
    if(Cy_WDT_IsEnabled() == false)
    {
        bresult = false;
    }
    return bresult;
}

void WdtDriver_Disable(void)
{
    Cy_WDT_Disable();
    Cy_SysClk_IloDisable();
    ilo_compensated_counts = 0;
    temp_ilo_counts = 0;
}

void WdtDriver_RegisterDSCallback(void)
{
    /* Register Deep Sleep callback */
    Cy_SysPm_RegisterCallback(&sysClkCallback);
}