/*
 * kasoku.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_KASOKU_H_
#define INC_KASOKU_H_
#include "BaseCommand.h"
#include "PWM_Output.h"

namespace controll
{
	class kasoku
	{
		bool isKasokuEnd;//加速が終わったかどうか

		float now_x;//現在の位置
		float dt;//刻み時間1ms
		float target_a;//加速度
		float target_v_start;//初速度
		float now_v;//現在の速度
		float target_v_max;//最大速度
		float target_v_end;//終端速度
		float target_x;//目標距離
		float xde;//減速距離

		Command now_cm;//現在のコマンド
		PWM_Out my_pwm;//pwmのオブジェクト



		kasoku();
		void set_kasoku();
		void daikei();
		void add_pwm(PWM_Out &pwm);//pwm_outオブジェクトを登録する
	public:
		void updata(Command cm);//コマンドを更新する(CommandExecuterに呼ばれる)
		void transmit_pwm();//pwm_outに計算した速度と位置とフラグを送る関数
		float show_v();//now_vを返す関数(PID_Ctrlに呼ばれる)
	};
}


#endif /* INC_KASOKU_H_ */
