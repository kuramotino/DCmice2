/*
 * encoder.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Ryu
 */
#include <main.h>
#include "encoder.h"
#include "tim.h"
#include "stm32f4xx_hal.h"

void pl_encoder_init(void){
	HAL_TIM_Base_Start_IT(&htim1);//1エンコーダーR
	HAL_TIM_Base_Start_IT(&htim8);//2エンコーダーL

	HAL_TIM_Encoder_MspInit(&htim1);//1エンコーダーR
	HAL_TIM_Encoder_MspInit(&htim8);//2エンコーダーL

	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL);
}

int16_t pl_count_encoderR(void) {
	int16_t count = 0;
	uint16_t enc_count = TIM1->CNT;
	TIM1->CNT = 0;

	if (enc_count > 32767) {
		count = (int16_t) enc_count;
	} else {
		count = (int16_t) enc_count;
	}

	return count;
}

int16_t pl_count_encoderL(void) {
	int16_t count = 0;
	uint16_t enc_count = TIM8->CNT;
	TIM8->CNT = 0;

	if (enc_count > 32767) {
		count = -(int16_t) enc_count;
	} else {
		count = -(int16_t) enc_count;
	}

	return count;
}

