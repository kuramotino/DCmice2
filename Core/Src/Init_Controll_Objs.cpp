/*
 * Init_Controll_Objs.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: Ryu
 */
#include "Init_Controll_Objs.h"
#include "tim.h"
controll::CommandExecuter cx_obj;
controll::kasoku ksk_obj;
controll::PWM_Out pwm_obj;
controll::CommandStatus cs_obj;
controll::Command com_obj;
controll::InputData input_obj;
module::Enc enc_obj;
module::Gyro gyro_obj;
controll::PID_Ctrl pid_obj;
controll::FailSafe fail_obj;
bool init_flag=false;
using namespace controll;

void Init_Controll()//controll,module名前空間のオブジェクトたちを初期化する
{
	cx_obj.addCtrl(&pid_obj);
	cx_obj.addCtrl(&fail_obj);
	cx_obj.add_kasoku_PWM(&ksk_obj, &pwm_obj);
	cx_obj.set_cs(&cs_obj);
	ksk_obj.add_pwm(&pwm_obj);
	pwm_obj.set_cs(&cs_obj);
	enc_obj.add_input(&input_obj);
	enc_obj.pl_encoder_init();
	gyro_obj.add_input(&input_obj);
	gyro_obj.gyro_init();
	pid_obj.add_obj(&ksk_obj, &pwm_obj, &input_obj, &cs_obj);
	fail_obj.add_obj(&ksk_obj, &pwm_obj, &input_obj, &cs_obj);
	init_flag=true;
}

void Sync_Module()//TIM6の割り込み処理
{
	if(init_flag==true)
	{
	cx_obj.polling_cs();
	enc_obj.sensor_input();
	gyro_obj.sensor_input();
	ksk_obj.daikei();
	ksk_obj.transmit_pwm();//isKasokuEnd==trueならCommandStatusをオフにする
	pid_obj.PID();
	fail_obj.FailStop();
	pwm_obj.pwm();
	}
}

void Sync_Mo_R()//右モータの割り込み処理
{
	float duty_r;
	float duty_l;
	enum turn cw;
	pwm_obj.out_duty(&duty_r, &duty_l,&cw);

	if(cw==Front || cw==Left)
	{
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,(uint16_t)(10000*duty_r));
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,0);
		__HAL_TIM_SET_COUNTER(&htim3, 0);
	}
	else if(cw==Back || cw==Right)
	{
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,0);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,(uint16_t)(10000*duty_r));
		__HAL_TIM_SET_COUNTER(&htim3, 0);
	}
}

void Sync_Mo_L()//左モータの割り込み処理
{
	float duty_r;
	float duty_l;
	enum turn cw;
	pwm_obj.out_duty(&duty_r, &duty_l,&cw);

	if(cw==Front || cw==Right)
	{
		__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,(uint16_t)(10000*duty_l));
		__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,0);
		__HAL_TIM_SET_COUNTER(&htim12, 0);
	}
	else if(cw==Back || cw==Left)
	{
		__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,0);
		__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,(uint16_t)(10000*duty_l));
		__HAL_TIM_SET_COUNTER(&htim12, 0);
	}
}

