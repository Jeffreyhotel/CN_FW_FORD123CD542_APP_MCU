/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef UARTDRIVER_H
#define UARTDRIVER_H


/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */
#include "main.h"

#define UART_SUCCESS    0U
#define UART_BAD_PARAM  1U
#define UART_RX_BUSY    2U
#define UART_TX_BUSY    3U
#define UART_RX_EMPTY   4U
#define UART_FAIL       5U

uint8_t UartDriver_Receive(uint8_t RxBuffer[], uint32_t u32RxSize);
uint32_t UartDriver_GetNumReceived();
void UartDriver_AbortReceive();
void UartDriver_TxWriteString(uint8_t* u8TxBuffer);
uint8_t UartDriver_Initial();

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */
