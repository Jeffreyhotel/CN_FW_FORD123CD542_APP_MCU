/*******************************************************************************
 * File Name: cycfg_clocks.h
 *
 * Description:
 * Clock configuration
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

#if !defined(CYCFG_CLOCKS_H)
#define CYCFG_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define peri_0_div_16_0_ENABLED 1U
#define peri_0_div_16_0_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_0_NUM 0U
#define peri_0_div_16_10_ENABLED 1U
#define peri_0_div_16_10_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_10_NUM 10U
#define peri_0_div_16_11_ENABLED 1U
#define peri_0_div_16_11_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_11_NUM 11U
#define peri_0_div_16_1_ENABLED 1U
#define peri_0_div_16_1_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_1_NUM 1U
#define peri_0_div_16_2_ENABLED 1U
#define peri_0_div_16_2_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_2_NUM 2U
#define peri_0_div_16_3_ENABLED 1U
#define peri_0_div_16_3_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_3_NUM 3U
#define peri_0_div_16_4_ENABLED 1U
#define peri_0_div_16_4_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_4_NUM 4U
#define peri_0_div_16_5_ENABLED 1U
#define peri_0_div_16_5_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_5_NUM 5U
#define peri_0_div_16_6_ENABLED 1U
#define peri_0_div_16_6_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_6_NUM 6U
#define peri_0_div_16_7_ENABLED 1U
#define peri_0_div_16_7_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_7_NUM 7U
#define peri_0_div_16_8_ENABLED 1U
#define peri_0_div_16_8_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_8_NUM 8U
#define peri_0_div_16_9_ENABLED 1U
#define peri_0_div_16_9_HW CY_SYSCLK_DIV_16_BIT
#define peri_0_div_16_9_NUM 9U
#define peri_0_div_24_5_0_ENABLED 1U
#define peri_0_div_24_5_0_HW CY_SYSCLK_DIV_24_5_BIT
#define peri_0_div_24_5_0_NUM 0U

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t peri_0_div_16_0_obj;
extern const cyhal_resource_inst_t peri_0_div_16_10_obj;
extern const cyhal_resource_inst_t peri_0_div_16_11_obj;
extern const cyhal_resource_inst_t peri_0_div_16_1_obj;
extern const cyhal_resource_inst_t peri_0_div_16_2_obj;
extern const cyhal_resource_inst_t peri_0_div_16_3_obj;
extern const cyhal_resource_inst_t peri_0_div_16_4_obj;
extern const cyhal_resource_inst_t peri_0_div_16_5_obj;
extern const cyhal_resource_inst_t peri_0_div_16_6_obj;
extern const cyhal_resource_inst_t peri_0_div_16_7_obj;
extern const cyhal_resource_inst_t peri_0_div_16_8_obj;
extern const cyhal_resource_inst_t peri_0_div_16_9_obj;
extern const cyhal_resource_inst_t peri_0_div_24_5_0_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void);
void reserve_cycfg_clocks(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_CLOCKS_H */
