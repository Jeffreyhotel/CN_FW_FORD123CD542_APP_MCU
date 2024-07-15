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

cy_stc_scb_uart_context_t SCB_UART3_DEBUG_context;

uint8_t UartDriver_Initial()
{
    uint8_t u8result = TRUE;
    cy_en_scb_uart_status_t initstatus;
    /* Initialize the UART */
    initstatus = Cy_SCB_UART_Init(SCB_UART3_DEBUG_HW, &SCB_UART3_DEBUG_config, &SCB_UART3_DEBUG_context);

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

uint8_t UartDriver_Receive(uint8_t RxBuffer[], uint32_t u32RxSize)
{
    uint32_t status;
    uint8_t result = UART_FAIL;
    status = Cy_SCB_UART_GetArray(SCB_UART3_DEBUG_HW,RxBuffer,u32RxSize);
    if ( status > 0)
    {
        result = UART_SUCCESS;
    }else{
        result = UART_RX_EMPTY;
    }
    return result;
}

uint32_t UartDriver_GetNumReceived()
{
    return Cy_SCB_UART_GetNumInRxFifo(SCB_UART3_DEBUG_HW);
}

void UartDriver_AbortReceive()
{
    Cy_SCB_UART_ClearRxFifo(SCB_UART3_DEBUG_HW);
}

void UartDriver_TxWriteString(uint8_t* u8TxBuffer)
{
    Cy_SCB_UART_PutString(SCB_UART3_DEBUG_HW, (const char_t *)u8TxBuffer);
}

/* *****************************************************************************
 End of File
 */