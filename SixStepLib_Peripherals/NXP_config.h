/**
 * @file    NXP_config.h
 * @brief   Processor Specicific declerations are included
 * @authors MemisNail Can Bekir
 * @details
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKV42F16.h"
#include "fsl_debug_console.h"
#include "fsl_cadc.h"
#include "fsl_gpio.h"
#include "fsl_ftm.h"
#include "fsl_xbara.h"
#include "fsl_enc.h"
#include "fsl_uart.h"

#define BOARD_UART_IRQ UART0_RX_TX_IRQn
#define BOARD_UART_IRQ_HANDLER UART0_RX_TX_IRQHandler

/* Interrupt number and interrupt handler for the FTM0 and FTM1 instance used */
#define BOARD_FTM_IRQ_NUM FTM0_IRQn
#define BOARD_FTM1_IRQ_NUM FTM1_IRQn
#define FTM_INPUT_CAPTURE_HANDLER FTM0_IRQHandler // FTM0 IRQ
#define BOARD_FTM1_HANDLER FTM1_IRQHandler        // FTM1 IRQ
/* Get source clock for FTM driver */
#define FTM_SOURCE_CLOCK CLOCK_GetFreq((kCLOCK_FastPeriphClk))

/*-----FLEX TIMER PARAMETERS------------------------------------------------*/
/* The Flextimer instance/channel used for board */
#define BOARD_FTM_BASEADDR FTM0     // to generate PWM !!
#define BOARD_FTM_BASEADDR1 FTM1    // to capture signal !!
#define BOARD_FTM_BASEADDR3 FTM3    // to generate PWMv!!
#define BOARD_FIRST_FTM_CHANNEL 0U  // PWM_W_low
#define BOARD_SECOND_FTM_CHANNEL 1U // PWM_W_high
#define BOARD_THIRD_FTM_CHANNEL 2U  // PWM_V_low
#define BOARD_FOURTH_FTM_CHANNEL 3U // PWM_V_high
#define BOARD_FIFTH_FTM_CHANNEL 4U  // PWM_U_low
#define BOARD_SIXTH_FTM_CHANNEL 5U  // PWM_U_high

/*-----ADC PARAMETERS----------------------------------------------------*/
#define DEMO_CADC_BASEADDR ADC
// #define BEMF_U_CADC_CHANNEL  4U    //ADCA channel_4-> bemf u phase
// #define BEMF_V_CADC_CHANNEL  5U    //ADCA channel_5 -> bemf v phase
// #define BEMF_W_CADC_CHANNEL  12U    //ADCB channel_4 -> bemf w phase           (!!! adress: b1100)
#define CURRENT_U_CADC_CHANNEL 9U // ADCB channel_1 -> current u phase         (!!! adress: b1001)
#define CURRENT_V_CADC_CHANNEL 1U // ADCA channel_1 -> current v phase
#define CURRENT_W_CADC_CHANNEL 0U // ADCA channel_0 -> current w phase
#define IPM_TEMP_CADC_CHANNEL 7U  // ADCA channel_7g -> ipm temperature value
#define DC_BUS_CADC_CHANNEL 11U   // ADCB channel_3 -> board DC voltage value (!!! adress: b1011)

extern void BOARD_InitUART(uint32_t u32UClockSpeedinHz, uint32_t u32BaudRate);
extern void PWM_Config(void);
extern void Timer_Delay_Config(void);
extern void CADC_Config(void);
extern void Hall_Config(void);