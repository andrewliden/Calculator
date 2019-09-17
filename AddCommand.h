// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _ADD_COMMAND
#define _ADD_COMMAND

#include "BinaryCommand.h"

template <typename T>
class AddCommand : public BinaryCommand<T>
{
	public:
		AddCommand();
		AddCommand(Stack<T> * initTargetStack);
		virtual T evaluate(T a, T b);
};

#include "AddCommand.cpp"

#endif