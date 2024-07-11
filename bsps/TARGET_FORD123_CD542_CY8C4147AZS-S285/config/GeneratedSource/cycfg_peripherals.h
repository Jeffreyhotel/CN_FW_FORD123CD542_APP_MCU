/*******************************************************************************
 * File Name: cycfg_peripherals.h
 *
 * Description:
 * Peripheral Hardware Block configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_sar.h"
#include "cycfg_routing.h"
#include "cy_sysclk.h"
#include "cy_scb_spi.h"
#include "cy_scb_i2c.h"
#include "cy_scb_uart.h"
#include "cy_tcpwm_counter.h"
#include "cy_tcpwm_pwm.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define PASS_ADC_SENSE_ENABLED 1U
#define PASS_ADC_SENSE_HW SAR0
#define PASS_ADC_SENSE_IRQ pass_0_interrupt_sar_IRQn
#define PASS_ADC_SENSE_VREF_MV 3300UL
#define SCB_SPI0M_ENABLED 1U
#define SCB_SPI0M_HW SCB0
#define SCB_SPI0M_IRQ scb_0_interrupt_IRQn
#define SCB_I2C1M_ENABLED 1U
#define SCB_I2C1M_HW SCB1
#define SCB_I2C1M_IRQ scb_1_interrupt_IRQn
#define SCB_I2C2S_ENABLED 1U
#define SCB_I2C2S_HW SCB2
#define SCB_I2C2S_IRQ scb_2_interrupt_IRQn
#define SCB_UART3_DEBUG_ENABLED 1U
#define SCB_UART3_DEBUG_HW SCB3
#define SCB_UART3_DEBUG_IRQ scb_3_interrupt_IRQn
#define SCB_I2C4M_ENABLED 1U
#define SCB_I2C4M_HW SCB4
#define SCB_I2C4M_IRQ scb_4_interrupt_IRQn
#define TC0_TIMER_ENABLED 1U
#define TC0_TIMER_HW TCPWM
#define TC0_TIMER_NUM 0UL
#define TC0_TIMER_MASK (1UL << 0)
#define TC0_TIMER_IRQ tcpwm_interrupts_0_IRQn
#define TC5_INTB_ENABLED 1U
#define TC5_INTB_HW TCPWM
#define TC5_INTB_NUM 5UL
#define TC5_INTB_MASK (1UL << 5)
#define TC7_PWM_LED_ENABLED 1U
#define TC7_PWM_LED_HW TCPWM
#define TC7_PWM_LED_NUM 7UL
#define TC7_PWM_LED_MASK (1UL << 7)

extern const cy_stc_sar_channel_config_t PASS_ADC_SENSE_channel_0_config;
extern const cy_stc_sar_channel_config_t PASS_ADC_SENSE_channel_1_config;
extern const cy_stc_sar_channel_config_t PASS_ADC_SENSE_channel_2_config;
extern const cy_stc_sar_config_t PASS_ADC_SENSE_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t PASS_ADC_SENSE_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_scb_spi_config_t SCB_SPI0M_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t SCB_SPI0M_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_scb_i2c_config_t SCB_I2C1M_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t SCB_I2C1M_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_scb_i2c_config_t SCB_I2C2S_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t SCB_I2C2S_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_scb_uart_config_t SCB_UART3_DEBUG_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t SCB_UART3_DEBUG_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_scb_i2c_config_t SCB_I2C4M_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t SCB_I2C4M_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_tcpwm_counter_config_t TC0_TIMER_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t TC0_TIMER_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_tcpwm_pwm_config_t TC5_INTB_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t TC5_INTB_obj;
#endif /* defined (CY_USING_HAL) */

extern const cy_stc_tcpwm_pwm_config_t TC7_PWM_LED_config;

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t TC7_PWM_LED_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_peripherals(void);
void reserve_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERALS_H */
