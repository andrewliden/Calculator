// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "NodeFactory.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "DivideCommand.h"
#include "MultiplyCommand.h"
#include "ModuloCommand.h"

NodeFactory::NodeFactory()
:AbstractNodeFactory()
{
	
}

NodeFactory::NodeFactory(Stack<int>* initResultStack)
:AbstractNodeFactory(initResultStack)
{
	
}

BinaryOperatorNode* NodeFactory::createAddNode()
{
	return new BinaryOperatorNode(new AddCommand<int>(resultStack));
}

BinaryOperatorNode* NodeFactory::createSubtractNode()
{
	return new BinaryOperatorNode(new SubtractCommand<int>(resultStack));
}

BinaryOperatorNode* NodeFactory::createMultiplyNode()
{
	return new BinaryOperatorNode(new MultiplyCommand<int>(resultStack));
}

BinaryOperatorNode* NodeFactory::createDivideNode()
{
	return new BinaryOperatorNode(new DivideCommand<int>(resultStack));
}

BinaryOperatorNode* NodeFactory::createModuloNode()
{
	return new BinaryOperatorNode(new ModuloCommand<int>(resultStack));
}

OperandNode* NodeFactory::createOperandNode(int initValue)
{
	return new OperandNode(resultStack, initValue);
}

ParenthesisNode* NodeFactory::createParenthesisNode()
{
	return new ParenthesisNode();
}

NodeFactory::~NodeFactory()
{
	
}

