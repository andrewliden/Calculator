// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef CONC_VISITOR_
#define CONC_VISITOR_

#include "Visitor.h"

class ConcreteVisitor : public Visitor
{
	public:
		ConcreteVisitor();
		virtual void visitOperandNode(OperandNode* target);
		virtual void visitParenthesisNode(ParenthesisNode* target);
		virtual void visitBinaryOperatorNode(BinaryOperatorNode* target);
		~ConcreteVisitor();
};

#endif