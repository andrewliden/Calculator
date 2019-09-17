// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "ModuloCommand.h"
#include <cmath>

template <typename T>
ModuloCommand<T>::ModuloCommand()
:BinaryCommand<T>(nullptr, MODULO_PRC)
{
	
}

template <typename T>
ModuloCommand<T>::ModuloCommand(Stack<T> * initTargetStack)
:BinaryCommand<T>(initTargetStack, MODULO_PRC)
{
	
}

template <typename T>
T ModuloCommand<T>::evaluate(T a, T b)
{
	if(b == 0)
		throw CalculatorException::byZero();
	T quotient = floor((double) a / b);
	T modulo = a - quotient * b;
	return modulo;
}