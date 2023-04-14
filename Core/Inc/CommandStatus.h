/*
 * CommandStatus.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */

#ifndef INC_COMMANDSTATUS_H_
#define INC_COMMANDSTATUS_H_

namespace controll
{
	class CommandStatus
	{
		int command_status;
	public:
		void off_command(int cs);
		void on_command(int cs);
		int show_status();
	};
}


#endif /* INC_COMMANDSTATUS_H_ */
