// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _LEFTP_COMMAND
#define _LEFTP_COMMAND

#include "Command.h"

template <typename T>
class LeftParenthesisCommand: public Command<T>
{
	public:
		LeftParenthesisCommand();
		void execute();
};

#include "LeftParenthesisCommand.cpp"

#endif