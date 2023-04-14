/*
 * CommandStatus.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */
#include "CommandStatus.h"

namespace controll
{
	void controll::CommandStatus::off_command(int cs)
	{
		if(cs<=0)
		{
			command_status=cs;
		}
	}

	void controll::CommandStatus::on_command(int cs)
	{
		if(cs>0)
		{
			command_status=cs;
		}
	}

	int controll::CommandStatus::show_status()
	{
		return command_status;
	}
}
