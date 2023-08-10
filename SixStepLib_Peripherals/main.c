/**
 * @file    main.c
 * @brief   Main codes are included
 * @authors Nail Memiş - Bekir Can Karatopak
 * @details
 */

#include "main.h"

int Sector_old=0;
uint32_t sector_count=0;
float Sector_freq=0;
float Sector_mech_rpm=0;


int main(void)
{

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	PWM_Config(); // PWM config function
	// CADC_Config(); 	  //ADC config function
	Timer_Delay_Config(); // FTM1 config function
	PID_Variables_Init();
	BOARD_InitUART(CLOCK_GetFreq(kCLOCK_FastPeriphClk), 115200U);

	while (1)
	{

		//*********************ADC PART*****************
		// CADC_Value_Read();
		//*********************IPM PWM PART*************

		PID_struct.DesiredSpeed_rpm = 500;
		updatedDutycycle = PID_Output_Calculation();

		// ilk önce A fazına aling yapılıp sonra komütasyona geçilir
		if (Align_fl)
		{
			ClosedLoop_Motor_Drive(Hall_Sector, updatedDutycycle);
		}
		else
		{
			Alignment_Fcn();
		}
	}
	return 0;
}


void FTM_Delay(uint32_t ms) // milisecond delay with timer interrupt
{
	delayCounter = ms;
	while (delayCounter != 0)
	{
	}
}

/******************DELAY**************/
void BOARD_FTM1_HANDLER(void)
{ //(5 kHz çalışma hızında)

	// gelen flag time overflow ise girecek!
	if ((FTM_GetStatusFlags(BOARD_FTM_BASEADDR1) & kFTM_TimeOverflowFlag) == kFTM_TimeOverflowFlag)
	{
		/* Clear interrupt flag.*/
		FTM_ClearStatusFlags(BOARD_FTM_BASEADDR1, kFTM_TimeOverflowFlag);

		ms_div_5_count++;
		// 1 kHz işlemler kısmı
		if (ms_div_5_count >= 10)
		{
			ms_div_5_count = 0U;
			pid_calculator_count++; // Ayrık PID için
			uart_count++;			// UART transmit yapmak için
			UART_Transmit_Byte();	// UART hız datası basma kısmı


			if (delayCounter > 0)
			{
				delayCounter--;
			}
		}

		// 10 kHz işlemler kısmı
		Hall_Sensor_GPIO_Read();


		milisecondCounts++;
		if (milisecondCounts >= (second * 10))
		{
			second_cnt++;

			milisecondCounts = 0U;
		}
	}
	__DSB();
}

float PID_Output_Calculation()
{
	if (pid_calculator_count >= pid_time)
	{

		PID_struct.MeasuredSpeed_rpm = HallA_mech_rpm; //(hallA'dan okunan mekanik hız değeri(rpm))

		PID_struct.error = PID_struct.DesiredSpeed_rpm - PID_struct.MeasuredSpeed_rpm;
		PID_struct.integral = PID_struct.integralPrev + (pid_time * (PID_struct.error + PID_struct.lastError) / 2);
		PID_struct.derivative = (PID_struct.error - PID_struct.lastError) / pid_time;
		PID_struct.output = (PID_struct.error * PID_struct.values.kp) + (PID_struct.derivative * PID_struct.values.kd) + (PID_struct.integral * PID_struct.values.ki);

		if (PID_struct.output > duty_cycle_max)
		{
			PID_struct.output = duty_cycle_max;
			PID_struct.integral = PID_struct.integralPrev;
		}
		else if (PID_struct.output < 0)
		{
			PID_struct.output = 0;
			PID_struct.integral = PID_struct.integralPrev;
		}

		// updatedDutycycle = (updatedDutycycle) + (int)(PID_struct.output); //Motor sürme fonksiyonunda kullanılacak "duty cycle"
		PID_struct.lastError = PID_struct.error;
		PID_struct.integralPrev = PID_struct.integral;
		pid_calculator_count = 0;
		return PID_struct.output;
	}
	else
	{
		return PID_struct.output;
	}
}

void Hall_Sensor_GPIO_Read()
{

	////////////////////// GPIO Read PART ////////////////////////////////////////////////////////

	HallA_Status_fl = GPIO_PinRead(GPIOE, 29U);
	HallB_Status_fl = GPIO_PinRead(GPIOE, 30U);
	HallC_Status_fl = GPIO_PinRead(GPIOE, 24U);

	HallA_Status_fl_old = HallA_Status_fl;
	HallB_Status_fl_old = HallB_Status_fl;
	HallC_Status_fl_old = HallC_Status_fl;

	////////////////// HallA RPM Calculation Part ////////////////////


	if (HallA_Status_fl == 1)
	{ // HallA high rpm hesaplama kısmı

		HallA_high_cnt++;

		if (HallA_low_cnt >= 10)
		{										  // 0 yerine biraz yüksek eşik değeri verilebilir
			HallAFreq = (10000) / (HallA_low_cnt); // clock interrupt freq: 1000 Hz  //elektriksel hız
			HallA_rpm = HallAFreq * 60;			  // frequency to RPM transform     //elektriksel hız
			HallA_mech_rpm = HallA_rpm / 8;
			HallA_low_cnt = 0;
			Hall_speed_calc_cnt++;
		}
		else
		{
			HallA_low_cnt = 0;
		}
	}
	else
	{ // HallA low rpm hesaplama kısmı

		HallA_low_cnt++;

		if (HallA_high_cnt >= 10)
		{										   // 0 yerine biraz yüksek eşik değeri verilebilir
			HallAFreq = (10000) / (HallA_high_cnt); // clock interrupt freq: 1000 Hz  //elektriksel hız
			HallA_rpm = HallAFreq * 60;			   // frequency to RPM transform     //elektriksel hız
			HallA_mech_rpm = HallA_rpm / 8;
			HallA_high_cnt = 0;
			Hall_speed_calc_cnt++;
		}
		else
		{
			HallA_high_cnt = 0;
		}
	}

	// HallA zero speed calculation
	if (HallA_low_cnt > 3000 || HallA_high_cnt > 3000)
	{ // yani 2000 ms'den büyük bir beklemede hız sıfırlanır
		// HallA sensör low durumundaki hız sıfırlama
		HallA_rpm = 0;
		HallA_mech_rpm = 0;
		HallA_low_cnt = 0;
		HallA_high_cnt = 0;
	}

	// RPM Speed Moving Average Filter Part
	if(Hall_speed_calc_cnt != Hall_speed_calc_cnt_old){

		filter_sum -= filter_buffer[index];		  // en eski değer toplamdan çıkartıldı
		filter_buffer[index] = HallA_mech_rpm;	  // giriş değeri buffer'a ilgili indexine atandı
		filter_sum += filter_buffer[index];		  // giriş değeri giğer değerlerle toplandı
		index = (index + 1) % buffer_size;		  // index güncellendi
		filter_output = filter_sum / buffer_size; // çıkış değeri ortalama alınarak döndürüldü
		HallA_mech_rpm = filter_output;

		Hall_speed_calc_cnt_old = Hall_speed_calc_cnt;
	}


	////////////////////// Commutation Sector Calculation Part ////////////////////////////////////////

	if (HallA_Status_fl == 1 && HallB_Status_fl == 0 && HallC_Status_fl == 0)
	{
		Hall_Sector = 2;
	}
	else if (HallA_Status_fl == 1 && HallB_Status_fl == 1 && HallC_Status_fl == 0)
	{
		Hall_Sector = 3;
	}
	else if (HallA_Status_fl == 0 && HallB_Status_fl == 1 && HallC_Status_fl == 0)
	{
		Hall_Sector = 4;
	}
	else if (HallA_Status_fl == 0 && HallB_Status_fl == 1 && HallC_Status_fl == 1)
	{
		Hall_Sector = 5;
	}
	else if (HallA_Status_fl == 0 && HallB_Status_fl == 0 && HallC_Status_fl == 1)
	{
		Hall_Sector = 6;
	}
	else if (HallA_Status_fl == 1 && HallB_Status_fl == 0 && HallC_Status_fl == 1)
	{
		Hall_Sector = 1; // 6 idi, değiştirdim 1 yaptım
	}
	else
	{
		// hata bayrağı kaldır
		SectorError_fl++;
		Hall_Sector = 7;
	}

	////////////Sektör Üzerinden Hız Hesaplama Bölümü/////////////////

	/* if(Sector_old == Hall_Sector){
		sector_count++;
	}else{
		//count hız hesaplama;
		if(sector_count >=2){
			Sector_freq = (10000) / (sector_count);
			Sector_mech_rpm=Sector_freq*(2.5);
			sector_count=0;
			Hall_speed_calc_cnt++;
		}
		else{
			Sector_mech_rpm=0;
		}

		Sector_old=Hall_Sector;
		*/
	}


void UART_Transmit_Byte()
{

	if (uart_count >= 2)
	{
		uart_count = 0;
		send_tx = HallA_mech_rpm ;
		//send_tx=HallA_high_cnt;
		sprintf(txbuff, "%d\n\n", send_tx);
		// UART Transmit Part
		while(txIndex < 4){
			if ((kUART_TxDataRegEmptyFlag || kUART_TransmissionCompleteFlag) && UART_GetStatusFlags(UART0) )// && txIndex < 4)
			{
				UART_WriteByte(UART0, txbuff[txIndex]);
				txIndex++;
			}

		}
		txIndex=0;
	}
}

void BOARD_UART_IRQ_HANDLER()
{
	uint8_t data;

	/* If new data arrived. */
	if ((kUART_RxDataRegFullFlag | kUART_RxOverrunFlag) && UART_GetStatusFlags(UART0))
	{
		data = UART_ReadByte(UART0);
		/* If ring buffer is not full, add data to ring buffer. */
		if (rxIndex < 7)
		{
			rxbuff[rxIndex] = data;
			rxIndex++;
		}
		if (rxbuff[0] == 35 && rxIndex == 6)
		{
			// tx_on = 1;
			rxIndex = 0;
			rxbuff_old[0] = rxbuff[1];
			rxbuff_old[1] = rxbuff[2];
			rxbuff_old[2] = rxbuff[3];
			rxbuff_old[3] = rxbuff[4];
			rxbuff_old[4] = rxbuff[5];

			if (rxbuff_old[4] == 10) // üç haneli  "\n" ASCİİ karşılığı=10 ise
			{
				rxbuff_old[0] = rxbuff[1] - 48; //"0" ascii karşılığı 48 olduğu için
				rxbuff_old[1] = rxbuff[2] - 48;
				rxbuff_old[2] = rxbuff[3] - 48;
				rxbuff_old[3] = rxbuff[4] - 48;
				ref_hiz = rxbuff_old[0] * 100 + rxbuff_old[1] * 10 + rxbuff_old[2];
				if (rxbuff_old[3] == 0) // start-stop bit koşulu
				{
					Current_Task = STOP;
					// updatedDutycycle = 0;  //bunu sıfır yapılmasına gerek yok
					// Referans hız sıfır olmalı;
					PID_struct.DesiredSpeed_rpm = 0;
					Align_fl = 0;
				}
				if (rxbuff_old[3] == 1)
				{
					Current_Task = START; // HUZA GÖRE HESAPLANACAK
					// updatedDutycycle = 80;  //buna değer verilmeyecek
					// updatedDutycycle = updatedDutycycle + (int)(PID_Output_Calculation());   //buna değer verilmeyecek
					PID_struct.DesiredSpeed_rpm = ref_hiz; // UART'tan gelen hız PID hesaplamasına girecek
				}
			}
		}
	}

	SDK_ISR_EXIT_BARRIER;
}

void Alignment_Fcn(){

	if ( (Hall_Sector == 1 || Hall_Sector == 2)  && Current_Task == START)  //sector değeri 1 veya 2 arasında değişiyor
	{
		// normalde hall sector 2 idi
		Align_fl = 1;
	}
	else{
		// 65 eğerini kafamdan verdim, çalışılan voltaja göre değişir
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 60);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 60);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 60);
		FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
		FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
		FTM_Delay(15); // 15 ms delay
	}
}



