#ifndef _UNRECOGNIZED
#define _UNRECOGNIZED

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "Command.h"

//This class will be used for exceptions.
template <typename T>
class UnrecognizedCommand : public Command<T>
{
	public:
		UnrecognizedCommand();
		void execute();
		~UnrecognizedCommand();
};

#include "UnrecognizedCommand.cpp"

#endif