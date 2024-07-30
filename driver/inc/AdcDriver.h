#ifndef __ADCDRIVER_H__
#define __ADCDRIVER_H__

#include "main.h"

#define ADC_SAR0_TYPE       SAR0
#define ADC_SAR0_CONFIG     PASS_ADC_SENSE_config
#define ADC_SAR0_CH0_BLTTEMP    0x00000000U
#define ADC_SAR0_CH1_PCBTEMP    0x00000001U
#define ADC_SAR0_CH2_BATVOLT    0x00000002U

bool AdcDriver_Initial(SAR_Type* SAR, cy_stc_sar_config_t SAR_Config);
void AdcDriver_Enable(SAR_Type* SAR);
void AdcDriver_Disable(SAR_Type* SAR);
uint16_t AdcDriver_ChannelResultGet(SAR_Type* SAR, uint16_t channel);

#endif