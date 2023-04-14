/*
 * BaseCommand.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Ryu
 */

#ifndef INC_BASECOMMAND_H_
#define INC_BASECOMMAND_H_

namespace controll
{
	class Command
	{
	public:
		float bu_tar_a;//目標加速度
		float bu_tar_v_start;//目標初速度
		float bu_tar_v_max;//目標最高速度
		float bu_tar_v_end;//目標終端速度
		float bu_tar_x;//目標距離
		float gv;//重心速度
		bool isStop;//stopさせるかどうか
		bool isTurn;//turnかどうか
	};
}


#endif /* INC_BASECOMMAND_H_ */
