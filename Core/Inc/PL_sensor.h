/*
 * PL_sensor.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Ryu
 */

#ifndef INC_PL_SENSOR_H_
#define INC_PL_SENSOR_H_

extern uint16_t g_sensor_on[5];
extern uint16_t g_sensor_off[5];
extern uint16_t g_sensor_now[5];

void pl_callback_getSensor(void);
void pl_interupt_getSensor(void);
void test_adc(void);

#endif /* INC_PL_SENSOR_H_ */
