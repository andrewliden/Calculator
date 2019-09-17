// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "LeftParenthesisCommand.h"

template <typename T>
LeftParenthesisCommand<T>::LeftParenthesisCommand()
:Command<T>(nullptr, LEFT_PAREN_PRC)
{
	
}

template <typename T>
void LeftParenthesisCommand<T>::execute()
{
	//Parentheses shouldn't ever get a chance to execute.  If they do something went wrong.  Throw an exception.
	throw CalculatorException::leftoverParenthesis();
}