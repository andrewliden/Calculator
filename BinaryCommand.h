// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _BIN_COMMAND
#define _BIN_COMMAND

#include "Command.h"

template <typename T>
class BinaryCommand : public Command<T>
{
	public:
		BinaryCommand();
		BinaryCommand(Stack<T> * initTargetStack, int initPrecedence);
		virtual void execute();
		virtual T evaluate(T a, T b) = 0;
};

#include "BinaryCommand.cpp"

#endif