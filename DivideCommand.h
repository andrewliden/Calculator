// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _DIV_COMMAND
#define _DIV_COMMAND

#include "BinaryCommand.h"

template <typename T>
class DivideCommand: public BinaryCommand<T>
{
	public:
		DivideCommand();
		DivideCommand(Stack<T> * initTargetStack);
		virtual T evaluate(T a, T b);	
};

#include "DivideCommand.cpp"

#endif