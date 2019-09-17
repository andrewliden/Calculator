// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include <sstream>
#include "TreeInterpreter.h"
#include "CalculatorExceptions.h"

TreeInterpreter::TreeInterpreter()
:targetInvoker(nullptr), resultStack(Stack<int>())
{
	
}

TreeInterpreter::TreeInterpreter(TreeInvoker* initInvoker)
:targetInvoker(initInvoker), resultStack(Stack<int>())
{
	targetInvoker->setStack(&resultStack);
}

void TreeInterpreter::interpret()
{
	//first, convert the input to a tree.
	MathExpression* treeRoot = inputToTree();
	//Give the result to the invoker.
	targetInvoker->setExpression(treeRoot);
}

MathExpression* TreeInterpreter::inputToTree()
{
	//Initialize the return value as a null pointer.
	MathExpression* returnValue = nullptr;
	//Tokenize the given text.
	std::string token;
	std::stringstream extractor(this->getText());
	//Create a builder for the interpretation, and give it the result stack.
	ExpressionBuilder* builder = new ConcreteBuilder(&resultStack);
	//Unhandled parenthesis can occur in many places.  A safe (but admittedly somewhat lazy)
	//approach is taken, where unhandled parenthesis errors are caught untill the tree is returned to the client.
	try
	{
		//While there are tokens, use the builder to build the corresponding objects.
		while(getline(extractor, token, ' '))
		{
			//Just figure out what kind of input we're looking at, and let the builder handle the rest.
			//First, check if this is one of the binary operators,
			//+, -, *, /, or %
			if(token == "")
			{
				builder->clear();
				std::cout << "Could not parse:  Empty input detected." << std::endl;
				delete builder;
				return nullptr;
			}
			if(token == "+")
				builder->BuildAddNode();
			else if(token == "-")
				builder->BuildSubtractNode();
			else if(token == "*")
				builder->BuildMultiplyNode();
			else if(token == "/")
				builder->BuildDivideNode();
			else if(token == "%")
				builder->BuildModuloNode();
			else if(token == "(")
				builder->BuildLeftParenthesis();
			else if(token == ")")
				builder->BuildRightParenthesis();
			else if(this->isVariable(token))
				builder->BuildVariableNode(token[0]);
			else if(this->isOperand(token))
			{
				try
				{
					builder->BuildOperandNode(stoi(token));
				}
				catch(std::out_of_range rangeError)
				{
					//Value could not be converted from string correctly.
					builder->clear();
					std::cout << "Could not parse:  value exceeding maximum input range detected." << std::endl;
					delete builder;
					return nullptr;
				}
			}
			else
			{
				//On the unrecognized entry case, clear the builder, show an error,
				//and return a null pointer.
				builder->clear();
				std::cout << "Could not parse:  Unrecognized command entered." << std::endl;
				delete builder;
				return nullptr;
			}
		}
		returnValue = builder->getResult();
	}
	catch(CalculatorException::leftoverParenthesis leftover)
	{
		builder->clear();
		std::cout << "Could not parse:  Mismatched parenthesis detected." << std::endl;
		delete builder;
		return nullptr;
	}
	catch(CalculatorException::parenthesisError parenError)
	{
		builder->clear();
		std::cout << "An error occured while attempting to parse a parenthesis." << std::endl;
		delete builder;
		return nullptr;
	}
	catch(ConcreteBuilder::operatorInsertException insertError)
	{
		//This often occurs when operators or parenthesis are mismatched, but it can occur in many places.
		builder->clear();
		std::cout << "An error occurred while attempting to insert an operator." << std::endl;
		delete builder;
		return nullptr;
	}
	catch(ConcreteBuilder::operandInsertException insertError)
	{
		//This often occurs when operators or parenthesis are mismatched, but it can occur in many places.
		builder->clear();
		std::cout << "An error occurred while attempting to insert an operand." << std::endl;
		delete builder;
		return nullptr;
	}
	
	delete builder;
	return returnValue;
}

TreeInterpreter::~TreeInterpreter()
{
	
}