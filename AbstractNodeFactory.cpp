// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "AbstractNodeFactory.h"

AbstractNodeFactory::AbstractNodeFactory()
:resultStack(nullptr)
{
	
}

AbstractNodeFactory::AbstractNodeFactory(Stack<int>* initResultStack)
:resultStack(initResultStack)
{
	
}

AbstractNodeFactory::~AbstractNodeFactory()
{
	
}