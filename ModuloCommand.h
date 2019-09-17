// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _MODULO_COMMAND
#define _MODULO_COMMAND

#include "BinaryCommand.h"

template <typename T>
class ModuloCommand: public BinaryCommand<T>
{
	public:
		ModuloCommand();
		ModuloCommand(Stack<T> * initTargetStack);
		virtual T evaluate(T a, T b);	
};

#include "ModuloCommand.cpp"

#endif