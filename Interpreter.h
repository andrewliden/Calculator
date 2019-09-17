// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _INTERPRETER
#define _INTERPRETER

#include <cctype>
#include <iostream>
#include <sstream>
#include "AbstractInterpreter.h"
#include "Command.h"
#include "ConcreteFactory.h"
#include "ConcreteBuilder.h"
#include "Invoker.h"
#include "Queue.h"
#include "Stack.h"

class Interpreter : public AbstractInterpreter
{
	public:
		Interpreter();
		Interpreter(Invoker* initInvoker);
		//Interprets all commands in input and gives the resulting commands
		//to the invoker.  Clears input when done.
		void interpret();
		//exception class used for mismatched parentheses
		class missingParenthesis {};
	private:
		//Helper method to interpret one command and return a command pointer.
		Command<int>* interpretToken(std::string command, AbstractCommandFactory<int>* commandFactory);
		//Takes the string in input and converts it into a stack of postfix commands.
		Queue<Command<int>*> inputToPostfix();
		
		std::string input;
		Invoker * targetInvoker;
};

#endif