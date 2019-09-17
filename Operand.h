#ifndef _OPERAND
#define _OPERAND

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "Command.h"

template <typename T>
class Operand : public Command<T>
{
	public:
		Operand();
		Operand(Stack<T> * initTargetStack, T initValue);
		virtual void execute();
		void setValue(T newValue);
	private:
		T value;
};

#include "Operand.cpp"

#endif