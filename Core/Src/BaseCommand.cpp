/*
 * BaseCommand.cpp
 *
 *  Created on: Apr 13, 2023
 *      Author: Ryu
 */
#include "BaseCommand.h"
namespace controll
{
	controll::Command::Command()
	{
		bu_tar_a=3000;//1目標加速度
						bu_tar_v_start=100;//2目標初速度
						bu_tar_v_max=500;//3目標最高速度
						bu_tar_v_end=100;//4目標終端速度
						bu_tar_x=360;//5目標距離
						gv=800;//6重心速度
						isStop=false;//stopさせるかどうか
						isFailStop=false;//FailSafeでstopさせるか
						isPID_Stop=false;//PIDをstopさせるか
						isTurn=false;//turnかどうか
	}

	controll::Command::Command(enum command_type type)
	{
		switch (type)
		{
			case Stra:
				bu_tar_a=3000;//1目標加速度
				bu_tar_v_start=0;//2目標初速度
				bu_tar_v_max=300;//3目標最高速度
				bu_tar_v_end=0;//4目標終端速度
				bu_tar_x=300;//5目標距離
				gv=500;//6重心速度
				isStop=false;//stopさせるかどうか
				isFailStop=false;//FailSafeでstopさせるか
				isPID_Stop=false;//PIDをstopさせるか
				isTurn=false;//turnかどうか
				break;

			case Left_sla:
				break;

			case Right_sla:
				break;

			case Stop:
				isStop=true;
				break;

			case Fail_Stop:
				isStop=true;
				isFailStop=true;
				break;

		}
	}
}

