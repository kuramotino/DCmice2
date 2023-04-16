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
	enum command_type{Stra,Left_sla,Right_sla,Left_sen,Right_sen,Stra_Back,Stop,Fail_Stop};
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
		bool isFailStop;//FailSafeでstopさせるか
		bool isPID_Stop;//PIDをstopさせるか
		bool isTurn;//turnかどうか

	public:
		Command();
		Command(enum command_type type);//Commandのコンストラクタ*/

	};
}


#endif /* INC_BASECOMMAND_H_ */
