#ifndef UARTApp_H__
#define UARTApp_H__

#include "main.h"

void UartApp_ReadFlow();
bool UartApp_CompareBuffer(char *StringSource, uint8_t rdBuffer[], uint8_t start_pos, uint8_t stop_pos);

#endif