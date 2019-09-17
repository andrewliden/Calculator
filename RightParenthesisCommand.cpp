// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "RightParenthesisCommand.h"

template <typename T>
RightParenthesisCommand<T>::RightParenthesisCommand()
:Command<T>(nullptr, RIGHT_PAREN_PRC)
{
	
}

template <typename T>
void RightParenthesisCommand<T>::execute()
{
	throw CalculatorException::leftoverParenthesis();
}