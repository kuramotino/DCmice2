/*
 * InputData.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_INPUTDATA_H_
#define INC_INPUTDATA_H_
#include "stdio.h"

namespace controll
{
	class InputData
	{
	public:
		float v_encoder;//エンコーダから取得した機体の速度
		float enc_v_R;//エンコーダから取得した右タイヤの速度
		float enc_v_L;//エンコーダから取得した左タイヤの速度
		int16_t enc_v_R_sum;//右エンコーダの合計値
		int16_t enc_v_L_sum;//左エンコーダの合計値
		float omega_gyro;//ジャイロから取得した機体の角速度
	};
}


#endif /* INC_INPUTDATA_H_ */
