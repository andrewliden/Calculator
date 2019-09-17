#include "AbstractInterpreter.h"
#include <stdio.h>
#include <stdlib.h>

AbstractInterpreter::AbstractInterpreter()
:input("")
{
	
}

void AbstractInterpreter::takeInput()
{
	std::cout << "Enter an expression, or type QUIT to quit." << std::endl;
	getline(std::cin, input);
}

std::string AbstractInterpreter::getText()
{
	return input;
}

//Helper function to determine if a given token is an operand.
bool AbstractInterpreter::isOperand(std::string token)
{
	bool operand = true;
	int i = 0;
	for(auto tokenChar : token)
	{
		//If this isn't a digit, assume that this isn't a numeric operator.		
		if(!isdigit(tokenChar))
			operand = false;
		//To correct for false positives on negative numbers,
		//If this is the first character, and the length of the token is greater than 1,
		//and this character is -, this is still an operand.
		if(i == 0)
			if(token.length() > 1)
				if(tokenChar == '-')
					operand = true;
		i++;
	}
	return operand;
}

bool AbstractInterpreter::isVariable(std::string token)
{
	//Returns true when the length of the token is 1 and it is an alphabetic letter.
	return (token.length() == 1 and isalpha(token[0]));
}

AbstractInterpreter::~AbstractInterpreter()
{
	
}