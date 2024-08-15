/*******************************************************************************
 * File Name: cycfg_pins.c
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.20.0
 * device-db 4.16.0.6098
 * mtb-pdl-cat2 2.11.0.12518
 *
 *******************************************************************************
 * Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t PCBA_A0_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = PCBA_A0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t PCBA_A0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PCBA_A0_PORT_NUM,
    .channel_num = PCBA_A0_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t PCBA_A1_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = PCBA_A1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t PCBA_A1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PCBA_A1_PORT_NUM,
    .channel_num = PCBA_A1_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t PCBA_A2_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = PCBA_A2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t PCBA_A2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PCBA_A2_PORT_NUM,
    .channel_num = PCBA_A2_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t PCBA_A3_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = PCBA_A3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t PCBA_A3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PCBA_A3_PORT_NUM,
    .channel_num = PCBA_A3_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t RTC_WCO_IN_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = RTC_WCO_IN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t RTC_WCO_IN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = RTC_WCO_IN_PORT_NUM,
    .channel_num = RTC_WCO_IN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t RTC_WCO_OUT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = RTC_WCO_OUT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t RTC_WCO_OUT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = RTC_WCO_OUT_PORT_NUM,
    .channel_num = RTC_WCO_OUT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t P1V2_EN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = P1V2_EN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t P1V2_EN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = P1V2_EN_PORT_NUM,
    .channel_num = P1V2_EN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t P1V2_PG_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = P1V2_PG_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t P1V2_PG_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = P1V2_PG_PORT_NUM,
    .channel_num = P1V2_PG_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t BIAS_FAULT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = BIAS_FAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t BIAS_FAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = BIAS_FAULT_PORT_NUM,
    .channel_num = BIAS_FAULT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t BIAS_EN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = BIAS_EN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t BIAS_EN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = BIAS_EN_PORT_NUM,
    .channel_num = BIAS_EN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_I2C_SCL_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_OD_DRIVESLOW,
    .hsiom = DES_I2C_SCL_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_I2C_SCL_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_I2C_SCL_PORT_NUM,
    .channel_num = DES_I2C_SCL_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_I2C_SDA_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_OD_DRIVESLOW,
    .hsiom = DES_I2C_SDA_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_I2C_SDA_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_I2C_SDA_PORT_NUM,
    .channel_num = DES_I2C_SDA_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_7_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = ioss_0_port_1_pin_7_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t ioss_0_port_1_pin_7_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_1_pin_7_PORT_NUM,
    .channel_num = ioss_0_port_1_pin_7_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t ADC_PCBTEMP_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = ADC_PCBTEMP_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t ADC_PCBTEMP_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ADC_PCBTEMP_PORT_NUM,
    .channel_num = ADC_PCBTEMP_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t ADC_BLTTEMP_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = ADC_BLTTEMP_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t ADC_BLTTEMP_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ADC_BLTTEMP_PORT_NUM,
    .channel_num = ADC_BLTTEMP_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t ADC_BATTVOLT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = ADC_BATTVOLT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t ADC_BATTVOLT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ADC_BATTVOLT_PORT_NUM,
    .channel_num = ADC_BATTVOLT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t SYNC_CHECK_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = SYNC_CHECK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t SYNC_CHECK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = SYNC_CHECK_PORT_NUM,
    .channel_num = SYNC_CHECK_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t FPCACHK_ROUT_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = FPCACHK_ROUT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t FPCACHK_ROUT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = FPCACHK_ROUT_PORT_NUM,
    .channel_num = FPCACHK_ROUT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t FPCACHK_RIN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = FPCACHK_RIN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t FPCACHK_RIN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = FPCACHK_RIN_PORT_NUM,
    .channel_num = FPCACHK_RIN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_LOCK_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = DES_LOCK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_LOCK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_LOCK_PORT_NUM,
    .channel_num = DES_LOCK_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_PASS_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = DES_PASS_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_PASS_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_PASS_PORT_NUM,
    .channel_num = DES_PASS_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t EXFLASH_WP_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = EXFLASH_WP_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t EXFLASH_WP_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = EXFLASH_WP_PORT_NUM,
    .channel_num = EXFLASH_WP_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DISP_FAULT_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = DISP_FAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DISP_FAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DISP_FAULT_PORT_NUM,
    .channel_num = DISP_FAULT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t MCU_SWDIO_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = MCU_SWDIO_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t MCU_SWDIO_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = MCU_SWDIO_PORT_NUM,
    .channel_num = MCU_SWDIO_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t MCU_SWCLK_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = MCU_SWCLK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t MCU_SWCLK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = MCU_SWCLK_PORT_NUM,
    .channel_num = MCU_SWCLK_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t FPCACHK_LOUT_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = FPCACHK_LOUT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t FPCACHK_LOUT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = FPCACHK_LOUT_PORT_NUM,
    .channel_num = FPCACHK_LOUT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t FPCACHK_LIN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = FPCACHK_LIN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t FPCACHK_LIN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = FPCACHK_LIN_PORT_NUM,
    .channel_num = FPCACHK_LIN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DDIC_WP_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLUP_IN_OFF,
    .hsiom = DDIC_WP_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DDIC_WP_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DDIC_WP_PORT_NUM,
    .channel_num = DDIC_WP_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t EXFLASH_SPI_SDI_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = EXFLASH_SPI_SDI_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t EXFLASH_SPI_SDI_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = EXFLASH_SPI_SDI_PORT_NUM,
    .channel_num = EXFLASH_SPI_SDI_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t EXFLASH_SPI_SDO_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = EXFLASH_SPI_SDO_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t EXFLASH_SPI_SDO_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = EXFLASH_SPI_SDO_PORT_NUM,
    .channel_num = EXFLASH_SPI_SDO_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t EXFLASH_SPI_SCK_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = EXFLASH_SPI_SCK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t EXFLASH_SPI_SCK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = EXFLASH_SPI_SCK_PORT_NUM,
    .channel_num = EXFLASH_SPI_SCK_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t EXFLASH_SPI_CS_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = EXFLASH_SPI_CS_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t EXFLASH_SPI_CS_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = EXFLASH_SPI_CS_PORT_NUM,
    .channel_num = EXFLASH_SPI_CS_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t P3V3_PG_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = P3V3_PG_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t P3V3_PG_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = P3V3_PG_PORT_NUM,
    .channel_num = P3V3_PG_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t P3V3_EN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = P3V3_EN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t P3V3_EN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = P3V3_EN_PORT_NUM,
    .channel_num = P3V3_EN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t VBATT_EN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = VBATT_EN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t VBATT_EN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = VBATT_EN_PORT_NUM,
    .channel_num = VBATT_EN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t LED_EN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = LED_EN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t LED_EN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = LED_EN_PORT_NUM,
    .channel_num = LED_EN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t HVLDO_EN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = HVLDO_EN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t HVLDO_EN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = HVLDO_EN_PORT_NUM,
    .channel_num = HVLDO_EN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_INTB_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLUP_IN_OFF,
    .hsiom = DES_INTB_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_INTB_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_INTB_PORT_NUM,
    .channel_num = DES_INTB_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_PDB_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = DES_PDB_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_PDB_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_PDB_PORT_NUM,
    .channel_num = DES_PDB_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t LED_DIM_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = LED_DIM_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t LED_DIM_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = LED_DIM_PORT_NUM,
    .channel_num = LED_DIM_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t LED_FAULT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = LED_FAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t LED_FAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = LED_FAULT_PORT_NUM,
    .channel_num = LED_FAULT_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DES_BISTEN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = DES_BISTEN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DES_BISTEN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DES_BISTEN_PORT_NUM,
    .channel_num = DES_BISTEN_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DISP_RESX_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = DISP_RESX_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DISP_RESX_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DISP_RESX_PORT_NUM,
    .channel_num = DISP_RESX_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t MCU_I2C_SCL_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_OD_DRIVESLOW,
    .hsiom = MCU_I2C_SCL_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t MCU_I2C_SCL_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = MCU_I2C_SCL_PORT_NUM,
    .channel_num = MCU_I2C_SCL_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t MCU_I2C_SDA_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_OD_DRIVESLOW,
    .hsiom = MCU_I2C_SDA_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t MCU_I2C_SDA_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = MCU_I2C_SDA_PORT_NUM,
    .channel_num = MCU_I2C_SDA_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DEBUG_UART_RX_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = DEBUG_UART_RX_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DEBUG_UART_RX_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DEBUG_UART_RX_PORT_NUM,
    .channel_num = DEBUG_UART_RX_PIN,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t DEBUG_UART_TX_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = DEBUG_UART_TX_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t DEBUG_UART_TX_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = DEBUG_UART_TX_PORT_NUM,
    .channel_num = DEBUG_UART_TX_PIN,
};
#endif /* defined (CY_USING_HAL) */

void init_cycfg_pins(void)
{
    Cy_GPIO_Pin_Init(PCBA_A0_PORT, PCBA_A0_PIN, &PCBA_A0_config);
    Cy_GPIO_Pin_Init(PCBA_A1_PORT, PCBA_A1_PIN, &PCBA_A1_config);
    Cy_GPIO_Pin_Init(PCBA_A2_PORT, PCBA_A2_PIN, &PCBA_A2_config);
    Cy_GPIO_Pin_Init(PCBA_A3_PORT, PCBA_A3_PIN, &PCBA_A3_config);
    Cy_GPIO_Pin_Init(RTC_WCO_IN_PORT, RTC_WCO_IN_PIN, &RTC_WCO_IN_config);
    Cy_GPIO_Pin_Init(RTC_WCO_OUT_PORT, RTC_WCO_OUT_PIN, &RTC_WCO_OUT_config);
    Cy_GPIO_Pin_Init(P1V2_EN_PORT, P1V2_EN_PIN, &P1V2_EN_config);
    Cy_GPIO_Pin_Init(P1V2_PG_PORT, P1V2_PG_PIN, &P1V2_PG_config);
    Cy_GPIO_Pin_Init(BIAS_FAULT_PORT, BIAS_FAULT_PIN, &BIAS_FAULT_config);
    Cy_GPIO_Pin_Init(BIAS_EN_PORT, BIAS_EN_PIN, &BIAS_EN_config);
    Cy_GPIO_Pin_Init(DES_I2C_SCL_PORT, DES_I2C_SCL_PIN, &DES_I2C_SCL_config);
    Cy_GPIO_Pin_Init(DES_I2C_SDA_PORT, DES_I2C_SDA_PIN, &DES_I2C_SDA_config);
    Cy_GPIO_Pin_Init(ioss_0_port_1_pin_7_PORT, ioss_0_port_1_pin_7_PIN, &ioss_0_port_1_pin_7_config);
    Cy_GPIO_Pin_Init(ADC_PCBTEMP_PORT, ADC_PCBTEMP_PIN, &ADC_PCBTEMP_config);
    Cy_GPIO_Pin_Init(ADC_BLTTEMP_PORT, ADC_BLTTEMP_PIN, &ADC_BLTTEMP_config);
    Cy_GPIO_Pin_Init(ADC_BATTVOLT_PORT, ADC_BATTVOLT_PIN, &ADC_BATTVOLT_config);
    Cy_GPIO_Pin_Init(SYNC_CHECK_PORT, SYNC_CHECK_PIN, &SYNC_CHECK_config);
    Cy_GPIO_Pin_Init(FPCACHK_ROUT_PORT, FPCACHK_ROUT_PIN, &FPCACHK_ROUT_config);
    Cy_GPIO_Pin_Init(FPCACHK_RIN_PORT, FPCACHK_RIN_PIN, &FPCACHK_RIN_config);
    Cy_GPIO_Pin_Init(DES_LOCK_PORT, DES_LOCK_PIN, &DES_LOCK_config);
    Cy_GPIO_Pin_Init(DES_PASS_PORT, DES_PASS_PIN, &DES_PASS_config);
    Cy_GPIO_Pin_Init(EXFLASH_WP_PORT, EXFLASH_WP_PIN, &EXFLASH_WP_config);
    Cy_GPIO_Pin_Init(DISP_FAULT_PORT, DISP_FAULT_PIN, &DISP_FAULT_config);
    Cy_GPIO_Pin_Init(MCU_SWDIO_PORT, MCU_SWDIO_PIN, &MCU_SWDIO_config);
    Cy_GPIO_Pin_Init(MCU_SWCLK_PORT, MCU_SWCLK_PIN, &MCU_SWCLK_config);
    Cy_GPIO_Pin_Init(FPCACHK_LOUT_PORT, FPCACHK_LOUT_PIN, &FPCACHK_LOUT_config);
    Cy_GPIO_Pin_Init(FPCACHK_LIN_PORT, FPCACHK_LIN_PIN, &FPCACHK_LIN_config);
    Cy_GPIO_Pin_Init(DDIC_WP_PORT, DDIC_WP_PIN, &DDIC_WP_config);
    Cy_GPIO_Pin_Init(EXFLASH_SPI_SDI_PORT, EXFLASH_SPI_SDI_PIN, &EXFLASH_SPI_SDI_config);
    Cy_GPIO_Pin_Init(EXFLASH_SPI_SDO_PORT, EXFLASH_SPI_SDO_PIN, &EXFLASH_SPI_SDO_config);
    Cy_GPIO_Pin_Init(EXFLASH_SPI_SCK_PORT, EXFLASH_SPI_SCK_PIN, &EXFLASH_SPI_SCK_config);
    Cy_GPIO_Pin_Init(EXFLASH_SPI_CS_PORT, EXFLASH_SPI_CS_PIN, &EXFLASH_SPI_CS_config);
    Cy_GPIO_Pin_Init(P3V3_PG_PORT, P3V3_PG_PIN, &P3V3_PG_config);
    Cy_GPIO_Pin_Init(P3V3_EN_PORT, P3V3_EN_PIN, &P3V3_EN_config);
    Cy_GPIO_Pin_Init(VBATT_EN_PORT, VBATT_EN_PIN, &VBATT_EN_config);
    Cy_GPIO_Pin_Init(LED_EN_PORT, LED_EN_PIN, &LED_EN_config);
    Cy_GPIO_Pin_Init(HVLDO_EN_PORT, HVLDO_EN_PIN, &HVLDO_EN_config);
    Cy_GPIO_Pin_Init(DES_INTB_PORT, DES_INTB_PIN, &DES_INTB_config);
    Cy_GPIO_Pin_Init(DES_PDB_PORT, DES_PDB_PIN, &DES_PDB_config);
    Cy_GPIO_Pin_Init(LED_DIM_PORT, LED_DIM_PIN, &LED_DIM_config);
    Cy_GPIO_Pin_Init(LED_FAULT_PORT, LED_FAULT_PIN, &LED_FAULT_config);
    Cy_GPIO_Pin_Init(DES_BISTEN_PORT, DES_BISTEN_PIN, &DES_BISTEN_config);
    Cy_GPIO_Pin_Init(DISP_RESX_PORT, DISP_RESX_PIN, &DISP_RESX_config);
    Cy_GPIO_Pin_Init(MCU_I2C_SCL_PORT, MCU_I2C_SCL_PIN, &MCU_I2C_SCL_config);
    Cy_GPIO_Pin_Init(MCU_I2C_SDA_PORT, MCU_I2C_SDA_PIN, &MCU_I2C_SDA_config);
    Cy_GPIO_Pin_Init(DEBUG_UART_RX_PORT, DEBUG_UART_RX_PIN, &DEBUG_UART_RX_config);
    Cy_GPIO_Pin_Init(DEBUG_UART_TX_PORT, DEBUG_UART_TX_PIN, &DEBUG_UART_TX_config);
}
void reserve_cycfg_pins(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&PCBA_A0_obj);
    cyhal_hwmgr_reserve(&PCBA_A1_obj);
    cyhal_hwmgr_reserve(&PCBA_A2_obj);
    cyhal_hwmgr_reserve(&PCBA_A3_obj);
    cyhal_hwmgr_reserve(&RTC_WCO_IN_obj);
    cyhal_hwmgr_reserve(&RTC_WCO_OUT_obj);
    cyhal_hwmgr_reserve(&P1V2_EN_obj);
    cyhal_hwmgr_reserve(&P1V2_PG_obj);
    cyhal_hwmgr_reserve(&BIAS_FAULT_obj);
    cyhal_hwmgr_reserve(&BIAS_EN_obj);
    cyhal_hwmgr_reserve(&DES_I2C_SCL_obj);
    cyhal_hwmgr_reserve(&DES_I2C_SDA_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_1_pin_7_obj);
    cyhal_hwmgr_reserve(&ADC_PCBTEMP_obj);
    cyhal_hwmgr_reserve(&ADC_BLTTEMP_obj);
    cyhal_hwmgr_reserve(&ADC_BATTVOLT_obj);
    cyhal_hwmgr_reserve(&SYNC_CHECK_obj);
    cyhal_hwmgr_reserve(&FPCACHK_ROUT_obj);
    cyhal_hwmgr_reserve(&FPCACHK_RIN_obj);
    cyhal_hwmgr_reserve(&DES_LOCK_obj);
    cyhal_hwmgr_reserve(&DES_PASS_obj);
    cyhal_hwmgr_reserve(&EXFLASH_WP_obj);
    cyhal_hwmgr_reserve(&DISP_FAULT_obj);
    cyhal_hwmgr_reserve(&MCU_SWDIO_obj);
    cyhal_hwmgr_reserve(&MCU_SWCLK_obj);
    cyhal_hwmgr_reserve(&FPCACHK_LOUT_obj);
    cyhal_hwmgr_reserve(&FPCACHK_LIN_obj);
    cyhal_hwmgr_reserve(&DDIC_WP_obj);
    cyhal_hwmgr_reserve(&EXFLASH_SPI_SDI_obj);
    cyhal_hwmgr_reserve(&EXFLASH_SPI_SDO_obj);
    cyhal_hwmgr_reserve(&EXFLASH_SPI_SCK_obj);
    cyhal_hwmgr_reserve(&EXFLASH_SPI_CS_obj);
    cyhal_hwmgr_reserve(&P3V3_PG_obj);
    cyhal_hwmgr_reserve(&P3V3_EN_obj);
    cyhal_hwmgr_reserve(&VBATT_EN_obj);
    cyhal_hwmgr_reserve(&LED_EN_obj);
    cyhal_hwmgr_reserve(&HVLDO_EN_obj);
    cyhal_hwmgr_reserve(&DES_INTB_obj);
    cyhal_hwmgr_reserve(&DES_PDB_obj);
    cyhal_hwmgr_reserve(&LED_DIM_obj);
    cyhal_hwmgr_reserve(&LED_FAULT_obj);
    cyhal_hwmgr_reserve(&DES_BISTEN_obj);
    cyhal_hwmgr_reserve(&DISP_RESX_obj);
    cyhal_hwmgr_reserve(&MCU_I2C_SCL_obj);
    cyhal_hwmgr_reserve(&MCU_I2C_SDA_obj);
    cyhal_hwmgr_reserve(&DEBUG_UART_RX_obj);
    cyhal_hwmgr_reserve(&DEBUG_UART_TX_obj);
#endif /* defined (CY_USING_HAL) */
}
