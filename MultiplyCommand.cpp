// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden


#include "MultiplyCommand.h"

template <typename T>
MultiplyCommand<T>::MultiplyCommand()
:BinaryCommand<T>(nullptr, MUL_PRC)
{
	
}

template <typename T>
MultiplyCommand<T>::MultiplyCommand(Stack<T> * initTargetStack)
:BinaryCommand<T>(initTargetStack, MUL_PRC)
{
	
}

template <typename T>
T MultiplyCommand<T>::evaluate(T a, T b)
{
	T result = a * b;
	//Detect overflow and underflow.
	if(a != 0 and b != 0)
	{
		if(result / a != b or result / b != a)
			throw CalculatorException::overflow();
	}
	return a * b;
}