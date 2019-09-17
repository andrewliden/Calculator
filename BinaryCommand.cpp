// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "BinaryCommand.h"

template <typename T>
BinaryCommand<T>::BinaryCommand()
:Command<T>()
{
	
}

template <typename T>
BinaryCommand<T>::BinaryCommand(Stack<T> * initTargetStack, int initPrecedence)
:Command<T>(initTargetStack, initPrecedence)
{
	
}

template <typename T>
void BinaryCommand<T>::execute()
{
	T b = this->targetStack->top();
	this->targetStack->pop();
	T a = this->targetStack->top();
	this->targetStack->pop();
	T result = evaluate(a, b);
	this->targetStack->push(result);
}