#include "Analog_Read.h"

void CADC_Value_Read(void)
{

	CADC_ClearStatusFlags(DEMO_CADC_BASEADDR, kCADC_ConverterAEndOfScanFlag);
	CADC_ClearStatusFlags(DEMO_CADC_BASEADDR, kCADC_ConverterBEndOfScanFlag);
	CADC_DoSoftwareTriggerConverter(DEMO_CADC_BASEADDR, kCADC_ConverterA); // Triggers the converter A by software trigger.
	CADC_DoSoftwareTriggerConverter(DEMO_CADC_BASEADDR, kCADC_ConverterB); // Triggers the converter B by software trigger.

	while (kCADC_ConverterAEndOfScanFlag != (kCADC_ConverterAEndOfScanFlag & CADC_GetStatusFlags(DEMO_CADC_BASEADDR)))
	{
	}
	while (kCADC_ConverterBEndOfScanFlag != (kCADC_ConverterBEndOfScanFlag & CADC_GetStatusFlags(DEMO_CADC_BASEADDR)))
	{
	}

	// Get Sample Result value
	CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 9U); // The lower three bits of ADC_RSLT register are always going to be zero
	CURRENT_U_Value = CadcConversionValue >> 3;

	CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 1U);
	CURRENT_V_Value = CadcConversionValue >> 3;

	CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 0U);
	CURRENT_W_Value = CadcConversionValue >> 3;

	////CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 2U); //normalde 4
	////BEMF_U_Value  = CadcConversionValue >> 3;

	////CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 3U); //normalde 5
	////BEMF_V_Value  = CadcConversionValue >> 3;

	////CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 8U);
	////BEMF_W_Value  = CadcConversionValue >> 3;

	CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 10U);
	DC_BUS_Value = CadcConversionValue >> 3;

	CadcConversionValue = CADC_GetSampleResultValue(DEMO_CADC_BASEADDR, 11U);
	IPM_TEMP_Value = CadcConversionValue >> 3;

	// Convert CADC value to a voltage based on 3.3V VREFH on board
	// voltRead = (float)(CadcConversionValue * (VREF_BRD / SE_12BIT));

	CADC_ClearStatusFlags(DEMO_CADC_BASEADDR, kCADC_ConverterAEndOfScanFlag); // Clear status Flags
	CADC_ClearStatusFlags(DEMO_CADC_BASEADDR, kCADC_ConverterBEndOfScanFlag); // Clear status Flags
}
