/*******************************************************************************
 * File Name: cycfg_clocks.c
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

#include "cycfg_clocks.h"

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t peri_0_div_16_0_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_0_HW,
    .channel_num = peri_0_div_16_0_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_10_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_10_HW,
    .channel_num = peri_0_div_16_10_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_11_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_11_HW,
    .channel_num = peri_0_div_16_11_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_1_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_1_HW,
    .channel_num = peri_0_div_16_1_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_2_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_2_HW,
    .channel_num = peri_0_div_16_2_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_3_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_3_HW,
    .channel_num = peri_0_div_16_3_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_4_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_4_HW,
    .channel_num = peri_0_div_16_4_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_5_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_5_HW,
    .channel_num = peri_0_div_16_5_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_6_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_6_HW,
    .channel_num = peri_0_div_16_6_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_7_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_7_HW,
    .channel_num = peri_0_div_16_7_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_8_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_8_HW,
    .channel_num = peri_0_div_16_8_NUM,
};
const cyhal_resource_inst_t peri_0_div_16_9_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_16_9_HW,
    .channel_num = peri_0_div_16_9_NUM,
};
const cyhal_resource_inst_t peri_0_div_24_5_0_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_div_24_5_0_HW,
    .channel_num = peri_0_div_24_5_0_NUM,
};
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void)
{
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, 5U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 10U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 10U, 0U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 10U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 11U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 11U, 4U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 11U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, 2U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 2U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2U, 3U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 2U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 3U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 3U, 51U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 3U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 4U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 4U, 4U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 4U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 5U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 5U, 0U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 5U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 6U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 6U, 47U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 6U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 7U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 7U, 4U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 7U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 8U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 8U, 3U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 8U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 9U);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 9U, 0U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 9U);
    Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_24_5_BIT, 0U);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, 0U, 4U, 0U);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, 0U);
}
void reserve_cycfg_clocks(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&peri_0_div_16_0_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_10_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_11_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_1_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_2_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_3_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_4_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_5_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_6_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_7_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_8_obj);
    cyhal_hwmgr_reserve(&peri_0_div_16_9_obj);
    cyhal_hwmgr_reserve(&peri_0_div_24_5_0_obj);
#endif /* defined (CY_USING_HAL) */
}
