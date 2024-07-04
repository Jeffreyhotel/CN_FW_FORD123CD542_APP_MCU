// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "driver/inc/UartDriver.h"

// *****************************************************************************
// *****************************************************************************
// Section: PORT Implementation
// *****************************************************************************
// *****************************************************************************

cy_stc_scb_uart_context_t CYBSP_UART_context;

uint8_t UartDriver_Initial()
{
    uint8_t u8result = TRUE;
    cy_en_scb_uart_status_t initstatus;
    /* Initialize the UART */
    initstatus = Cy_SCB_UART_Init(SCB_UART3_DEBUG_HW, &SCB_UART3_DEBUG_config, &CYBSP_UART_context);

    /* Initialization failed. Handle error */
    if(initstatus!=CY_SCB_UART_SUCCESS)
    {
        u8result = FALSE;
    }else
    {
        Cy_SCB_UART_Enable(SCB_UART3_DEBUG_HW);
    }
    return u8result;
}

void UartDriver_TxWriteString(uint8_t* u8TxBuffer)
{
    Cy_SCB_UART_PutString(SCB_UART3_DEBUG_HW, (const char_t *)u8TxBuffer);
}

/* *****************************************************************************
 End of File
 */