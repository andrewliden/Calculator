// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef VISITOR_
#define VISITOR_

#include "Stack.h"

class OperandNode;
class BinaryOperatorNode;
class ParenthesisNode;

class Visitor
{
	public:
		Visitor();
		virtual void visitOperandNode(OperandNode* target) = 0;
		virtual void visitParenthesisNode(ParenthesisNode* target) = 0;
		virtual void visitBinaryOperatorNode(BinaryOperatorNode* target) = 0;
		virtual ~Visitor();

};

#endif