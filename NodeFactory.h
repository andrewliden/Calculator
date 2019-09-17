// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _NODE_FACTORY
#define _NODE_FACTORY

#include "AbstractNodeFactory.h"

class NodeFactory : public AbstractNodeFactory
{
	public:
		NodeFactory();
		NodeFactory(Stack<int>* initResultStack);
		virtual BinaryOperatorNode* createAddNode();
		virtual BinaryOperatorNode* createSubtractNode();
		virtual BinaryOperatorNode* createMultiplyNode();
		virtual BinaryOperatorNode* createDivideNode();
		virtual BinaryOperatorNode* createModuloNode();
		virtual ParenthesisNode* createParenthesisNode();
		virtual OperandNode* createOperandNode(int initValue);
		virtual ~NodeFactory();
};

#endif