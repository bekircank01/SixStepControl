/**
 * @file    NXP_config.c
 * @brief   Processor Specicific codes are included
 * @authors MemisNail Can Bekir
 * @details
 */

#include "NXP_config.h"

void PWM_Config(void)
{
    // PWM CONFIG

    ftm_config_t ftmInfo;
    ftm_chnl_pwm_signal_param_t ftmParam[3];
    ftm_chnl_pwm_signal_param_t ftmParam1[3];

    /* Configure ftm params with frequency 24kHZ */
    ftmParam[0].chnlNumber = (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL; // W_H
    ftmParam[0].level = kFTM_HighTrue;
    ftmParam[0].dutyCyclePercent = 0U;
    ftmParam[0].firstEdgeDelayPercent = 0U;
    ftmParam[0].enableDeadtime = false;

    ftmParam[1].chnlNumber = (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL; // U_L
    ftmParam[1].level = kFTM_HighTrue;
    ftmParam[1].dutyCyclePercent = 0U;
    ftmParam[1].firstEdgeDelayPercent = 0U;
    ftmParam[1].enableDeadtime = false;

    ftmParam[2].chnlNumber = (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL; // U_H
    ftmParam[2].level = kFTM_HighTrue;
    ftmParam[2].dutyCyclePercent = 0U;
    ftmParam[2].firstEdgeDelayPercent = 0U;
    ftmParam[2].enableDeadtime = false;
    //---------------------------------------------------------------------------//

    ftmParam1[0].chnlNumber = (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL; // W_L
    ftmParam1[0].level = kFTM_HighTrue;
    ftmParam1[0].dutyCyclePercent = 0U;
    ftmParam1[0].firstEdgeDelayPercent = 0U;
    ftmParam1[0].enableDeadtime = false;

    ftmParam1[1].chnlNumber = (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL; // V_L
    ftmParam1[1].level = kFTM_HighTrue;
    ftmParam1[1].dutyCyclePercent = 0U;
    ftmParam1[1].firstEdgeDelayPercent = 0U;
    ftmParam1[1].enableDeadtime = false;

    ftmParam1[2].chnlNumber = (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL; // V_H
    ftmParam1[2].level = kFTM_HighTrue;
    ftmParam1[2].dutyCyclePercent = 0U;
    ftmParam1[2].firstEdgeDelayPercent = 0U;
    ftmParam1[2].enableDeadtime = false;

    FTM_GetDefaultConfig(&ftmInfo);
    /* Divide the system clock by 1 */
    // ftmInfo.deadTimePrescale = kFTM_Deadtime_Prescale_4;
    /* No counts are inserted */
    // ftmInfo.deadTimeValue = 0; //kafama göre

    /* Initialize FTM module */
    FTM_Init(BOARD_FTM_BASEADDR, &ftmInfo);  // FTM0
    FTM_Init(BOARD_FTM_BASEADDR3, &ftmInfo); // FTM3

    // FTM1
    FTM_SetupPwm(BOARD_FTM_BASEADDR, ftmParam, 3U, kFTM_EdgeAlignedPwm, 4000U, FTM_SOURCE_CLOCK); // default frekans:12000
    // FTM3
    FTM_SetupPwm(BOARD_FTM_BASEADDR3, ftmParam1, 3U, kFTM_EdgeAlignedPwm, 4000U, FTM_SOURCE_CLOCK); // default frekans:12000

    FTM_StartTimer(BOARD_FTM_BASEADDR, kFTM_SystemClock);  // FTM0
    FTM_StartTimer(BOARD_FTM_BASEADDR3, kFTM_SystemClock); // FTM3
}

void Timer_Delay_Config(void)
{
    ftm_config_t ftm_delay;

    FTM_GetDefaultConfig(&ftm_delay);

    /* Divide FTM clock by 4 */
    ftm_delay.prescale = kFTM_Prescale_Divide_1; // didvide=1 olduğunda 1000 Hz

    /* Initialize FTM module */
    FTM_Init(BOARD_FTM_BASEADDR1, &ftm_delay);

    /*
     * Set timer period.
     */
    FTM_SetTimerPeriod(BOARD_FTM_BASEADDR1, USEC_TO_COUNT(100U, FTM_SOURCE_CLOCK)); // normalde 200
    // timer frekans depğeri için modülo değerini değiştirmek gerek, modüla azalınca freq artıyor.
    // 200=5kHz, 10=10kHz, 1000=1kHz (divide 1 ise)
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR1, kFTM_TimeOverflowInterruptEnable);

    EnableIRQ(BOARD_FTM1_IRQ_NUM);

    FTM_StartTimer(BOARD_FTM_BASEADDR1, kFTM_SystemClock);
}

void CADC_Config(void)
{
    cadc_config_t cadcConfigStruct;
    cadc_converter_config_t cadcConverterConfigStruct;
    cadc_sample_config_t cadcSampleConfigStruct;

    /* Configure the CADC */
    CADC_GetDefaultConfig(&cadcConfigStruct);                                       // Gets an available pre-defined settings for module's configuration.
    cadcConfigStruct.dualConverterScanMode = kCADC_DualConverterWorkAsOnceParallel; // default: sequential mode
    cadcConfigStruct.powerUpDelay = 0x2AU;                                          // Delay clock count to wait for the clock is stable.
    cadcConfigStruct.enableSimultaneousMode = false;                                // default: false
    CADC_Init(DEMO_CADC_BASEADDR, &cadcConfigStruct);                               // Enable the clock for CADC, Set the global settings for CADC converter.

    /* Trigger channel */
    // A
    CADC_EnableConverterDMA(DEMO_CADC_BASEADDR, kCADC_ConverterA, false);                 // Enables or disables the DMA feature
    CADC_EnableConverter(DEMO_CADC_BASEADDR, kCADC_ConverterA, true);                     // Enables the converter's conversion.
    CADC_EnableConverterSyncInput(DEMO_CADC_BASEADDR, kCADC_ConverterA, false);           // Enables the input of external sync signal.
    CADC_DisableInterrupts(DEMO_CADC_BASEADDR, kCADC_ConverterAEndOfScanInterruptEnable); // Disables the interrupts.
    // B
    CADC_EnableConverterDMA(DEMO_CADC_BASEADDR, kCADC_ConverterB, false);                 // Enables or disables the DMA feature
    CADC_EnableConverter(DEMO_CADC_BASEADDR, kCADC_ConverterB, true);                     // Enables the converter's conversion.
    CADC_EnableConverterSyncInput(DEMO_CADC_BASEADDR, kCADC_ConverterB, false);           // Enables the input of external sync signal.
    CADC_DisableInterrupts(DEMO_CADC_BASEADDR, kCADC_ConverterBEndOfScanInterruptEnable); // Disables the interrupts.

    CADC_GetDefaultConverterConfig(&cadcConverterConfigStruct); // Gets an available pre-defined settings for each converter's configuration.(default değere döndürür)
    cadcConverterConfigStruct.clockDivisor = 0xAU;
    cadcConverterConfigStruct.speedMode = kCADC_SpeedMode3;
    // A
    CADC_SetConverterConfig(DEMO_CADC_BASEADDR, kCADC_ConverterA, &cadcConverterConfigStruct); // Configures the converter.
    CADC_EnableConverterPower(DEMO_CADC_BASEADDR, kCADC_ConverterA, true);                     // Enables power for the converter.
    // B
    CADC_SetConverterConfig(DEMO_CADC_BASEADDR, kCADC_ConverterB, &cadcConverterConfigStruct); // Configures the converter.
    CADC_EnableConverterPower(DEMO_CADC_BASEADDR, kCADC_ConverterB, true);                     // Enables power for the converter.

    /* Configure slot in conversion sequence. */
    /* Common setting. */
    //// --> bemf olanları belirtmek için kullanıldı

    ////CADC_EnableSample(DEMO_CADC_BASEADDR, 2U, false);  //Enables or disables the sample slot.(burada 2'ıncı sample slot)
    ////cadcSampleConfigStruct.channelNumber          = BEMF_U_CADC_CHANNEL;
    cadcSampleConfigStruct.enableDifferentialPair = 0U;
    cadcSampleConfigStruct.zeroCrossingMode = kCADC_ZeroCrossingDisabled;
    cadcSampleConfigStruct.lowLimitValue = 0U;
    cadcSampleConfigStruct.highLimitValue = 0xFFFFU;
    cadcSampleConfigStruct.offsetValue = 0U; //**
    cadcSampleConfigStruct.enableWaitSync = false;

    // Enable slot 4 for BEMF_U_CADC_CHANNEL
    ////CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 2U, &cadcSampleConfigStruct);   //Configures the sample slot.
    ////CADC_EnableSample(DEMO_CADC_BASEADDR, 2U, true);                         //This function is to enable the sample slot. Only the enabled sample slot can join the conversion sequence.

    // Enable slot 5 for BEMF_V_CADC_CHANNEL
    ////CADC_EnableSample(DEMO_CADC_BASEADDR, 3U, false);
    ////cadcSampleConfigStruct.channelNumber = BEMF_V_CADC_CHANNEL;
    ////CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 3U, &cadcSampleConfigStruct);  //Index of sample slot:3
    ////CADC_EnableSample(DEMO_CADC_BASEADDR, 3U, true);

    // Enable slot 12 for  BEMF_W_CADC_CHANNEL (!!! ADCB !!!)
    ////CADC_EnableSample(DEMO_CADC_BASEADDR, 8U, false);
    ////cadcSampleConfigStruct.channelNumber =  BEMF_W_CADC_CHANNEL;
    ////CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 8U, &cadcSampleConfigStruct);  //Index of sample slot:8
    ////CADC_EnableSample(DEMO_CADC_BASEADDR, 8U, true);

    // Enable slot 9 for  CURRENT_U_CADC_CHANNEL (!!! ADCB !!!)
    CADC_EnableSample(DEMO_CADC_BASEADDR, 9U, false);
    cadcSampleConfigStruct.channelNumber = CURRENT_U_CADC_CHANNEL;
    cadcSampleConfigStruct.channelGain = kCADC_ChannelGainx2;
    CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 9U, &cadcSampleConfigStruct); // Index of sample slot:9
    CADC_EnableSample(DEMO_CADC_BASEADDR, 9U, true);
    cadcSampleConfigStruct.channelGain = kCADC_ChannelGainx1;

    // Enable slot 1 for  CURRENT_V_CADC_CHANNEL
    CADC_EnableSample(DEMO_CADC_BASEADDR, 1U, false);
    cadcSampleConfigStruct.channelNumber = CURRENT_V_CADC_CHANNEL;
    CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 1U, &cadcSampleConfigStruct); // Index of sample slot:1
    CADC_EnableSample(DEMO_CADC_BASEADDR, 1U, true);

    // Enable slot 0 for  CURRENT_W_CADC_CHANNEL
    CADC_EnableSample(DEMO_CADC_BASEADDR, 0U, false);
    cadcSampleConfigStruct.channelNumber = CURRENT_W_CADC_CHANNEL;
    CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 0U, &cadcSampleConfigStruct); // Index of sample slot:0
    CADC_EnableSample(DEMO_CADC_BASEADDR, 0U, true);

    // Enable slot 7 for  IPM_TEMP_CADC_CHANNEL
    CADC_EnableSample(DEMO_CADC_BASEADDR, 11U, false);
    cadcSampleConfigStruct.channelNumber = IPM_TEMP_CADC_CHANNEL;
    cadcSampleConfigStruct.channelGain = kCADC_ChannelGainx4;
    CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 11U, &cadcSampleConfigStruct); // Index of sample slot:11
    CADC_EnableSample(DEMO_CADC_BASEADDR, 11U, true);
    cadcSampleConfigStruct.channelGain = kCADC_ChannelGainx1;

    // Enable slot 11 for  DC_BUS_CADC_CHANNEL (!!! ADCB !!!)
    CADC_EnableSample(DEMO_CADC_BASEADDR, 10U, false);
    cadcSampleConfigStruct.channelNumber = DC_BUS_CADC_CHANNEL;
    CADC_SetSampleConfig(DEMO_CADC_BASEADDR, 10U, &cadcSampleConfigStruct); // Index of sample slot:10
    CADC_EnableSample(DEMO_CADC_BASEADDR, 10U, true);
}

void Hall_Config(void)
{
    ftm_config_t ftm_hall; //?

    FTM_GetDefaultConfig(&ftm_hall); //?

    /* Initialize FTM module */
    FTM_Init(BOARD_FTM_BASEADDR, &ftm_hall); //?

    /* Setup dual-edge capture on a FTM channel pair */
    FTM_SetupInputCapture(BOARD_FTM_BASEADDR, kFTM_Chnl_0, kFTM_RiseAndFallEdge, 0); // (Hall_C)
    FTM_SetupInputCapture(BOARD_FTM_BASEADDR, kFTM_Chnl_2, kFTM_RiseAndFallEdge, 0); // (Hall_A)
    FTM_SetupInputCapture(BOARD_FTM_BASEADDR, kFTM_Chnl_3, kFTM_RiseAndFallEdge, 0); // (Hall_B)

    /* Set the timer to be in free-running mode */
    BOARD_FTM_BASEADDR->MOD = 0xFFFF;

    /* Enable channel interrupt when the second edge is detected */
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl0InterruptEnable); // encoderA (Hall_C)
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl2InterruptEnable); // encoderB (Hall_A)
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl3InterruptEnable); // encoder index (Hall_B)

    /* Enable at the NVIC */
    EnableIRQ(BOARD_FTM_IRQ_NUM);

    FTM_StartTimer(BOARD_FTM_BASEADDR, kFTM_SystemClock); //?
}

void BOARD_InitUART(uint32_t u32UClockSpeedinHz, uint32_t u32BaudRate)
{
    uart_config_t config;

    /*
     * config.baudRate_Bps = 115200U;
     * config.parityMode = kUART_ParityDisabled;
     * config.stopBitCount = kUART_OneStopBit;
     * config.txFifoWatermark = 0;
     * config.rxFifoWatermark = 1;
     * config.enableTx = false;
     * config.enableRx = false;
     */
    UART_GetDefaultConfig(&config);
    config.baudRate_Bps = 115200U; // baudrate 9600 yapılmıştır
    config.enableTx = true;        //  önemli !!!
    config.enableRx = true;        //  önemli !!!

    UART_Init(UART0, &config, u32UClockSpeedinHz);

    /* Enable RX interrupt. */
    UART_EnableInterrupts(UART0, kUART_RxDataRegFullInterruptEnable | kUART_RxOverrunInterruptEnable);
    EnableIRQ(BOARD_UART_IRQ);
}
