/*
 * encoder.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Ryu
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "stm32f4xx_hal.h"

void pl_encoder_init();

int16_t pl_count_encoderR1(void);
int16_t pl_count_encoderL(void);

#endif /* INC_ENCODER_H_ */
