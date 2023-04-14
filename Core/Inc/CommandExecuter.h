/*
 * CommandExecuter.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_COMMANDEXECUTER_H_
#define INC_COMMANDEXECUTER_H_
#include "kasoku.h"
#include "PWM_Output.h"
#include "BaseCtrl.h"
#include "BaseCommand.h"
#include "CommandStatus.h"
#include <iostream>
#include <string>
#include <list>

namespace controll
{

	class CommandExecuter
	{
		std::list<controll::BaseCtrl> CtrlList;
		kasoku kasoku_listenar;
		PWM_Out pwm_listenar;
		Command set_cm;

		void addCtrl(BaseCtrl &ctrl);
		void add_kasoku_PWM(kasoku &ka,PWM_Out &pwm);
		void notify_Ctrl(Command cm);
		void notify_kasoku_PWM(Command cm);
	};
}


#endif /* INC_COMMANDEXECUTER_H_ */
