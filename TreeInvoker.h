// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _TREE_INVOKER
#define _TREE_INVOKER

#include <iostream>
#include "MathExpression.h"
#include "Stack.h"

class TreeInvoker
{
	public:
		TreeInvoker();
		void setStack(Stack<int>* newResultStack);
		void executeCommands();
		void setExpression(MathExpression* newExpression);
		void showResult();
		~TreeInvoker();
	private:
		MathExpression* expression;
		Stack<int>* resultStack;

};

#endif