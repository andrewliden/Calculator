#ifndef ABSTRACT_INTERPRETER
#define ABSTRACT_INTERPRETER

#include <iostream>

class AbstractInterpreter
{
	public:
		AbstractInterpreter();
		void takeInput();
		std::string getText();
		virtual void interpret() = 0;
		virtual ~AbstractInterpreter();
	protected:
		//Helper method to analyze a token to determine if it is an operand.
		bool isOperand(std::string token);
		//Helper method to analyze if a token is a variable.
		bool isVariable(std::string token);
		std::string input;
};

#endif