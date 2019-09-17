// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "Operand.h"

template <typename T>
Operand<T>::Operand()
:Command<T>(nullptr, OPERAND_PRC), value(0)
{
	
}

template <typename T>
Operand<T>::Operand(Stack<T> * initTargetStack, T initValue)
:Command<T>(initTargetStack, OPERAND_PRC), value(initValue)
{
	
}

template <typename T>
void Operand<T>::execute()
{
	this->targetStack->push(value);
}

template <typename T>
void Operand<T>::setValue(T newValue)
{
	value = newValue;
}