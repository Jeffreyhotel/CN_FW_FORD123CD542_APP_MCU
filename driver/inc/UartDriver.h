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

void UartDriver_TxWriteString(uint8_t* u8TxBuffer);
uint8_t UartDriver_Initial();

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */
