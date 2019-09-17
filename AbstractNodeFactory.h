// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef ABS_NODE_FACTORY_
#define ABS_NODE_FACTORY_

#include "BinaryOperatorNode.h"
#include "OperandNode.h"
#include "ParenthesisNode.h"
#include "Stack.h"

class AbstractNodeFactory
{
	public:
		AbstractNodeFactory();
		AbstractNodeFactory(Stack<int>* initResultStack);
		virtual BinaryOperatorNode* createAddNode() = 0;
		virtual BinaryOperatorNode* createSubtractNode() = 0;
		virtual BinaryOperatorNode* createMultiplyNode() = 0;
		virtual BinaryOperatorNode* createDivideNode() = 0;
		virtual BinaryOperatorNode* createModuloNode() = 0;
		virtual ParenthesisNode* createParenthesisNode() = 0;
		virtual OperandNode* createOperandNode(int initValue) = 0;
		virtual ~AbstractNodeFactory();
	protected:
		Stack<int>* resultStack;
};

#endif