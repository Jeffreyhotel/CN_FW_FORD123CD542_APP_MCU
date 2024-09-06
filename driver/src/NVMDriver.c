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

#include "driver/inc/NVMDriver.h"

// *****************************************************************************
// *****************************************************************************
// Section: PORT Implementation
// *****************************************************************************
// *****************************************************************************

static uint8_t u8FlashCache[SIZE_ROW];

bool NVMDriver_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    uint32_t *paddress = (uint32_t*)address;
    (void)memcpy(data, paddress, length);
    return true;
}

cy_en_flashdrv_status_t NVMDriver_PageWrite( uint8_t *u8data, const uint32_t u32address)
{
    cy_en_flashdrv_status_t tResult;
    (void)memcpy((void *)u8FlashCache, (void *) FLASH_ROW_ADDRESS( u32address ), SIZE_ROW);
    (void)memcpy(u8FlashCache, u8data, SIZE_ROW);
    
    tResult = Cy_Flash_WriteRow(u32address, (uint32_t *)u8FlashCache);
    return tResult;
}

bool NVMDriver_RowErase(uint32_t address)
{
    uint32_t data[CY_FLASH_SIZEOF_ROW / sizeof(uint32_t)];
    bool bresult = true;
    memset(data, 0xFF, CY_FLASH_SIZEOF_ROW);
    if( Cy_Flash_WriteRow(address,data) == CY_FLASH_DRV_SUCCESS)
    {
        bresult = true;
    }else{
        bresult = false;
    }
    return bresult;
}

#if 0
bool NVMDriver_IsBusy(void)
{
    bool bresult = true;
    /* Need to check the warning information*/
    if (Cy_Flash_IsOperationComplete() == (int)CY_FLASH_DRV_PROGRESS_NO_ERROR )
    {
        bresult = true;
    }else{
        bresult = false;
    }
    return bresult;
}
#endif
/* *****************************************************************************
 End of File
 */
