// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef BINARY_OPERATOR_NODE_
#define BINARY_OPERATOR_NODE_

#include "MathExpression.h"
#include "BinaryCommand.h"
#include "Visitor.h"

class BinaryOperatorNode : public MathExpression
{
	public:
		BinaryOperatorNode();
		BinaryOperatorNode(BinaryCommand<int>* initOperator);
		virtual bool add(MathExpression* addExpression);
		virtual MathExpression* remove(int index);
		virtual void accept(Visitor* visitor);
		virtual MathExpression* getChild(int index);
		virtual int getPrecedence();
		BinaryCommand<int>* getOperator();
		~BinaryOperatorNode();
	protected:
		BinaryCommand<int>* binaryOperator;
		MathExpression* leftChild;
		MathExpression* rightChild;
};

#endif