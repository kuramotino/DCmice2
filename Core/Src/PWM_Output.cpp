/*
 * PWM_Output.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */
#include "PWM_Output.h"
#include "BaseCommand.h"
#include "CommandStatus.h"

namespace controll
{
	controll::PWM_Out::PWM_Out(void)//pwm_outのコンストラクタ
	{
		isDutyEnd=true;
	}

	void controll::PWM_Out::set_cs(CommandStatus &cs)
	{
		my_cs=cs;
	}

	void controll::PWM_Out::updata(Command cm)//現在のコマンドを更新(CommandExecuterに呼ばれる)
	{
		now_cm=cm;
		isDutyEnd=now_cm.isStop;
	}

	void controll::PWM_Out::updata_x_v(float x,float v,bool isKasokuEnd)//kasokuから現在のxとvとフラグを取得
	{
		now_x=x;
		now_v=v;
		isDutyEnd=isKasokuEnd;
	}

	void controll::PWM_Out::updata_PID(float fb_stra,float fb_turn)//PIDから現在のPID値を取得
	{
		duty_FB_stra=fb_stra;
		duty_FB_turn=fb_turn;
	}

	void controll::PWM_Out::set_pwm()//duty変換を開始する関数
	{
		if(isDutyEnd==true)
		{
			isDutyEnd=false;
			target_a=now_cm.bu_tar_a;
		}
	}

	void controll::PWM_Out::pwm()//duty変換を行う関数
	{
		if(isDutyEnd==false)
		{
			if(now_cm.isTurn==true)
			{
				duty_FF_stra=1/V_bat*ke*(60*n*now_cm.gv/2/3.14/taiya_dirmeter);
				duty_FF_turn=1/V_bat*(R/kt*(I*target_a/L)*taiya_dirmeter/n+ke*(60*n*L*now_v/4/3.14/taiya_dirmeter));
			}
			else
			{
				duty_FF_stra=1/V_bat*(R/kt*(m*target_a/2)*taiya_dirmeter/n+ke*(60*n*now_v/2/3.14/taiya_dirmeter));
				duty_FF_turn=0;
			}

			duty_R=duty_FF_stra+duty_FF_turn+duty_FB_stra+duty_FB_turn;
			duty_L=duty_FF_stra-duty_FF_turn+duty_FB_stra-duty_FB_turn;
		}
	}

	void controll::PWM_Out::out_duty(float* dutyR,float* dutyL)
	{
		*dutyR=duty_R;
		*dutyL=duty_L;
	}

	void controll::PWM_Out::status_off()
	{
		my_cs.off_command(0);//1:通常終了
	}
}
