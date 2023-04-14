/*
 * CommandExecuter.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */
#include <iostream>
#include <string>
#include <list>
#include "CommandExecuter.h"
#include "BaseCtrl.h"
#include "BaseCommand.h"
#include "kasoku.h"
#include "PWM_Output.h"
#include "CommandStatus.h"
using namespace std;

namespace controll
{
	void controll::CommandExecuter::addCtrl(BaseCtrl &ctrl)
	{
		CtrlList.push_back(ctrl);
	}

	void controll::CommandExecuter::add_kasoku_PWM(kasoku &ka,PWM_Out &pwm)
	{
		kasoku_listenar=ka;
		pwm_listenar=pwm;
	}

	void controll::CommandExecuter::notify_Ctrl(Command cm)
	{
		std::list<controll::BaseCtrl>::iterator i;
		for(i=CtrlList.begin();i!=CtrlList.end();i++)
		{
			(*i).updata(cm);
		}
	}

	void controll::CommandExecuter::notify_kasoku_PWM(Command cm)
	{
		kasoku_listenar.updata(cm);
		pwm_listenar.updata(cm);
	}
}

