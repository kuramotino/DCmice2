/*
 * PWM_Output.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_PWM_OUTPUT_H_
#define INC_PWM_OUTPUT_H_
#include "BaseCommand.h"
#include "CommandStatus.h"

namespace controll
{
	class PWM_Out
	{
		Command now_cm;//現在のコマンド
		CommandStatus my_cs;

		bool isDutyEnd;//Duty変換が終わったかどうか

		float now_x;//現在位置
		float now_v;//現在速度
		float target_a;//目標加速度
		float duty_R;
		float duty_L;
		float duty_FF_stra;
		float duty_FF_turn;
		float duty_FB_stra;
		float duty_FB_turn;

		float V_bat=8.4;//8.4V:電源電圧
		float R=4.3;//4.3Ω:モータの端子間抵抗
		float kt=3.96;//3.96mNm/A:トルク定数
		float m=0.5;//0.5kg:マウスの重量
		float taiya_dirmeter=23;//23mm:タイヤ径
		float n=4;//4:減速比
		float ke=0.414;//0.414mV/rpm:逆起電圧定数
		float L=50;//50mm:トレッド幅
		float I=0.00052;//0.00052kg*m^2:慣性モーメント*/


	public:
		PWM_Out(void);
		void set_cs(CommandStatus &cs);
		void updata(Command cm);
		void updata_x_v(float x,float v,bool isKasokuEnd);
		void updata_PID(float ff_turn,float fb_turn);
		void set_pwm();
		void pwm();
		void out_duty(float* dutyR,float* dutyL);
		void status_off();
	};
}



#endif /* INC_PWM_OUTPUT_H_ */
