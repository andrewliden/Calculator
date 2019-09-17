// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _RIGHTP_COMMAND
#define _RIGHTP_COMMAND

#include "Command.h"

template <typename T>
class RightParenthesisCommand: public Command<T>
{
	public:
		RightParenthesisCommand();
		void execute();
};

#include "RightParenthesisCommand.cpp"

#endif