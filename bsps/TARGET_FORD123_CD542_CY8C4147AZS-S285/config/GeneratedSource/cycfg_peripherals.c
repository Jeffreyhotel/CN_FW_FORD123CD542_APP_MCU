/*******************************************************************************
 * File Name: cycfg_peripherals.c
 *
 * Description:
 * Peripheral Hardware Block configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.20.0
 * device-db 4.17.0.6514
 * mtb-pdl-cat2 2.12.0.12916
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

#include "cycfg_peripherals.h"

#define TC0_TIMER_INPUT_DISABLED 0x7U
#define TC5_INTB_INPUT_DISABLED 0x7U
#define TC7_PWM_LED_INPUT_DISABLED 0x7U

const cy_stc_sar_channel_config_t PASS_ADC_SENSE_channel_0_config =
{
    .addr = (cy_en_sar_chan_config_port_pin_addr_t)(SAR0_VPLUS0_PIN | (SAR0_VPLUS0_PORT << SAR_CHAN_CONFIG_PORT_ADDR_Pos)),
    .differential = false,
    .resolution = CY_SAR_MAX_RES,
    .avgEn = false,
    .sampleTimeSel = CY_SAR_SAMPLE_TIME_0,
    .rangeIntrEn = false,
    .satIntrEn = false,
};
const cy_stc_sar_channel_config_t PASS_ADC_SENSE_channel_1_config =
{
    .addr = (cy_en_sar_chan_config_port_pin_addr_t)(SAR0_VPLUS1_PIN | (SAR0_VPLUS1_PORT << SAR_CHAN_CONFIG_PORT_ADDR_Pos)),
    .differential = false,
    .resolution = CY_SAR_MAX_RES,
    .avgEn = false,
    .sampleTimeSel = CY_SAR_SAMPLE_TIME_1,
    .rangeIntrEn = false,
    .satIntrEn = false,
};
const cy_stc_sar_channel_config_t PASS_ADC_SENSE_channel_2_config =
{
    .addr = (cy_en_sar_chan_config_port_pin_addr_t)(SAR0_VPLUS2_PIN | (SAR0_VPLUS2_PORT << SAR_CHAN_CONFIG_PORT_ADDR_Pos)),
    .differential = false,
    .resolution = CY_SAR_MAX_RES,
    .avgEn = false,
    .sampleTimeSel = CY_SAR_SAMPLE_TIME_1,
    .rangeIntrEn = false,
    .satIntrEn = false,
};
const cy_stc_sar_config_t PASS_ADC_SENSE_config =
{
    .vrefSel = CY_SAR_VREF_SEL_VDDA_DIV_2,
    .vrefBypCapEn = true,
    .negSel = CY_SAR_NEG_SEL_VREF,
    .negVref = CY_SAR_NEGVREF_HW,
    .boostPump = false,
    .power = CY_SAR_HALF_PWR,
    .sarMuxDsEn = false,
    .switchDisable = false,
    .subResolution = CY_SAR_SUB_RESOLUTION_10B,
    .leftAlign = false,
    .singleEndedSigned = false,
    .differentialSigned = false,
    .avgCnt = CY_SAR_AVG_CNT_16,
    .avgShift = true,
    .trigMode = CY_SAR_TRIGGER_MODE_FW_ONLY,
    .eosEn = false,
    .sampleTime0 = 352,
    .sampleTime1 = 3,
    .sampleTime2 = 2,
    .sampleTime3 = 2,
    .rangeThresLow = 0UL,
    .rangeThresHigh = 0UL,
    .rangeCond = CY_SAR_RANGE_COND_BELOW,
    .chanEn = 7UL,
    .channelConfig = {&PASS_ADC_SENSE_channel_0_config, &PASS_ADC_SENSE_channel_1_config, &PASS_ADC_SENSE_channel_2_config, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    .routingConfig = NULL,
    .vrefMvValue = PASS_ADC_SENSE_VREF_MV,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t PASS_ADC_SENSE_obj =
{
    .type = CYHAL_RSC_ADC,
    .block_num = 0,
    .channel_num = 0,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_scb_spi_config_t SCB_SPI0M_config =
{
    .spiMode = CY_SCB_SPI_MASTER,
    .subMode = CY_SCB_SPI_MOTOROLA,
    .sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
    .oversample = 16,
    .rxDataWidth = 8UL,
    .txDataWidth = 8UL,
    .enableMsbFirst = true,
    .enableInputFilter = false,
    .enableFreeRunSclk = false,
    .enableMisoLateSample = true,
    .enableTransferSeperation = false,
    .ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
    .enableWakeFromSleep = false,
    .rxFifoTriggerLevel = 7UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 0UL,
    .txFifoIntEnableMask = 0UL,
    .masterSlaveIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t SCB_SPI0M_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 0U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_scb_i2c_config_t SCB_I2C2S_config =
{
    .i2cMode = CY_SCB_I2C_SLAVE,
    .useRxFifo = true,
    .useTxFifo = true,
    .slaveAddress = 113,
    .slaveAddressMask = 254,
    .acceptAddrInFifo = false,
    .ackGeneralAddr = false,
    .enableWakeFromSleep = false,
    .enableDigitalFilter = false,
    .lowPhaseDutyCycle = 0,
    .highPhaseDutyCycle = 0,
    .delayInFifoAddress = 0,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t SCB_I2C2S_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 2U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_scb_uart_config_t SCB_UART3_DEBUG_config =
{
    .uartMode = CY_SCB_UART_STANDARD,
    .enableMutliProcessorMode = false,
    .smartCardRetryOnNack = false,
    .irdaInvertRx = false,
    .irdaEnableLowPowerReceiver = false,
    .enableLinMode = false,
    .oversample = 8,
    .enableMsbFirst = false,
    .dataWidth = 8UL,
    .parity = CY_SCB_UART_PARITY_NONE,
    .stopBits = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter = false,
    .breakWidth = 11UL,
    .dropOnFrameError = false,
    .dropOnParityError = false,
    .receiverAddress = 0x0UL,
    .receiverAddressMask = 0x0UL,
    .acceptAddrInFifo = false,
    .enableCts = false,
    .ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rtsRxFifoLevel = 0UL,
    .rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
    .rxFifoTriggerLevel = 7UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 7UL,
    .txFifoIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t SCB_UART3_DEBUG_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 3U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_scb_i2c_config_t SCB_I2C4M_config =
{
    .i2cMode = CY_SCB_I2C_MASTER,
    .useRxFifo = true,
    .useTxFifo = true,
    .slaveAddress = 0U,
    .slaveAddressMask = 0U,
    .acceptAddrInFifo = false,
    .ackGeneralAddr = false,
    .enableWakeFromSleep = false,
    .enableDigitalFilter = false,
    .lowPhaseDutyCycle = 16,
    .highPhaseDutyCycle = 9,
    .delayInFifoAddress = 0,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t SCB_I2C4M_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 4U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_tcpwm_counter_config_t TC0_TIMER_config =
{
    .period = 32768,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = CY_TCPWM_INT_ON_TC,
    .captureInputMode = TC0_TIMER_INPUT_DISABLED & 0x3U,
    .captureInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = TC0_TIMER_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = TC0_TIMER_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = TC0_TIMER_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = TC0_TIMER_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t TC0_TIMER_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_tcpwm_pwm_config_t TC5_INTB_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 1,
    .runMode = CY_TCPWM_PWM_ONESHOT,
    .period0 = 50000,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 25000,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = CY_TCPWM_INT_NONE,
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_ENABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = TC5_INTB_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = TC5_INTB_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = TC5_INTB_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = TC5_INTB_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = TC5_INTB_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t TC5_INTB_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 5U,
};
#endif /* defined (CY_USING_HAL) */

const cy_stc_tcpwm_pwm_config_t TC7_PWM_LED_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_16,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 20459,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 0,
    .enableCompareSwap = false,
    .interruptSources = CY_TCPWM_INT_NONE,
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = TC7_PWM_LED_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = TC7_PWM_LED_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = TC7_PWM_LED_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = TC7_PWM_LED_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = TC7_PWM_LED_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
};

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t TC7_PWM_LED_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 7U,
};
#endif /* defined (CY_USING_HAL) */

void init_cycfg_peripherals(void)
{
    Cy_SysClk_PeriphAssignDivider(PCLK_PASS0_CLOCK_SAR, CY_SYSCLK_DIV_16_BIT, 0U);
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB0_CLOCK, CY_SYSCLK_DIV_16_BIT, 1U);
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB2_CLOCK, CY_SYSCLK_DIV_16_BIT, 2U);
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB3_CLOCK, CY_SYSCLK_DIV_16_BIT, 3U);
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB4_CLOCK, CY_SYSCLK_DIV_16_BIT, 4U);
    Cy_WDT_SetMatch(4096UL);
    Cy_WDT_SetIgnoreBits(0UL);
    Cy_WDT_ClearInterrupt();
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS0, CY_SYSCLK_DIV_16_BIT, 6U);
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS5, CY_SYSCLK_DIV_16_BIT, 8U);
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS7, CY_SYSCLK_DIV_16_BIT, 5U);
}
void reserve_cycfg_peripherals(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&PASS_ADC_SENSE_obj);
    cyhal_hwmgr_reserve(&SCB_SPI0M_obj);
    cyhal_hwmgr_reserve(&SCB_I2C2S_obj);
    cyhal_hwmgr_reserve(&SCB_UART3_DEBUG_obj);
    cyhal_hwmgr_reserve(&SCB_I2C4M_obj);
    cyhal_hwmgr_reserve(&TC0_TIMER_obj);
    cyhal_hwmgr_reserve(&TC5_INTB_obj);
    cyhal_hwmgr_reserve(&TC7_PWM_LED_obj);
#endif /* defined (CY_USING_HAL) */
}
