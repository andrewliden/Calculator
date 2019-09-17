// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef OPERAND_EXPR
#define OPERAND_EXPR

#include "MathExpression.h"
#include "Operand.h"
#include "Visitor.h"
#include "Stack.h"

class OperandNode : public MathExpression
{
	public:
		OperandNode();
		OperandNode(Stack<int>* initStack, int initValue);
		virtual void accept(Visitor* visitor);
		virtual bool add(MathExpression* addExpression);
		virtual MathExpression* remove(int inded);
		virtual MathExpression* getChild(int index);
		virtual int getPrecedence();
		void setValue(int newValue);
		Operand<int> getOperand();
		~OperandNode();
	protected:
		Operand<int> operand;
};

#endif