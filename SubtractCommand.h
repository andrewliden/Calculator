// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "BinaryCommand.h"

#ifndef _SUBTR_COMMAND
#define _SUBTR_COMMAND

#include "BinaryCommand.h"

template <typename T>
class SubtractCommand : public BinaryCommand<T>
{
	public:
		SubtractCommand();
		SubtractCommand(Stack<T> * initTargetStack);
		virtual T evaluate(T a, T b);
};

#include "SubtractCommand.cpp"

#endif