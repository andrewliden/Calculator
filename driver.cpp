// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include <iostream>
#include "Command.h"
#include "AbstractInterpreter.h"
#include "TreeInterpreter.h"
#include "TreeInvoker.h"

int main()
{
	//Create an interpreter & invoker.
	TreeInvoker invoker;
	AbstractInterpreter* interpreter = new TreeInterpreter(&invoker);
	bool keepGoing = true;
	while(keepGoing)
	{
		//Get the command from the user.
		interpreter->takeInput();
		if(interpreter->getText() == "QUIT")
		{
			keepGoing = false;
		}
		else
		{
			//If we didn't get a QUIT, interpret the commands
			interpreter->interpret();
			//then execute them.
			invoker.executeCommands();
			//Then show the result.
			invoker.showResult();
		}
	}
	//delete the interpreter and return 0.
	delete interpreter;
	return 0;
}