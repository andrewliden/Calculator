// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _TREE_INTERPRETER
#define _TREE_INTERPRETER

#include <iostream>
#include "AbstractInterpreter.h"
#include "TreeInvoker.h"
#include "MathExpression.h"
#include "ConcreteBuilder.h"

class TreeInterpreter : public AbstractInterpreter
{
	public:
		TreeInterpreter();
		TreeInterpreter(TreeInvoker* initInvoker);
		void interpret();
		~TreeInterpreter();
	private:
		MathExpression* inputToTree();
		TreeInvoker* targetInvoker;
		Stack<int> resultStack;
};

#endif