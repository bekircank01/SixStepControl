#include "OpenLoop.h"

void Motor_Drive(void)
{

	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0U);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0U);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0U);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0U);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
	// delay();
	FTM_Delay(15);

	// 1.sıra (dikeyde CCW tepki verdi)
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
	// delay();
	FTM_Delay(15);

	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
	// delay();
	FTM_Delay(15);

	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
	// delay();
	FTM_Delay(15);

	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
	// delay();
	FTM_Delay(15);

	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SIXTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FIFTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FOURTH_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, openloop_duty);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR3, (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, 0);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR3, true);
	// delay();
	FTM_Delay(15);
}
