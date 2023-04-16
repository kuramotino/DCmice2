/*
 * Act_Pat.cpp
 *
 *  Created on: 2023/04/16
 *      Author: Ryu
 */
#include "Act_Pat.h"
#include "BaseCommand.h"
#include "Init_Controll_Objs.h"
using namespace controll;
namespace application
{
	void App_Set_Command(enum command_type c_type)
	{
		Command bu_cm(c_type);
		cx_obj.wake_CtrlSystem(bu_cm);
		while(cx_obj.return_now_status()==Run)
		{

		}
	}
}

