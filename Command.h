// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _COMMAND
#define _COMMAND

#include <iostream>
#include "CalculatorExceptions.h"
#include "Stack.h"

// COMMENT You should place each class in its own file to reduce the amount
// of code that has to be recompiled if you make a change to a single line
// of code. Right now, everythring has to recompile when you change lines
// that have no relation to the code that changed. This means your packaging
// is tightly coupled.
// 	RESPONSE - Took suggested action.

template <typename T>
class Command
{
	public:
		typedef T type;
		Command();
		Command(Stack<T> * initTargetStack);
		Command(Stack<T> * initTargetStack, int initPrecedence);
		void setTargetStack(Stack<T>* newTargetStack);
		virtual void execute() = 0;
		virtual int getPrecedence();
		virtual ~Command();
	protected:
		Stack<T>* targetStack;
		int precedence;
};

#include "Command.cpp"

#endif
