/*******************************************************************************
  PORT

  Company:
    AUO

  File Name:
    Port.c

  Version:
    1.00.02
  
  Summary:
    Interface definition of PORT PLIB

  Description:
    This file provides an interface to control and interact with PORT-I/O
    Pin controller module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "driver/inc/AdcDriver.h"

// *****************************************************************************
// *****************************************************************************
// Section: PORT Implementation
// *****************************************************************************
// *****************************************************************************

bool AdcDriver_Initial(SAR_Type* SAR, cy_stc_sar_config_t SAR_Config)
{
    bool bresult = true;
    cy_rslt_t result;
    /* Initialize the SAR ADC with the device configurator generated structure*/
    result = Cy_SAR_Init(SAR, &SAR_Config);
    if (result != CY_SAR_SUCCESS)
    {
        bresult = false;
    }
    /* Enable the SAR ADC */
    Cy_SAR_Enable(SAR);
    return bresult;
}

void AdcDriver_Enable(SAR_Type* SAR)
{
    Cy_SAR_Enable(SAR);
}

void AdcDriver_Disable(SAR_Type* SAR)
{
    Cy_SAR_Disable(SAR);
}

#if 0
void AdcDriver_ChannelSelect( uint16_t positiveInput, uint16_t negativeInput )
{
    ADC0_ChannelSelect(positiveInput,negativeInput);
}
#endif

static void AdcDriver_ConversionStart(SAR_Type* SAR)
{
    Cy_SAR_StartConvert(SAR, CY_SAR_START_CONVERT_SINGLE_SHOT);
}

static bool AdcDriver_ConversionSequenceIsFinished(SAR_Type* SAR)
{
    bool bresult = true;
    cy_en_sar_status_t result;
    result = Cy_SAR_IsEndConversion(SAR, CY_SAR_WAIT_FOR_RESULT);
    if(result != CY_SAR_SUCCESS)
    {
        bresult = false;
    }
    return bresult;
}

static uint16_t AdcDriver_ConversionResultGet(SAR_Type* SAR, uint32_t channel)
{
    return Cy_SAR_GetResult16(SAR, channel);
}

#if 0
bool AdcDriver_ConversionStatusGet(void)
{
    return ADC0_ConversionStatusGet();
}
#endif

uint16_t AdcDriver_ChannelResultGet(SAR_Type* SAR, uint16_t channel)
{
    uint32_t u32debounce = 0UL;
    AdcDriver_Enable(SAR);
    AdcDriver_ConversionStart(SAR);
    while((true != AdcDriver_ConversionSequenceIsFinished(SAR)) && (u32debounce < 11154U))
    {
        u32debounce += 1UL;
    }
    return AdcDriver_ConversionResultGet(SAR, channel);
}
/* *****************************************************************************
 End of File
 */
