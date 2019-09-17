// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef EXPR_BUILDER
#define EXPR_BUILDER

#include "MathExpression.h"

class ExpressionBuilder
{
	public:
		ExpressionBuilder();
		virtual void BuildOperandNode(int initValue) = 0;
		virtual void BuildAddNode() = 0;
		virtual void BuildSubtractNode() = 0;
		virtual void BuildMultiplyNode() = 0;
		virtual void BuildDivideNode() = 0;
		virtual void BuildModuloNode() = 0;
		virtual void BuildVariableNode(char letter) = 0;
		virtual void BuildLeftParenthesis() = 0;
		virtual void BuildRightParenthesis() = 0;
		virtual MathExpression* getResult() = 0;
		//If the builder has to quit work early (i.e. something was invalid),
		//Have a way to clear everything the builder was working on.
		virtual void clear() = 0;
		virtual ~ExpressionBuilder();
	protected:
		MathExpression* treeRoot;
};

#endif