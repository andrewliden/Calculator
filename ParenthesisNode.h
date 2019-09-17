// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef PARENTHESIS_NODE_
#define PARENTHESIS_NODE_

#include "MathExpression.h"

//this is a type of unary node that owns a math expression.
class ParenthesisNode : public MathExpression
{
	public:
		ParenthesisNode();
		virtual void accept(Visitor* visitor);
		virtual bool add(MathExpression* addExpression);
		virtual MathExpression* remove(int index);
		virtual MathExpression* getChild(int index);
		virtual int getPrecedence();
		virtual ~ParenthesisNode();
	protected:
		MathExpression* treeRoot;
};

#endif