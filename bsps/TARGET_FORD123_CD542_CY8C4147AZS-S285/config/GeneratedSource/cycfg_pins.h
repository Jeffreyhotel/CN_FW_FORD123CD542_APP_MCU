/*******************************************************************************
 * File Name: cycfg_pins.h
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define PCBA_A0_ENABLED 1U
#define PCBA_A0_PORT GPIO_PRT0
#define PCBA_A0_PORT_NUM 0U
#define PCBA_A0_PIN 0U
#define PCBA_A0_NUM 0U
#define PCBA_A0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define PCBA_A0_INIT_DRIVESTATE 0
#ifndef ioss_0_port_0_pin_0_HSIOM
    #define ioss_0_port_0_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PCBA_A0_HSIOM ioss_0_port_0_pin_0_HSIOM
#define PCBA_A0_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define PCBA_A0_HAL_PORT_PIN P0_0
#define PCBA_A0 P0_0
#define PCBA_A0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PCBA_A0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define PCBA_A0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define PCBA_A1_ENABLED 1U
#define PCBA_A1_PORT GPIO_PRT0
#define PCBA_A1_PORT_NUM 0U
#define PCBA_A1_PIN 1U
#define PCBA_A1_NUM 1U
#define PCBA_A1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define PCBA_A1_INIT_DRIVESTATE 0
#ifndef ioss_0_port_0_pin_1_HSIOM
    #define ioss_0_port_0_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define PCBA_A1_HSIOM ioss_0_port_0_pin_1_HSIOM
#define PCBA_A1_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define PCBA_A1_HAL_PORT_PIN P0_1
#define PCBA_A1 P0_1
#define PCBA_A1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PCBA_A1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define PCBA_A1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define PCBA_A2_ENABLED 1U
#define PCBA_A2_PORT GPIO_PRT0
#define PCBA_A2_PORT_NUM 0U
#define PCBA_A2_PIN 2U
#define PCBA_A2_NUM 2U
#define PCBA_A2_DRIVEMODE CY_GPIO_DM_HIGHZ
#define PCBA_A2_INIT_DRIVESTATE 0
#ifndef ioss_0_port_0_pin_2_HSIOM
    #define ioss_0_port_0_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define PCBA_A2_HSIOM ioss_0_port_0_pin_2_HSIOM
#define PCBA_A2_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define PCBA_A2_HAL_PORT_PIN P0_2
#define PCBA_A2 P0_2
#define PCBA_A2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PCBA_A2_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define PCBA_A2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define PCBA_A3_ENABLED 1U
#define PCBA_A3_PORT GPIO_PRT0
#define PCBA_A3_PORT_NUM 0U
#define PCBA_A3_PIN 3U
#define PCBA_A3_NUM 3U
#define PCBA_A3_DRIVEMODE CY_GPIO_DM_HIGHZ
#define PCBA_A3_INIT_DRIVESTATE 0
#ifndef ioss_0_port_0_pin_3_HSIOM
    #define ioss_0_port_0_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define PCBA_A3_HSIOM ioss_0_port_0_pin_3_HSIOM
#define PCBA_A3_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define PCBA_A3_HAL_PORT_PIN P0_3
#define PCBA_A3 P0_3
#define PCBA_A3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PCBA_A3_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define PCBA_A3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define RTC_WCO_IN_ENABLED 1U
#define RTC_WCO_IN_PORT GPIO_PRT0
#define RTC_WCO_IN_PORT_NUM 0U
#define RTC_WCO_IN_PIN 4U
#define RTC_WCO_IN_NUM 4U
#define RTC_WCO_IN_DRIVEMODE CY_GPIO_DM_ANALOG
#define RTC_WCO_IN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_4_HSIOM
    #define ioss_0_port_0_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define RTC_WCO_IN_HSIOM ioss_0_port_0_pin_4_HSIOM
#define RTC_WCO_IN_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define RTC_WCO_IN_HAL_PORT_PIN P0_4
#define RTC_WCO_IN P0_4
#define RTC_WCO_IN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define RTC_WCO_IN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define RTC_WCO_IN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define RTC_WCO_OUT_ENABLED 1U
#define RTC_WCO_OUT_PORT GPIO_PRT0
#define RTC_WCO_OUT_PORT_NUM 0U
#define RTC_WCO_OUT_PIN 5U
#define RTC_WCO_OUT_NUM 5U
#define RTC_WCO_OUT_DRIVEMODE CY_GPIO_DM_ANALOG
#define RTC_WCO_OUT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_5_HSIOM
    #define ioss_0_port_0_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define RTC_WCO_OUT_HSIOM ioss_0_port_0_pin_5_HSIOM
#define RTC_WCO_OUT_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define RTC_WCO_OUT_HAL_PORT_PIN P0_5
#define RTC_WCO_OUT P0_5
#define RTC_WCO_OUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define RTC_WCO_OUT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define RTC_WCO_OUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define P1V2_EN_ENABLED 1U
#define P1V2_EN_PORT GPIO_PRT0
#define P1V2_EN_PORT_NUM 0U
#define P1V2_EN_PIN 6U
#define P1V2_EN_NUM 6U
#define P1V2_EN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define P1V2_EN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_0_pin_6_HSIOM
    #define ioss_0_port_0_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define P1V2_EN_HSIOM ioss_0_port_0_pin_6_HSIOM
#define P1V2_EN_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define P1V2_EN_HAL_PORT_PIN P0_6
#define P1V2_EN P0_6
#define P1V2_EN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define P1V2_EN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define P1V2_EN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define P1V2_PG_ENABLED 1U
#define P1V2_PG_PORT GPIO_PRT0
#define P1V2_PG_PORT_NUM 0U
#define P1V2_PG_PIN 7U
#define P1V2_PG_NUM 7U
#define P1V2_PG_DRIVEMODE CY_GPIO_DM_HIGHZ
#define P1V2_PG_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_7_HSIOM
    #define ioss_0_port_0_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define P1V2_PG_HSIOM ioss_0_port_0_pin_7_HSIOM
#define P1V2_PG_IRQ ioss_interrupts_gpio_0_IRQn

#if defined (CY_USING_HAL)
#define P1V2_PG_HAL_PORT_PIN P0_7
#define P1V2_PG P0_7
#define P1V2_PG_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define P1V2_PG_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define P1V2_PG_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define BIAS_FAULT_ENABLED 1U
#define BIAS_FAULT_PORT GPIO_PRT1
#define BIAS_FAULT_PORT_NUM 1U
#define BIAS_FAULT_PIN 0U
#define BIAS_FAULT_NUM 0U
#define BIAS_FAULT_DRIVEMODE CY_GPIO_DM_HIGHZ
#define BIAS_FAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_0_HSIOM
    #define ioss_0_port_1_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define BIAS_FAULT_HSIOM ioss_0_port_1_pin_0_HSIOM
#define BIAS_FAULT_IRQ ioss_interrupts_gpio_1_IRQn

#if defined (CY_USING_HAL)
#define BIAS_FAULT_HAL_PORT_PIN P1_0
#define BIAS_FAULT P1_0
#define BIAS_FAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define BIAS_FAULT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define BIAS_FAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define BIAS_EN_ENABLED 1U
#define BIAS_EN_PORT GPIO_PRT1
#define BIAS_EN_PORT_NUM 1U
#define BIAS_EN_PIN 1U
#define BIAS_EN_NUM 1U
#define BIAS_EN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define BIAS_EN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_1_pin_1_HSIOM
    #define ioss_0_port_1_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define BIAS_EN_HSIOM ioss_0_port_1_pin_1_HSIOM
#define BIAS_EN_IRQ ioss_interrupts_gpio_1_IRQn

#if defined (CY_USING_HAL)
#define BIAS_EN_HAL_PORT_PIN P1_1
#define BIAS_EN P1_1
#define BIAS_EN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define BIAS_EN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define BIAS_EN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define DES_I2C_SCL_ENABLED 1U
#define DES_I2C_SCL_PORT GPIO_PRT1
#define DES_I2C_SCL_PORT_NUM 1U
#define DES_I2C_SCL_PIN 2U
#define DES_I2C_SCL_NUM 2U
#define DES_I2C_SCL_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define DES_I2C_SCL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_2_HSIOM
    #define ioss_0_port_1_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_I2C_SCL_HSIOM ioss_0_port_1_pin_2_HSIOM
#define DES_I2C_SCL_IRQ ioss_interrupts_gpio_1_IRQn

#if defined (CY_USING_HAL)
#define DES_I2C_SCL_HAL_PORT_PIN P1_2
#define DES_I2C_SCL P1_2
#define DES_I2C_SCL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_I2C_SCL_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define DES_I2C_SCL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_OPENDRAINDRIVESLOW
#endif /* defined (CY_USING_HAL) */

#define DES_I2C_SDA_ENABLED 1U
#define DES_I2C_SDA_PORT GPIO_PRT1
#define DES_I2C_SDA_PORT_NUM 1U
#define DES_I2C_SDA_PIN 3U
#define DES_I2C_SDA_NUM 3U
#define DES_I2C_SDA_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define DES_I2C_SDA_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_3_HSIOM
    #define ioss_0_port_1_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_I2C_SDA_HSIOM ioss_0_port_1_pin_3_HSIOM
#define DES_I2C_SDA_IRQ ioss_interrupts_gpio_1_IRQn

#if defined (CY_USING_HAL)
#define DES_I2C_SDA_HAL_PORT_PIN P1_3
#define DES_I2C_SDA P1_3
#define DES_I2C_SDA_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_I2C_SDA_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define DES_I2C_SDA_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_OPENDRAINDRIVESLOW
#endif /* defined (CY_USING_HAL) */

#define ioss_0_port_1_pin_7_ENABLED 1U
#define ioss_0_port_1_pin_7_PORT GPIO_PRT1
#define ioss_0_port_1_pin_7_PORT_NUM 1U
#define ioss_0_port_1_pin_7_PIN 7U
#define ioss_0_port_1_pin_7_NUM 7U
#define ioss_0_port_1_pin_7_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_1_pin_7_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_7_HSIOM
    #define ioss_0_port_1_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_7_IRQ ioss_interrupts_gpio_1_IRQn

#if defined (CY_USING_HAL)
#define ioss_0_port_1_pin_7_HAL_PORT_PIN P1_7
#define ioss_0_port_1_pin_7 P1_7
#define ioss_0_port_1_pin_7_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_1_pin_7_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_1_pin_7_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define ADC_BLTTEMP_ENABLED 1U
#define ADC_BLTTEMP_PORT GPIO_PRT2
#define ADC_BLTTEMP_PORT_NUM 2U
#define ADC_BLTTEMP_PIN 0U
#define ADC_BLTTEMP_NUM 0U
#define ADC_BLTTEMP_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_BLTTEMP_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_0_HSIOM
    #define ioss_0_port_2_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_BLTTEMP_HSIOM ioss_0_port_2_pin_0_HSIOM
#define ADC_BLTTEMP_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define ADC_BLTTEMP_HAL_PORT_PIN P2_0
#define ADC_BLTTEMP P2_0
#define ADC_BLTTEMP_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ADC_BLTTEMP_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ADC_BLTTEMP_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define ADC_PCBTEMP_ENABLED 1U
#define ADC_PCBTEMP_PORT GPIO_PRT2
#define ADC_PCBTEMP_PORT_NUM 2U
#define ADC_PCBTEMP_PIN 1U
#define ADC_PCBTEMP_NUM 1U
#define ADC_PCBTEMP_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_PCBTEMP_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_1_HSIOM
    #define ioss_0_port_2_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_PCBTEMP_HSIOM ioss_0_port_2_pin_1_HSIOM
#define ADC_PCBTEMP_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define ADC_PCBTEMP_HAL_PORT_PIN P2_1
#define ADC_PCBTEMP P2_1
#define ADC_PCBTEMP_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ADC_PCBTEMP_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ADC_PCBTEMP_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define ADC_BATTVOLT_ENABLED 1U
#define ADC_BATTVOLT_PORT GPIO_PRT2
#define ADC_BATTVOLT_PORT_NUM 2U
#define ADC_BATTVOLT_PIN 2U
#define ADC_BATTVOLT_NUM 2U
#define ADC_BATTVOLT_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_BATTVOLT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_2_HSIOM
    #define ioss_0_port_2_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_BATTVOLT_HSIOM ioss_0_port_2_pin_2_HSIOM
#define ADC_BATTVOLT_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define ADC_BATTVOLT_HAL_PORT_PIN P2_2
#define ADC_BATTVOLT P2_2
#define ADC_BATTVOLT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ADC_BATTVOLT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ADC_BATTVOLT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) */

#define SYNC_CHECK_ENABLED 1U
#define SYNC_CHECK_PORT GPIO_PRT2
#define SYNC_CHECK_PORT_NUM 2U
#define SYNC_CHECK_PIN 3U
#define SYNC_CHECK_NUM 3U
#define SYNC_CHECK_DRIVEMODE CY_GPIO_DM_HIGHZ
#define SYNC_CHECK_INIT_DRIVESTATE 0
#ifndef ioss_0_port_2_pin_3_HSIOM
    #define ioss_0_port_2_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define SYNC_CHECK_HSIOM ioss_0_port_2_pin_3_HSIOM
#define SYNC_CHECK_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define SYNC_CHECK_HAL_PORT_PIN P2_3
#define SYNC_CHECK P2_3
#define SYNC_CHECK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define SYNC_CHECK_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define SYNC_CHECK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define FPCACHK_ROUT_ENABLED 1U
#define FPCACHK_ROUT_PORT GPIO_PRT2
#define FPCACHK_ROUT_PORT_NUM 2U
#define FPCACHK_ROUT_PIN 4U
#define FPCACHK_ROUT_NUM 4U
#define FPCACHK_ROUT_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FPCACHK_ROUT_INIT_DRIVESTATE 0
#ifndef ioss_0_port_2_pin_4_HSIOM
    #define ioss_0_port_2_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define FPCACHK_ROUT_HSIOM ioss_0_port_2_pin_4_HSIOM
#define FPCACHK_ROUT_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define FPCACHK_ROUT_HAL_PORT_PIN P2_4
#define FPCACHK_ROUT P2_4
#define FPCACHK_ROUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define FPCACHK_ROUT_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define FPCACHK_ROUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define FPCACHK_RIN_ENABLED 1U
#define FPCACHK_RIN_PORT GPIO_PRT2
#define FPCACHK_RIN_PORT_NUM 2U
#define FPCACHK_RIN_PIN 5U
#define FPCACHK_RIN_NUM 5U
#define FPCACHK_RIN_DRIVEMODE CY_GPIO_DM_HIGHZ
#define FPCACHK_RIN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_2_pin_5_HSIOM
    #define ioss_0_port_2_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define FPCACHK_RIN_HSIOM ioss_0_port_2_pin_5_HSIOM
#define FPCACHK_RIN_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define FPCACHK_RIN_HAL_PORT_PIN P2_5
#define FPCACHK_RIN P2_5
#define FPCACHK_RIN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define FPCACHK_RIN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define FPCACHK_RIN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define DES_LOCK_ENABLED 1U
#define DES_LOCK_PORT GPIO_PRT2
#define DES_LOCK_PORT_NUM 2U
#define DES_LOCK_PIN 6U
#define DES_LOCK_NUM 6U
#define DES_LOCK_DRIVEMODE CY_GPIO_DM_HIGHZ
#define DES_LOCK_INIT_DRIVESTATE 0
#ifndef ioss_0_port_2_pin_6_HSIOM
    #define ioss_0_port_2_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_LOCK_HSIOM ioss_0_port_2_pin_6_HSIOM
#define DES_LOCK_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define DES_LOCK_HAL_PORT_PIN P2_6
#define DES_LOCK P2_6
#define DES_LOCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_LOCK_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define DES_LOCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define DES_PASS_ENABLED 1U
#define DES_PASS_PORT GPIO_PRT2
#define DES_PASS_PORT_NUM 2U
#define DES_PASS_PIN 7U
#define DES_PASS_NUM 7U
#define DES_PASS_DRIVEMODE CY_GPIO_DM_HIGHZ
#define DES_PASS_INIT_DRIVESTATE 0
#ifndef ioss_0_port_2_pin_7_HSIOM
    #define ioss_0_port_2_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_PASS_HSIOM ioss_0_port_2_pin_7_HSIOM
#define DES_PASS_IRQ ioss_interrupts_gpio_2_IRQn

#if defined (CY_USING_HAL)
#define DES_PASS_HAL_PORT_PIN P2_7
#define DES_PASS P2_7
#define DES_PASS_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_PASS_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define DES_PASS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define EXFLASH_WP_ENABLED 1U
#define EXFLASH_WP_PORT GPIO_PRT3
#define EXFLASH_WP_PORT_NUM 3U
#define EXFLASH_WP_PIN 0U
#define EXFLASH_WP_NUM 0U
#define EXFLASH_WP_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define EXFLASH_WP_INIT_DRIVESTATE 0
#ifndef ioss_0_port_3_pin_0_HSIOM
    #define ioss_0_port_3_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define EXFLASH_WP_HSIOM ioss_0_port_3_pin_0_HSIOM
#define EXFLASH_WP_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define EXFLASH_WP_HAL_PORT_PIN P3_0
#define EXFLASH_WP P3_0
#define EXFLASH_WP_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define EXFLASH_WP_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define EXFLASH_WP_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define DISP_FAULT_ENABLED 1U
#define DISP_FAULT_PORT GPIO_PRT3
#define DISP_FAULT_PORT_NUM 3U
#define DISP_FAULT_PIN 1U
#define DISP_FAULT_NUM 1U
#define DISP_FAULT_DRIVEMODE CY_GPIO_DM_HIGHZ
#define DISP_FAULT_INIT_DRIVESTATE 0
#ifndef ioss_0_port_3_pin_1_HSIOM
    #define ioss_0_port_3_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define DISP_FAULT_HSIOM ioss_0_port_3_pin_1_HSIOM
#define DISP_FAULT_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define DISP_FAULT_HAL_PORT_PIN P3_1
#define DISP_FAULT P3_1
#define DISP_FAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DISP_FAULT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define DISP_FAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define MCU_SWDIO_ENABLED 1U
#define MCU_SWDIO_PORT GPIO_PRT3
#define MCU_SWDIO_PORT_NUM 3U
#define MCU_SWDIO_PIN 2U
#define MCU_SWDIO_NUM 2U
#define MCU_SWDIO_DRIVEMODE CY_GPIO_DM_STRONG
#define MCU_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_2_HSIOM
    #define ioss_0_port_3_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define MCU_SWDIO_HSIOM ioss_0_port_3_pin_2_HSIOM
#define MCU_SWDIO_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define MCU_SWDIO_HAL_PORT_PIN P3_2
#define MCU_SWDIO P3_2
#define MCU_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define MCU_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define MCU_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define MCU_SWCLK_ENABLED 1U
#define MCU_SWCLK_PORT GPIO_PRT3
#define MCU_SWCLK_PORT_NUM 3U
#define MCU_SWCLK_PIN 3U
#define MCU_SWCLK_NUM 3U
#define MCU_SWCLK_DRIVEMODE CY_GPIO_DM_STRONG
#define MCU_SWCLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_3_HSIOM
    #define ioss_0_port_3_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define MCU_SWCLK_HSIOM ioss_0_port_3_pin_3_HSIOM
#define MCU_SWCLK_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define MCU_SWCLK_HAL_PORT_PIN P3_3
#define MCU_SWCLK P3_3
#define MCU_SWCLK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define MCU_SWCLK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define MCU_SWCLK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define FPCACHK_LOUT_ENABLED 1U
#define FPCACHK_LOUT_PORT GPIO_PRT3
#define FPCACHK_LOUT_PORT_NUM 3U
#define FPCACHK_LOUT_PIN 4U
#define FPCACHK_LOUT_NUM 4U
#define FPCACHK_LOUT_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FPCACHK_LOUT_INIT_DRIVESTATE 0
#ifndef ioss_0_port_3_pin_4_HSIOM
    #define ioss_0_port_3_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define FPCACHK_LOUT_HSIOM ioss_0_port_3_pin_4_HSIOM
#define FPCACHK_LOUT_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define FPCACHK_LOUT_HAL_PORT_PIN P3_4
#define FPCACHK_LOUT P3_4
#define FPCACHK_LOUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define FPCACHK_LOUT_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define FPCACHK_LOUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define FPCACHK_LIN_ENABLED 1U
#define FPCACHK_LIN_PORT GPIO_PRT3
#define FPCACHK_LIN_PORT_NUM 3U
#define FPCACHK_LIN_PIN 5U
#define FPCACHK_LIN_NUM 5U
#define FPCACHK_LIN_DRIVEMODE CY_GPIO_DM_HIGHZ
#define FPCACHK_LIN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_3_pin_5_HSIOM
    #define ioss_0_port_3_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define FPCACHK_LIN_HSIOM ioss_0_port_3_pin_5_HSIOM
#define FPCACHK_LIN_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define FPCACHK_LIN_HAL_PORT_PIN P3_5
#define FPCACHK_LIN P3_5
#define FPCACHK_LIN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define FPCACHK_LIN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define FPCACHK_LIN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define DDIC_WP_ENABLED 1U
#define DDIC_WP_PORT GPIO_PRT3
#define DDIC_WP_PORT_NUM 3U
#define DDIC_WP_PIN 6U
#define DDIC_WP_NUM 6U
#define DDIC_WP_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DDIC_WP_INIT_DRIVESTATE 0
#ifndef ioss_0_port_3_pin_6_HSIOM
    #define ioss_0_port_3_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define DDIC_WP_HSIOM ioss_0_port_3_pin_6_HSIOM
#define DDIC_WP_IRQ ioss_interrupts_gpio_3_IRQn

#if defined (CY_USING_HAL)
#define DDIC_WP_HAL_PORT_PIN P3_6
#define DDIC_WP P3_6
#define DDIC_WP_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DDIC_WP_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define DDIC_WP_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define EXFLASH_SPI_SDI_ENABLED 1U
#define EXFLASH_SPI_SDI_PORT GPIO_PRT4
#define EXFLASH_SPI_SDI_PORT_NUM 4U
#define EXFLASH_SPI_SDI_PIN 0U
#define EXFLASH_SPI_SDI_NUM 0U
#define EXFLASH_SPI_SDI_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define EXFLASH_SPI_SDI_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_0_HSIOM
    #define ioss_0_port_4_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define EXFLASH_SPI_SDI_HSIOM ioss_0_port_4_pin_0_HSIOM
#define EXFLASH_SPI_SDI_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define EXFLASH_SPI_SDI_HAL_PORT_PIN P4_0
#define EXFLASH_SPI_SDI P4_0
#define EXFLASH_SPI_SDI_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define EXFLASH_SPI_SDI_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define EXFLASH_SPI_SDI_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define EXFLASH_SPI_SDO_ENABLED 1U
#define EXFLASH_SPI_SDO_PORT GPIO_PRT4
#define EXFLASH_SPI_SDO_PORT_NUM 4U
#define EXFLASH_SPI_SDO_PIN 1U
#define EXFLASH_SPI_SDO_NUM 1U
#define EXFLASH_SPI_SDO_DRIVEMODE CY_GPIO_DM_HIGHZ
#define EXFLASH_SPI_SDO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_1_HSIOM
    #define ioss_0_port_4_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define EXFLASH_SPI_SDO_HSIOM ioss_0_port_4_pin_1_HSIOM
#define EXFLASH_SPI_SDO_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define EXFLASH_SPI_SDO_HAL_PORT_PIN P4_1
#define EXFLASH_SPI_SDO P4_1
#define EXFLASH_SPI_SDO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define EXFLASH_SPI_SDO_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define EXFLASH_SPI_SDO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define EXFLASH_SPI_SCK_ENABLED 1U
#define EXFLASH_SPI_SCK_PORT GPIO_PRT4
#define EXFLASH_SPI_SCK_PORT_NUM 4U
#define EXFLASH_SPI_SCK_PIN 2U
#define EXFLASH_SPI_SCK_NUM 2U
#define EXFLASH_SPI_SCK_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define EXFLASH_SPI_SCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_2_HSIOM
    #define ioss_0_port_4_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define EXFLASH_SPI_SCK_HSIOM ioss_0_port_4_pin_2_HSIOM
#define EXFLASH_SPI_SCK_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define EXFLASH_SPI_SCK_HAL_PORT_PIN P4_2
#define EXFLASH_SPI_SCK P4_2
#define EXFLASH_SPI_SCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define EXFLASH_SPI_SCK_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define EXFLASH_SPI_SCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define EXFLASH_SPI_CS_ENABLED 1U
#define EXFLASH_SPI_CS_PORT GPIO_PRT4
#define EXFLASH_SPI_CS_PORT_NUM 4U
#define EXFLASH_SPI_CS_PIN 3U
#define EXFLASH_SPI_CS_NUM 3U
#define EXFLASH_SPI_CS_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define EXFLASH_SPI_CS_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_3_HSIOM
    #define ioss_0_port_4_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define EXFLASH_SPI_CS_HSIOM ioss_0_port_4_pin_3_HSIOM
#define EXFLASH_SPI_CS_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define EXFLASH_SPI_CS_HAL_PORT_PIN P4_3
#define EXFLASH_SPI_CS P4_3
#define EXFLASH_SPI_CS_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define EXFLASH_SPI_CS_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define EXFLASH_SPI_CS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define P3V3_PG_ENABLED 1U
#define P3V3_PG_PORT GPIO_PRT4
#define P3V3_PG_PORT_NUM 4U
#define P3V3_PG_PIN 4U
#define P3V3_PG_NUM 4U
#define P3V3_PG_DRIVEMODE CY_GPIO_DM_HIGHZ
#define P3V3_PG_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_4_HSIOM
    #define ioss_0_port_4_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define P3V3_PG_HSIOM ioss_0_port_4_pin_4_HSIOM
#define P3V3_PG_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define P3V3_PG_HAL_PORT_PIN P4_4
#define P3V3_PG P4_4
#define P3V3_PG_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define P3V3_PG_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define P3V3_PG_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define P3V3_EN_ENABLED 1U
#define P3V3_EN_PORT GPIO_PRT4
#define P3V3_EN_PORT_NUM 4U
#define P3V3_EN_PIN 5U
#define P3V3_EN_NUM 5U
#define P3V3_EN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define P3V3_EN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_4_pin_5_HSIOM
    #define ioss_0_port_4_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define P3V3_EN_HSIOM ioss_0_port_4_pin_5_HSIOM
#define P3V3_EN_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define P3V3_EN_HAL_PORT_PIN P4_5
#define P3V3_EN P4_5
#define P3V3_EN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define P3V3_EN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define P3V3_EN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define VBATT_EN_ENABLED 1U
#define VBATT_EN_PORT GPIO_PRT4
#define VBATT_EN_PORT_NUM 4U
#define VBATT_EN_PIN 6U
#define VBATT_EN_NUM 6U
#define VBATT_EN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define VBATT_EN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_4_pin_6_HSIOM
    #define ioss_0_port_4_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define VBATT_EN_HSIOM ioss_0_port_4_pin_6_HSIOM
#define VBATT_EN_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define VBATT_EN_HAL_PORT_PIN P4_6
#define VBATT_EN P4_6
#define VBATT_EN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define VBATT_EN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define VBATT_EN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define LED_EN_ENABLED 1U
#define LED_EN_PORT GPIO_PRT4
#define LED_EN_PORT_NUM 4U
#define LED_EN_PIN 7U
#define LED_EN_NUM 7U
#define LED_EN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_EN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_4_pin_7_HSIOM
    #define ioss_0_port_4_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_EN_HSIOM ioss_0_port_4_pin_7_HSIOM
#define LED_EN_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define LED_EN_HAL_PORT_PIN P4_7
#define LED_EN P4_7
#define LED_EN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_EN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define LED_EN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define HVLDO_EN_ENABLED 1U
#define HVLDO_EN_PORT GPIO_PRT5
#define HVLDO_EN_PORT_NUM 5U
#define HVLDO_EN_PIN 0U
#define HVLDO_EN_NUM 0U
#define HVLDO_EN_DRIVEMODE CY_GPIO_DM_HIGHZ
#define HVLDO_EN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_0_HSIOM
    #define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define HVLDO_EN_HSIOM ioss_0_port_5_pin_0_HSIOM
#define HVLDO_EN_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define HVLDO_EN_HAL_PORT_PIN P5_0
#define HVLDO_EN P5_0
#define HVLDO_EN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define HVLDO_EN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define HVLDO_EN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define DES_INTB_ENABLED 1U
#define DES_INTB_PORT GPIO_PRT5
#define DES_INTB_PORT_NUM 5U
#define DES_INTB_PIN 3U
#define DES_INTB_NUM 3U
#define DES_INTB_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DES_INTB_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_3_HSIOM
    #define ioss_0_port_5_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_INTB_HSIOM ioss_0_port_5_pin_3_HSIOM
#define DES_INTB_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define DES_INTB_HAL_PORT_PIN P5_3
#define DES_INTB P5_3
#define DES_INTB_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_INTB_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define DES_INTB_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define DES_PDB_ENABLED 1U
#define DES_PDB_PORT GPIO_PRT5
#define DES_PDB_PORT_NUM 5U
#define DES_PDB_PIN 5U
#define DES_PDB_NUM 5U
#define DES_PDB_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DES_PDB_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_5_HSIOM
    #define ioss_0_port_5_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_PDB_HSIOM ioss_0_port_5_pin_5_HSIOM
#define DES_PDB_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define DES_PDB_HAL_PORT_PIN P5_5
#define DES_PDB P5_5
#define DES_PDB_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_PDB_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define DES_PDB_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define LED_DIM_ENABLED 1U
#define LED_DIM_PORT GPIO_PRT5
#define LED_DIM_PORT_NUM 5U
#define LED_DIM_PIN 6U
#define LED_DIM_NUM 6U
#define LED_DIM_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_DIM_INIT_DRIVESTATE 0
#ifndef ioss_0_port_5_pin_6_HSIOM
    #define ioss_0_port_5_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_DIM_HSIOM ioss_0_port_5_pin_6_HSIOM
#define LED_DIM_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define LED_DIM_HAL_PORT_PIN P5_6
#define LED_DIM P5_6
#define LED_DIM_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_DIM_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define LED_DIM_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define LED_FAULT_ENABLED 1U
#define LED_FAULT_PORT GPIO_PRT5
#define LED_FAULT_PORT_NUM 5U
#define LED_FAULT_PIN 7U
#define LED_FAULT_NUM 7U
#define LED_FAULT_DRIVEMODE CY_GPIO_DM_HIGHZ
#define LED_FAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_7_HSIOM
    #define ioss_0_port_5_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_FAULT_HSIOM ioss_0_port_5_pin_7_HSIOM
#define LED_FAULT_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define LED_FAULT_HAL_PORT_PIN P5_7
#define LED_FAULT P5_7
#define LED_FAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_FAULT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define LED_FAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define DES_BISTEN_ENABLED 1U
#define DES_BISTEN_PORT GPIO_PRT6
#define DES_BISTEN_PORT_NUM 6U
#define DES_BISTEN_PIN 0U
#define DES_BISTEN_NUM 0U
#define DES_BISTEN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DES_BISTEN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_6_pin_0_HSIOM
    #define ioss_0_port_6_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define DES_BISTEN_HSIOM ioss_0_port_6_pin_0_HSIOM
#define DES_BISTEN_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define DES_BISTEN_HAL_PORT_PIN P6_0
#define DES_BISTEN P6_0
#define DES_BISTEN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DES_BISTEN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define DES_BISTEN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define DISP_RESX_ENABLED 1U
#define DISP_RESX_PORT GPIO_PRT6
#define DISP_RESX_PORT_NUM 6U
#define DISP_RESX_PIN 1U
#define DISP_RESX_NUM 1U
#define DISP_RESX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DISP_RESX_INIT_DRIVESTATE 0
#ifndef ioss_0_port_6_pin_1_HSIOM
    #define ioss_0_port_6_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define DISP_RESX_HSIOM ioss_0_port_6_pin_1_HSIOM
#define DISP_RESX_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define DISP_RESX_HAL_PORT_PIN P6_1
#define DISP_RESX P6_1
#define DISP_RESX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DISP_RESX_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define DISP_RESX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

#define MCU_I2C_SCL_ENABLED 1U
#define MCU_I2C_SCL_PORT GPIO_PRT6
#define MCU_I2C_SCL_PORT_NUM 6U
#define MCU_I2C_SCL_PIN 4U
#define MCU_I2C_SCL_NUM 4U
#define MCU_I2C_SCL_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define MCU_I2C_SCL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_4_HSIOM
    #define ioss_0_port_6_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define MCU_I2C_SCL_HSIOM ioss_0_port_6_pin_4_HSIOM
#define MCU_I2C_SCL_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define MCU_I2C_SCL_HAL_PORT_PIN P6_4
#define MCU_I2C_SCL P6_4
#define MCU_I2C_SCL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define MCU_I2C_SCL_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define MCU_I2C_SCL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_OPENDRAINDRIVESLOW
#endif /* defined (CY_USING_HAL) */

#define MCU_I2C_SDA_ENABLED 1U
#define MCU_I2C_SDA_PORT GPIO_PRT6
#define MCU_I2C_SDA_PORT_NUM 6U
#define MCU_I2C_SDA_PIN 5U
#define MCU_I2C_SDA_NUM 5U
#define MCU_I2C_SDA_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define MCU_I2C_SDA_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_5_HSIOM
    #define ioss_0_port_6_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define MCU_I2C_SDA_HSIOM ioss_0_port_6_pin_5_HSIOM
#define MCU_I2C_SDA_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define MCU_I2C_SDA_HAL_PORT_PIN P6_5
#define MCU_I2C_SDA P6_5
#define MCU_I2C_SDA_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define MCU_I2C_SDA_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define MCU_I2C_SDA_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_OPENDRAINDRIVESLOW
#endif /* defined (CY_USING_HAL) */

#define DEBUG_UART_RX_ENABLED 1U
#define DEBUG_UART_RX_PORT GPIO_PRT7
#define DEBUG_UART_RX_PORT_NUM 7U
#define DEBUG_UART_RX_PIN 0U
#define DEBUG_UART_RX_NUM 0U
#define DEBUG_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define DEBUG_UART_RX_INIT_DRIVESTATE 0
#ifndef ioss_0_port_7_pin_0_HSIOM
    #define ioss_0_port_7_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define DEBUG_UART_RX_HSIOM ioss_0_port_7_pin_0_HSIOM
#define DEBUG_UART_RX_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define DEBUG_UART_RX_HAL_PORT_PIN P7_0
#define DEBUG_UART_RX P7_0
#define DEBUG_UART_RX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DEBUG_UART_RX_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define DEBUG_UART_RX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) */

#define DEBUG_UART_TX_ENABLED 1U
#define DEBUG_UART_TX_PORT GPIO_PRT7
#define DEBUG_UART_TX_PORT_NUM 7U
#define DEBUG_UART_TX_PIN 1U
#define DEBUG_UART_TX_NUM 1U
#define DEBUG_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DEBUG_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
    #define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define DEBUG_UART_TX_HSIOM ioss_0_port_7_pin_1_HSIOM
#define DEBUG_UART_TX_IRQ ioss_interrupt_gpio_IRQn

#if defined (CY_USING_HAL)
#define DEBUG_UART_TX_HAL_PORT_PIN P7_1
#define DEBUG_UART_TX P7_1
#define DEBUG_UART_TX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define DEBUG_UART_TX_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define DEBUG_UART_TX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t PCBA_A0_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t PCBA_A0_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t PCBA_A1_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t PCBA_A1_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t PCBA_A2_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t PCBA_A2_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t PCBA_A3_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t PCBA_A3_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t RTC_WCO_IN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t RTC_WCO_IN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t RTC_WCO_OUT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t RTC_WCO_OUT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t P1V2_EN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t P1V2_EN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t P1V2_PG_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t P1V2_PG_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t BIAS_FAULT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t BIAS_FAULT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t BIAS_EN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t BIAS_EN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_I2C_SCL_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_I2C_SCL_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_I2C_SDA_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_I2C_SDA_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_7_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t ioss_0_port_1_pin_7_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t ADC_BLTTEMP_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t ADC_BLTTEMP_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t ADC_PCBTEMP_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t ADC_PCBTEMP_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t ADC_BATTVOLT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t ADC_BATTVOLT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t SYNC_CHECK_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t SYNC_CHECK_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t FPCACHK_ROUT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t FPCACHK_ROUT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t FPCACHK_RIN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t FPCACHK_RIN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_LOCK_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_LOCK_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_PASS_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_PASS_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t EXFLASH_WP_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t EXFLASH_WP_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DISP_FAULT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DISP_FAULT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t MCU_SWDIO_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t MCU_SWDIO_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t MCU_SWCLK_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t MCU_SWCLK_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t FPCACHK_LOUT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t FPCACHK_LOUT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t FPCACHK_LIN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t FPCACHK_LIN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DDIC_WP_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DDIC_WP_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t EXFLASH_SPI_SDI_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t EXFLASH_SPI_SDI_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t EXFLASH_SPI_SDO_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t EXFLASH_SPI_SDO_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t EXFLASH_SPI_SCK_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t EXFLASH_SPI_SCK_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t EXFLASH_SPI_CS_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t EXFLASH_SPI_CS_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t P3V3_PG_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t P3V3_PG_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t P3V3_EN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t P3V3_EN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t VBATT_EN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t VBATT_EN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t LED_EN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t LED_EN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t HVLDO_EN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t HVLDO_EN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_INTB_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_INTB_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_PDB_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_PDB_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t LED_DIM_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t LED_DIM_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t LED_FAULT_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t LED_FAULT_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DES_BISTEN_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DES_BISTEN_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DISP_RESX_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DISP_RESX_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t MCU_I2C_SCL_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t MCU_I2C_SCL_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t MCU_I2C_SDA_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t MCU_I2C_SDA_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DEBUG_UART_RX_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DEBUG_UART_RX_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_gpio_pin_config_t DEBUG_UART_TX_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t DEBUG_UART_TX_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
