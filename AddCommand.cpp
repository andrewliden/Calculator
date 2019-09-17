#include "AddCommand.h"

template <typename T>
AddCommand<T>::AddCommand()
:BinaryCommand<T>(nullptr, ADD_PRC)
{
		
}

template <typename T>
AddCommand<T>::AddCommand(Stack<T> * initTargetStack)
:BinaryCommand<T>(initTargetStack, ADD_PRC)
{
	
}

template <typename T>
T AddCommand<T>::evaluate(T a, T b)
{
	T result = a + b;
	//Detect overflow and underflow.
	if(a > 0 and b > 0 and result < 0)
		throw CalculatorException::overflow();
	if(a < 0 and b < 0 and result > 0)
		throw CalculatorException::underflow();
	return result;
}