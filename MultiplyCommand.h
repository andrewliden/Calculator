// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _MULT_COMMAND
#define _MULT_COMMAND

#include "BinaryCommand.h"

template <typename T>
class MultiplyCommand: public BinaryCommand<T>
{
	public:
		MultiplyCommand();
		MultiplyCommand(Stack<T> * initTargetStack);
		virtual T evaluate(T a, T b);	
};

#include "MultiplyCommand.cpp"

#endif