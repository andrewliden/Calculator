// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "DivideCommand.h"

template <typename T>
DivideCommand<T>::DivideCommand()
:BinaryCommand<T>(nullptr, DIV_PRC)
{
	
}

template <typename T>
DivideCommand<T>::DivideCommand(Stack<T> * initTargetStack)
:BinaryCommand<T>(initTargetStack, DIV_PRC)
{
	
}

template <typename T>
T DivideCommand<T>::evaluate(T a, T b)
{
	if(b == 0)
		throw CalculatorException::byZero();
	return a / b;
}