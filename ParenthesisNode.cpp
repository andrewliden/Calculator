#include "Command.h"
#include "ParenthesisNode.h"

ParenthesisNode::ParenthesisNode()
:treeRoot(nullptr)
{
	
}

void ParenthesisNode::accept(Visitor* visitor)
{
	visitor->visitParenthesisNode(this);
}

bool ParenthesisNode::add(MathExpression* addExpression)
{
	if(treeRoot == nullptr)
	{
		treeRoot = addExpression;
		return true;
	}
	else
		return false;
}

MathExpression* ParenthesisNode::remove(int index)
{
	if(index == 0)
	{
		MathExpression* returnValue = treeRoot;
		treeRoot = nullptr;
		return returnValue;
	}
	else
	{
		return nullptr;
	}
}

MathExpression* ParenthesisNode::getChild(int index)
{
	return treeRoot;
}

int ParenthesisNode::getPrecedence()
{
	return RIGHT_PAREN_PRC;
}

ParenthesisNode::~ParenthesisNode()
{
	if(treeRoot != nullptr)
		delete treeRoot;
}