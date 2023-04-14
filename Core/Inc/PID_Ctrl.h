/*
 * PID_Ctrl.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_PID_CTRL_H_
#define INC_PID_CTRL_H_
#include "BaseCtrl.h"

namespace controll
{
	class PID_Ctrl : public BaseCtrl
	{
		float fb_stra;
		float fb_turn;
		float v_encoder;//エンコーダから求めた速度
		float omega_gyro;//ジャイロから求めた角速度
		float now_v;//kasokuから得た速度
		float now_omega;//kasokuから得た角速度

		float enc_error;//エンコーダの差分
		float enc_sigma_error;//エンコーダの差分の和
		float enc_old_error;//前回のエンコーダの差分
		float enc_delta_error;//前回と今回のerrorの差分
		float gy_error;//ジャイロの差分
		float gy_sigma_error;//ジャイロの差分の和
		float gy_old_error;//前回のジャイロの差分
		float gy_delta_error;//前回と今回のerrorの差分

		float V_bat=8.4;//8.4V:電源電圧
		float Ksp;//直進のPゲイン
		float Ksi;//直進のIゲイン
		float Ksd;//直進のDゲイン
		float Ktp;//回転のPゲイン
		float Kti;//回転のIゲイン
		float Ktd;//回転のDゲイン

		void transmit_PID();//pwmに求めたpid値を送る関数
		void get_enc_gyro();//kasokuとinputdataから速度、角速度、計算した速度を取得する
		void PID();//PID値を計算する
	};
}

#endif /* INC_PID_CTRL_H_ */
