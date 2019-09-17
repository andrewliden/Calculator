// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "SubtractCommand.h"

template <typename T>
SubtractCommand<T>::SubtractCommand()
:BinaryCommand<T>(nullptr, SUB_PRC)
{
	
}

template <typename T>
SubtractCommand<T>::SubtractCommand(Stack<T> * initTargetStack)
:BinaryCommand<T>(initTargetStack, SUB_PRC)
{
	
}

template <typename T>
T SubtractCommand<T>::evaluate(T a, T b)
{
	T result = a - b;
	//Detect overflow and underflow.
	if(a > 0 and b < 0 and result < 0)
		throw CalculatorException::overflow();
	if(a < 0 and b > 0 and result > 0)
		throw CalculatorException::underflow();
	return result;
}