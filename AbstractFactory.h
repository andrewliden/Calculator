// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _ABS_FACTORY
#define _ABS_FACTORY

#include "Command.h"
#include "Stack.h"

// COMMENT You should place each class in its own file to reduce the amount
// of code that has to be recompiled if you make a change to a single line
// of code. Right now, everythring has to recompile when you change lines
// that have no relation to the code that changed. This means your packaging
// is tightly coupled.
	//RESPONSE Took suggested action.

template <typename T>
class AbstractCommandFactory
{
	public:
		typedef T type;
		AbstractCommandFactory();
		AbstractCommandFactory(Stack<T>* initTarget);
		virtual Command<T>* numberCommand(T inputNumber) = 0;
		virtual Command<T>* addCommand() = 0;
		virtual Command<T>* subtractCommand() = 0;
		virtual Command<T>* moduloCommand() = 0;
		virtual Command<T>* multiplyCommand() = 0;
		virtual Command<T>* divideCommand() = 0;
		virtual Command<T>* unrecognizedCommand() = 0;
		virtual Command<T>* leftParenthesisCommand() = 0;
		virtual Command<T>* rightParenthesisCommand() = 0;
	protected:
		Stack<T>* targetStack;
};

#include "AbstractFactory.cpp"

#endif
