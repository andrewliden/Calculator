// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "OperandNode.h"

OperandNode::OperandNode()
:operand()
{

}

OperandNode::OperandNode(Stack<int>* initStack, int initValue)
:operand(initStack, initValue)
{

}

void OperandNode::accept(Visitor* visitor)
{
	visitor->visitOperandNode(this);
}

bool OperandNode::add(MathExpression* addExpression)
{
	//This appears to be an example of how the composite pattern can make your design overly general -
	//Operands should not be able to add children.  Since this is the case, always return false, marking a failure to add the child.
	return false;
}

MathExpression* OperandNode::remove(int index)
{
	//The same case as above applies here.
	return nullptr;
}

MathExpression* OperandNode::getChild(int index)
{
	return nullptr;
}

Operand<int> OperandNode::getOperand()
{
	return this->operand;
}

void OperandNode::setValue(int newValue)
{
	operand.setValue(newValue);
}

int OperandNode::getPrecedence()
{
	return OPERAND_PRC;
}

OperandNode::~OperandNode()
{
	
}