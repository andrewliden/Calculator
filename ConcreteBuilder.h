// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef CONC_BUILDER
#define CONC_BUILDER

#include "ExpressionBuilder.h"
#include "OperandNode.h"
#include "BinaryOperatorNode.h"
#include "Stack.h"
#include "AbstractNodeFactory.h"
#include <map>

class ConcreteBuilder : public ExpressionBuilder
{
	public:
		class operandInsertException{};
		class operatorInsertException{};
		
		ConcreteBuilder();
		ConcreteBuilder(Stack<int> * initResultStack);
		virtual void BuildOperandNode(int initValue);
		virtual void BuildAddNode();
		virtual void BuildSubtractNode();
		virtual void BuildMultiplyNode();
		virtual void BuildDivideNode();
		virtual void BuildModuloNode();
		virtual void BuildVariableNode(char letter);
		virtual void BuildLeftParenthesis();
		virtual void BuildRightParenthesis();
		virtual MathExpression* getResult();
		MathExpression* getSubtree();
		virtual void clear();
		~ConcreteBuilder();
	private:
		//Helper functions to insert components into the tree.
		void operandInsert(OperandNode* nodeToInsert, MathExpression* &insertLocation);
		void binaryOperatorInsert(BinaryOperatorNode* nodeToInsert, MathExpression* &insertLocation);
		void addToVariableList(char letter, OperandNode* variable);
		void assignVariables();
		//Attributes
		std::multimap<char, OperandNode*> variables;
		ConcreteBuilder* subtreeBuilder;
		MathExpression* previousExpression;
		Stack<int>* resultStack;
		AbstractNodeFactory* nodeFactory;
};

#endif