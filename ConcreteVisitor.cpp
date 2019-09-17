// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "ConcreteVisitor.h"
#include "BinaryOperatorNode.h"
#include "ParenthesisNode.h"
#include "OperandNode.h"

ConcreteVisitor::ConcreteVisitor()
:Visitor()
{
	
}

void ConcreteVisitor::visitOperandNode(OperandNode* target)
{
  // COMMENT Very clever design, and interesting reuse of the commands from
  // assignment 3. See if you can improve upon your design so you do not have
  // to call setTargetStack() below. This will require you to provide the stack
  // when the object is being created. Based on your current design, it is possible
  // to accomplish this design approach.
	// RESPONSE Made suggested improvement.  This seems to reduce coupling between the builder & the visitor,
	// since the visitor doesn't need to be concerned with any kind of initialization procedures for operands.
	// On the other hand, it seems to increase coupling between the invoker & the interpreter, since the invoker
	// needs to be able to access the interpreter's result stack.
  
	//Get the operand from this node.
	Operand<int> operand = target->getOperand();
	//Execute the operand.
	operand.execute();
}

void ConcreteVisitor::visitBinaryOperatorNode(BinaryOperatorNode* target)
{
	//get the target's children and visit them first.
	if(target->getChild(0) != nullptr)
		target->getChild(0)->accept(this);
	if(target->getChild(1) != nullptr)
		target->getChild(1)->accept(this);
	//Get the operator from this node.
	BinaryCommand<int>* binaryOperator = target->getOperator();
	//Execute the operand.
	binaryOperator->execute();
}

void ConcreteVisitor::visitParenthesisNode(ParenthesisNode* target)
{
	//get the target's child and visit it.
	if(target->getChild(0) != nullptr)
		target->getChild(0)->accept(this);
}


ConcreteVisitor::~ConcreteVisitor()
{
	
}
