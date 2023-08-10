/**
 * @file    main.h
 * @brief   Main codes definition are included
 * @authors MemisNail Can Bekir
 * @details
 */

#include "ClosedLoop.h"

void Alignment_Fcn(void);
void BOARD_UART_IRQ_HANDLER(void);
float PID_Output_Calculation();
void UART_Transmit_Byte();
void Hall_Sensor_GPIO_Read();
void FTM_Delay(uint32_t ms);

//////EXTRA DENEMELER İÇİN KULLANILAN PARAMETRELER/////
int openloop_duty_test=65;
int drive_mode_switch=0;
int openloop_fl=0;

int Hall_speed_calc_cnt=0;
int Hall_speed_calc_cnt_old=0;
///////////////////////////////////////////////////////


uint8_t txbuff[3] = {0};
uint8_t rxIndex;
uint8_t txIndex=0;
uint8_t tx_on = 0;
uint8_t rxbuff[6] = {0};
uint8_t rxbuff_old[20] = {0};

float ref_hiz = 0;
typedef enum
{
	IDLE,
	STOP,
	START
} Task;
Task Current_Task = START;
int16_t send_tx;

int updatedDutycycle = 0; // PWM duty cycle ratio

volatile uint32_t milisecondCounts = 0U;
int ms_div_5_count = 0;
uint32_t second_cnt = 0;
uint32_t second = 1000U;
uint32_t delayCounter = 0; // ms delay counter
int uart_count = 0;

/*-----HALL SENSOR PARAMETERS------------------------------------------------*/
int HallA_Status_fl = 0; // Hall A için 1-0 durumlarını gösteren flag
int HallA_Status_fl_old = 0;
int HallB_Status_fl = 0; // Hall B için 1-0 durumlarını gösteren flag
int HallB_Status_fl_old = 0;
int HallC_Status_fl = 0; // Hall C için 1-0 durumlarını gösteren flag
int HallC_Status_fl_old = 0;

int Hall_Sector = 6;	 // alignment için 10 yapıldı!!!
int SectorError_fl = 0;
_Bool Align_fl = 0;

/*-----HALL SENSOR SPEED CALC. PARAMETERS------------------------------------------------*/

// HALL A Variables
float HallA_low_cnt = 0;
float HallA_high_cnt = 0;
float HallAFreq = 0;
float HallA_rpm = 0;
float HallA_mech_rpm = 0;

// Speed Filter Parameters
#define buffer_size 6		  // buffer boyutu
float filter_buffer[buffer_size]; // buffer için dizi tanımlama
float filter_sum = 0;			  // ölçüm toplamını tutacak
float filter_output = 0;		  // filtre fonksiyonu çikiş değeri
int index;						  // buffer içindeki elemanları belirtmek için index

/*-----PID Speed Controller PARAMETERS----------------------------------------------------*/
#define pid_time 1		   //1000 Hz
#define duty_cycle_max 100
float pid_calculator_count;

/*-----PID CONTROLLER PARAMETERS------------------------------------------------*/

struct pidStruct
{
	float MeasuredSpeed_rpm; //???
	float DesiredSpeed_rpm;
	float error;
	float lastError;
	float derivative;
	float integral;
	float integralPrev;
	float output;
	struct
	{
		float kp, ki, kd;
	} values;
} PID_struct;

void PID_Variables_Init(void)
{
	PID_struct.MeasuredSpeed_rpm = 0;
	PID_struct.DesiredSpeed_rpm = 0; // desired speed değeri
	PID_struct.error = 0;
	PID_struct.lastError = 0;
	PID_struct.derivative = 0;
	PID_struct.integral = 0;
	PID_struct.integralPrev = 0;
	PID_struct.output = 0;			// 0-100 arasında PWM duty cycle değeri alır
	PID_struct.values.kp = 0.03;	// ilk deneme: 0.03
	PID_struct.values.ki = 0.0003; // ilk deneme: 0.000004  26mayıs: 0.00022
	PID_struct.values.kd = 0;
}
