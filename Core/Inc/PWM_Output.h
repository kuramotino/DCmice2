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
	enum turn {Left,Right,Back,Front};
	class PWM_Out
	{
		Command now_cm;//現在のコマンド
		CommandStatus my_cs;

		bool isDutyEnd;//Duty変換が終わったかどうか

		float now_x;//現在位置
		float now_v;//現在速度 mm/s
		float target_a;//目標加速度 mm/s^2
		float duty_R;
		float duty_L;
		float duty_FF_stra;
		float duty_FF_turn;
		float duty_FB_stra;
		float duty_FB_turn;

		enum turn cw;//turnの向き
		float V_bat=8.4;//8.4V:電源電圧
		float R=4.3;//4.3Ω:モータの端子間抵抗
		float kt=3.96;//3.96mNm/A(0.00396 Nm):トルク定数
		float m=0.117;//0.117kg:マウスの重量
		float taiya_dirmeter=11.5;//23mm:タイヤ径
		float n=4;//4:減速比
		float ke=0.000414;//0.414mV/rpm(0.000414 V/rpm) :逆起電圧定数
		float L=50;//50mm:トレッド幅
		float I=0.000543;//0.000543kg*m^2:慣性モーメント*/


	public:
		PWM_Out(void);//pwmのコンストラクタ
		void set_cs(CommandStatus &cs);//CommandStatusオブジェクトをフィールドにセットする
		void updata(Command cm);//現在のコマンドを更新(CommandExecuterに呼ばれる)
		void updata_x_v(float x,float v,bool isKasokuEnd);//kasokuから現在のxとvとフラグを取得
		void updata_PID(float ff_turn,float fb_turn);//PIDから現在のPID値を取得
		void set_pwm();//duty変換に必要なパラメータをセットする関数
		void pwm();//duty変換を行う関数
		void out_duty(float* dutyR,float* dutyL,enum turn* bu_cw);//Dutyを返す関数
		void status_off();//CommandStatusをオフにする関数
	};
}



#endif /* INC_PWM_OUTPUT_H_ */
