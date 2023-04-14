/*
 * InputData.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_INPUTDATA_H_
#define INC_INPUTDATA_H_

namespace controll
{
	class InputData
	{
	public:
		float v_encoder;//エンコーダから取得した機体の速度
		float omega_gyro;//ジャイロから取得した機体の角速度
	};
}


#endif /* INC_INPUTDATA_H_ */
