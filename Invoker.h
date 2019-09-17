// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _INVOKER
#define _INVOKER

#include <iostream>
#include "Command.h"
#include "Stack.h"
#include "Queue.h"

//This is a postfix-invoker.
class Invoker
{
	public:
		Invoker();
		//Getters to allow access to internal command queue & result stack.
		Queue<Command<int>*>* getCommandQueue();
		Stack<int>* getResultStack();
		//Put a command on the stack.
		void enqueueCommand(Command<int>* inputCommand);
		//Execute the commands on the command queue.
		void executeCommands();
		//Show the result on the result stack.
		void showResult();
		~Invoker();
	private:
		//Helper method to clear the stack & the queue
		void clear();
		Stack<int> resultStack;
		Queue<Command<int>*> commandQueue;
};

#endif