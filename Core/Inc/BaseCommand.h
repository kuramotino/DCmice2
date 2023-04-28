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
	enum command_type{Stra,Left_sla,Right_sla,Left_sen,Right_sen,Stra_Back,Left_f_off,Left_b_off,Mid_Stra,Stop,Fail_Stop,Break_Stop};
	class Command
	{
	public:
		float bu_tar_a=1000;//目標加速度
		float bu_tar_v_start=0;//目標初速度
		float bu_tar_v_max=500;//目標最高速度
		float bu_tar_v_end=0;//目標終端速度
		float bu_tar_x=500;//目標距離
		float gv=500;//重心速度
		bool isStop=false;//stopさせるかどうか
		bool isFailStop=false;//FailSafeでstopさせるか
		bool isBreakStop=false;//Breakをかけるか
		bool isPID_Stop=false;//PIDをstopさせるか
		bool isTurn=false;//turnかどうか

	public:
		Command();
		Command(enum command_type type);//Commandのコンストラクタ*/

	};
}


#endif /* INC_BASECOMMAND_H_ */
