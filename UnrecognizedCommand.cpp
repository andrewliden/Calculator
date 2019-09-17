// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "UnrecognizedCommand.h"

template <typename T>
UnrecognizedCommand<T>::UnrecognizedCommand()
:Command<T>(nullptr, UNRECOGNIZED_PRC)
{
	
}

template <typename T>
void UnrecognizedCommand<T>::execute()
{
	//throw a copy of this command if an attempt is made to execute it.
	throw CalculatorException::unrecognized();
}

template <typename T>
UnrecognizedCommand<T>::~UnrecognizedCommand()
{
	
}
