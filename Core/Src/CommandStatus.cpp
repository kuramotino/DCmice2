/*
 * CommandStatus.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */
#include "CommandStatus.h"

namespace controll
{
	void controll::CommandStatus::off_command(enum status cs)
	{
		if(cs!=Run)
		{
			command_status=cs;
		}
	}

	void controll::CommandStatus::on_command(enum status cs)
	{
		if(cs==Run)
		{
			command_status=cs;
		}
	}

	enum status controll::CommandStatus::show_status()
	{
		return command_status;
	}
}
