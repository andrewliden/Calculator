// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "BinaryOperatorNode.h"

BinaryOperatorNode::BinaryOperatorNode()
:binaryOperator(nullptr), leftChild(nullptr), rightChild(nullptr)
{
	
}

BinaryOperatorNode::BinaryOperatorNode(BinaryCommand<int>* initOperator)
:binaryOperator(initOperator), leftChild(nullptr), rightChild(nullptr)
{
	
}

bool BinaryOperatorNode::add(MathExpression* addExpression)
{
	//Check if the left is empty.  If so, add there.
	if(leftChild == nullptr)
	{
		leftChild = addExpression;
		return true;
	}
	//Otherwise, try the right.
	else if(rightChild == nullptr)
	{
		rightChild = addExpression;
		return true;
	}
	//If we're here, adding failed.  return false.
	else
		return false;
}

MathExpression* BinaryOperatorNode::remove(int index)
{
	//Create a null reference to the removed child.
	MathExpression* removedChild = nullptr;;
	//Remove the left or right child, depending on the index, record a reference to it.
	if(index == 0)
	{
		removedChild = leftChild;
		leftChild = nullptr;
	}
	if(index == 1)
	{
		removedChild = rightChild;
		rightChild = nullptr;
	}
	return removedChild;
}

void BinaryOperatorNode::accept(Visitor* visitor)
{
	visitor->visitBinaryOperatorNode(this);
}

MathExpression* BinaryOperatorNode::getChild(int index)
{
	//0 returns left, 1 returns right.
	if(index == 0)
		return leftChild;
	if(index == 1)
		return rightChild;
	//Any other index returns a null pointer.
	return nullptr;
}

int BinaryOperatorNode::getPrecedence()
{
	if(binaryOperator == nullptr)
		return UNRECOGNIZED_PRC;
	else
		return binaryOperator->getPrecedence();
}

BinaryCommand<int>* BinaryOperatorNode::getOperator()
{
	return this->binaryOperator;
}

BinaryOperatorNode::~BinaryOperatorNode()
{
	//Delete the children.
	if(leftChild != nullptr)
		delete leftChild;
	if(rightChild != nullptr)
		delete rightChild;
	//Delete this node's owned command.
	if(binaryOperator != nullptr)
		delete binaryOperator;
}