#include "ClosedLoop.h"

extern int Hall_Sector_old = 0; // switch-case yapısında kullanılacak //başlangıç 0

void ClosedLoop_Motor_Drive(int comm_sector, int pwm_duty)
{

	switch (comm_sector)
	{
	case 1:

		//if(comm_pwm_update_counter > 0 ){
			//if (comm_sector != Hall_Sector_old) ////***align sonrası başlamama probleminden dolayı***
			//{

			//break;
		//}
		//else{
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);

			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
			Hall_Sector_old = 1;
		//}
		break;

	case 2:
		//if (comm_sector != Hall_Sector_old)
		//{
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);

			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
			Hall_Sector_old = 2;
		//}
		break;
	case 3:
		//if (comm_sector != Hall_Sector_old)
		//{
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);

			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
			Hall_Sector_old = 3;
		//}
		break;
	case 4:
		//if (comm_sector != Hall_Sector_old)
		//{
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);

			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
			Hall_Sector_old = 4;
		//}
		break;
	case 5:
		//if (comm_sector != Hall_Sector_old)
		//{
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0U);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0U);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);

			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
			Hall_Sector_old = 5;
		//}
		break;
	case 6:
		//if (comm_sector != Hall_Sector_old)
		//{
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, pwm_duty);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);

			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
			FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
			Hall_Sector_old = 6;
		//}
		break;

	case 7: // Hall 111-000 gelme durumunda PWM'ler sıfırlanır
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);

		FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
		FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
		break;

	default:
		//
		break;
	}
}
