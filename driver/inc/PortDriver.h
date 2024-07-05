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

#ifndef PORTDRIVER_H
#define PORTDRIVER_H

#include "main.h"

/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */

uint8_t PortDrvier_PinRead(const GPIO_PRT_Type *base, uint32_t u32Pin);
void PortDriver_PinWrite(GPIO_PRT_Type *base, uint32_t u32Pin, uint32_t value);
void PortDriver_PinSet(GPIO_PRT_Type *base, uint32_t u32Pin);
void PortDriver_PinClear(GPIO_PRT_Type *base, uint32_t u32Pin);
void PortDriver_PinToggle(GPIO_PRT_Type *base, uint32_t u32Pin);

#endif