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

#include "driver/inc/I2C2SDriver.h"
#include "app/inc/RegisterApp.h"




cy_stc_scb_i2c_context_t SCB_I2C2S_IRQ_context;

/* CYBSP_I2C_SCB_IRQ */
const cy_stc_sysint_t SCB_I2C2S_IRQ_config = {
        .intrSrc = (IRQn_Type) SCB_I2C2S_IRQ,
        .intrPriority = 2u
};

static void I2C2SDriver_InterruptHandler(void)
{
    /* ISR implementation for I2C */
    Cy_SCB_I2C_SlaveInterrupt(SCB_I2C2S_HW, &SCB_I2C2S_IRQ_context);
}

uint32_t I2C2SDriver_GetTxWriteTransferCount(void)
{
    return Cy_SCB_I2C_SlaveGetWriteTransferCount(SCB_I2C2S_HW,&SCB_I2C2S_IRQ_context);
}

uint32_t I2C2SDriver_GetTxReadTransferCount(void)
{
    return Cy_SCB_I2C_SlaveGetReadTransferCount(SCB_I2C2S_HW,&SCB_I2C2S_IRQ_context);
}

void I2C2SDriver_ConfigRxBuff(uint8_t ReadBuffer[])
{
    /* Configure read buffer */
    Cy_SCB_I2C_SlaveConfigReadBuf(SCB_I2C2S_HW, ReadBuffer,
                                    SL_RD_BUFFER_SIZE, &SCB_I2C2S_IRQ_context);
}

void I2C2SDriver_ConfigTxBuff(uint8_t WriteBuffer[])
{
    /* Configure write buffer */
    Cy_SCB_I2C_SlaveConfigWriteBuf(SCB_I2C2S_HW, WriteBuffer,
                                    SL_WR_BUFFER_SIZE, &SCB_I2C2S_IRQ_context);
}

void I2C2SDriver_RegisterCallback(cy_cb_scb_i2c_handle_events_t callback)
{
    /* Register Callback function for interrupt */
    Cy_SCB_I2C_RegisterEventCallback(SCB_I2C2S_HW,callback,&SCB_I2C2S_IRQ_context);
}

void I2C2SDriver_Enable(void)
{
    /*  Enable interrupt and I2C block */
    NVIC_EnableIRQ((IRQn_Type) SCB_I2C2S_IRQ_config.intrSrc);
    Cy_SCB_I2C_Enable(SCB_I2C2S_HW, &SCB_I2C2S_IRQ_context);
}

bool I2C2SDriver_Initial(void)
{
    bool bresult = true;
    cy_rslt_t result;
    /* Initialize and enable I2C Component in slave mode.
     * If initialization fails process error
     */
    result = Cy_SCB_I2C_Init(SCB_I2C2S_HW, &SCB_I2C2S_config,
                            &SCB_I2C2S_IRQ_context);
    if(result != CY_SCB_I2C_SUCCESS)
    {
        bresult = false;
    }

    result = Cy_SysInt_Init(&SCB_I2C2S_IRQ_config, &I2C2SDriver_InterruptHandler);
    if(result != CY_SYSINT_SUCCESS)
    {
        bresult = false;
    }

#if 0
    /* Configure read buffer */
    Cy_SCB_I2C_SlaveConfigReadBuf(SCB_I2C2S_HW, i2cReadBuffer,
                                    SL_RD_BUFFER_SIZE, &SCB_I2C2S_IRQ_context);

    /* Configure write buffer */
    Cy_SCB_I2C_SlaveConfigWriteBuf(SCB_I2C2S_HW, i2cWriteBuffer,
                                    SL_WR_BUFFER_SIZE, &SCB_I2C2S_IRQ_context);

    /* Register Callback function for interrupt */
    Cy_SCB_I2C_RegisterEventCallback(SCB_I2C2S_HW,
                                    (cy_cb_scb_i2c_handle_events_t) SlaveCallback,
                                    &SCB_I2C2S_IRQ_context);

    /*  Enable interrupt and I2C block */
    NVIC_EnableIRQ((IRQn_Type) SCB_I2C2S_IRQ_config.intrSrc);
    Cy_SCB_I2C_Enable(SCB_I2C2S_HW, &SCB_I2C2S_IRQ_context);
#endif

    return bresult;
}

/* *****************************************************************************
 End of File
 */
