// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _CONC_FACTORY
#define _CONC_FACTORY

#include "AbstractFactory.h"
#include "UnrecognizedCommand.h"
#include "Operand.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "ModuloCommand.h"
#include "MultiplyCommand.h"
#include "DivideCommand.h"
#include "LeftParenthesisCommand.h"
#include "RightParenthesisCommand.h"

template <typename T>
class ConcreteCommandFactory : public AbstractCommandFactory<T>
{
	public:
		ConcreteCommandFactory();
		ConcreteCommandFactory(Stack<T> * initTarget);
		virtual Command<T>* numberCommand(T inputNumber);
		virtual Command<T>* addCommand();
		virtual Command<T>* subtractCommand();
		virtual Command<T>* moduloCommand();
		virtual Command<T>* multiplyCommand();
		virtual Command<T>* divideCommand();
		virtual Command<T>* unrecognizedCommand();
		virtual Command<T>* leftParenthesisCommand();
		virtual Command<T>* rightParenthesisCommand();
};

#include "ConcreteFactory.cpp"

#endif