#include "driver/inc/PortDriver.h"

uint8_t PortDrvier_PinRead(const GPIO_PRT_Type *base, uint32_t u32Pin)
{
    return (uint8_t)(Cy_GPIO_Read(base,u32Pin) & 0xFF);
}

void PortDriver_PinWrite(GPIO_PRT_Type *base, uint32_t u32Pin, uint32_t value)
{
    Cy_GPIO_Write(base,u32Pin,value);
}

void PortDriver_PinSet(GPIO_PRT_Type *base, uint32_t u32Pin)
{
    Cy_GPIO_Set(base,u32Pin);
}

void PortDriver_PinClear(GPIO_PRT_Type *base, uint32_t u32Pin)
{
    Cy_GPIO_Clr(base,u32Pin);
}

void PortDriver_PinToggle(GPIO_PRT_Type *base, uint32_t u32Pin)
{
    Cy_GPIO_Inv(base,u32Pin);
}