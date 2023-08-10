#include "NXP_config.h"

void CADC_Value_Read(void);
// uint32_t BEMF_U_Value = 0U;
// uint32_t BEMF_V_Value = 0U;
// uint32_t BEMF_W_Value = 0U;
uint32_t CURRENT_U_Value = 0U;
uint32_t CURRENT_V_Value = 0U;
uint32_t CURRENT_W_Value = 0U;
uint32_t DC_BUS_Value = 0U;
uint32_t IPM_TEMP_Value = 0U; // 0-4095 arasında ham değer
uint32_t IpmTemp_mV = 0U;	  // ipm direnç değeri
uint32_t IpmTemp_Value = 0U;  // ipm sıcaklık değeri(derece-santigrat)
uint32_t CadcConversionValue = 0;