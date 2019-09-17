// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "AbstractFactory.h"

template <typename T>
AbstractCommandFactory<T>::AbstractCommandFactory()
:targetStack(nullptr)
{
	
}

template <typename T>
AbstractCommandFactory<T>::AbstractCommandFactory(Stack<T> * initTarget)
:targetStack(initTarget)
{
	
}
