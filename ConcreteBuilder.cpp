// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "ConcreteBuilder.h"
#include "NodeFactory.h"
#include "CalculatorExceptions.h"

ConcreteBuilder::ConcreteBuilder()
:ExpressionBuilder(), variables(), subtreeBuilder(nullptr), previousExpression(nullptr), resultStack(nullptr), nodeFactory(new NodeFactory(nullptr))
{

}

ConcreteBuilder::ConcreteBuilder(Stack<int> * initResultStack)
:ExpressionBuilder(), variables(), subtreeBuilder(nullptr), previousExpression(nullptr), resultStack(initResultStack), nodeFactory(new NodeFactory(initResultStack))
{

}

void ConcreteBuilder::BuildOperandNode(int initValue)
{
	operandInsert(nodeFactory->createOperandNode(initValue), treeRoot);
}

void ConcreteBuilder::BuildAddNode()
{
	binaryOperatorInsert(nodeFactory->createAddNode(), treeRoot);
}

void ConcreteBuilder::BuildSubtractNode()
{
	binaryOperatorInsert(nodeFactory->createSubtractNode(), treeRoot);
}

void ConcreteBuilder::BuildMultiplyNode()
{
	binaryOperatorInsert(nodeFactory->createMultiplyNode(), treeRoot);
}

void ConcreteBuilder::BuildDivideNode()
{
	binaryOperatorInsert(nodeFactory->createDivideNode(), treeRoot);
}

void ConcreteBuilder::BuildModuloNode()
{
	binaryOperatorInsert(nodeFactory->createModuloNode(), treeRoot);
}

void ConcreteBuilder::BuildLeftParenthesis()
{
	//Implementation plan:
	//Have a pointer to an object called subtree builder.
	//On Build operations, if the subtree builder exists,
	//build on it, instead.
	if(subtreeBuilder != nullptr)
		subtreeBuilder->BuildLeftParenthesis();
	else
		subtreeBuilder = new ConcreteBuilder(resultStack);
}

void ConcreteBuilder::BuildRightParenthesis()
{
	//Implementation plan:
	//Provided the subtree builder exists, get its contents, and put them inside of a parenthesis node.
	if(subtreeBuilder != nullptr)
	{
		//If the subtree builder has a subtree builder, work on that instead.
		if(subtreeBuilder->subtreeBuilder != nullptr)
			subtreeBuilder->BuildRightParenthesis();
		else
		{
			//Create a parenthesis node.
			ParenthesisNode* parenthesis = nodeFactory->createParenthesisNode();
			//First, check there's a previous expression.
			if(previousExpression == nullptr)
			{
				//If not, check if the root is null.
				if(treeRoot == nullptr)
					//If the tree root is null, make this the new root.
					treeRoot = parenthesis;
				else
				{
					//If it's not, something unexpected happened.
					//delete the parenthesis, then
					//throw an error related to parenthesis handling.
					delete parenthesis;
					throw CalculatorException::parenthesisError();
				}
			}
			else
			{
				//If there's an existing previous expression,
				//Try to add this as a child of it.
				bool added = previousExpression->add(parenthesis);
				//On failure, throw an error.
				if(!added)
				{
					delete parenthesis;
					throw CalculatorException::parenthesisError();
				}
			}
			//Get the subtree from the subtree builder.
			MathExpression* subtree = subtreeBuilder->getSubtree();
			//Add the subtree as a node to the parenthesis node.
			bool added = parenthesis->add(subtree);
			if(!added)
			{
				delete parenthesis;
				throw CalculatorException::parenthesisError();
			}
			//At the end of the operation, delete the subtree builder, and null it.
			delete subtreeBuilder;
			subtreeBuilder = nullptr;
			//Then, set this as the previous expression.
			previousExpression = parenthesis;
		}
	}
	else
	{
		//If the subtree builder was a null pointer, there's a right parenthesis with no match.
		//That's an error.  Throw an exception.
		throw CalculatorException::leftoverParenthesis();
	}
}

void ConcreteBuilder::BuildVariableNode(char letter)
{
	//Initially, variables are just operands with a value of 0.
	OperandNode* variable = nodeFactory->createOperandNode(0);
	operandInsert(variable, treeRoot);
	addToVariableList(letter, variable);
}

MathExpression* ConcreteBuilder::getResult()
{
	//Check if there's still an unattached subtree.  If so, there must be a hanging parenthesis.
	//Clear everything and throw an error.
	if(subtreeBuilder != nullptr)
	{
		clear();
		throw CalculatorException::leftoverParenthesis();
	}
	//Before giving the tree away to the invoker, assign all of the variables.
	assignVariables();
	return treeRoot;
}

MathExpression* ConcreteBuilder::getSubtree()
{
	//Returns the tree root without asking the user to assign variables.
	return treeRoot;
}
		
void ConcreteBuilder::clear()
{
	if(subtreeBuilder != nullptr)
	{
		//If the subtree builder exists, clear it, then delete & null it.
		subtreeBuilder->clear();
		delete subtreeBuilder;
		subtreeBuilder = nullptr;
	}
	if(treeRoot != nullptr)
	{
		delete this->treeRoot;
		treeRoot = nullptr;
	}
}


void ConcreteBuilder::operandInsert(OperandNode* nodeToInsert, MathExpression* &insertLocation)
{
	//First, check if there's a subtree.  If so, insert into that instead.
	if(subtreeBuilder != nullptr)
	{
		subtreeBuilder->operandInsert(nodeToInsert, subtreeBuilder->treeRoot);
	}
	else
	{
		//Keep track of whether or not the item was successfully added.
		bool added = false;
		if(insertLocation == nullptr)
		{
			//If the location is a null pointer, make the number the new root.
			insertLocation = nodeToInsert;
			added = true;
		}
		else
		{
			//Otherwise, try to make this a child of the most recently added operator.
			if(previousExpression != nullptr)
			{
				//Otherwise, try to add this as a child of the most recent expression.
				added = previousExpression->add(nodeToInsert);
			}	
		}
		if(added)
			previousExpression = nodeToInsert;
		else
		{
			//If the node failed to be added, clean up and throw an exception.
			this->clear();
			delete nodeToInsert;
			throw operandInsertException();
		}
	}
}

void ConcreteBuilder::binaryOperatorInsert(BinaryOperatorNode* nodeToInsert, MathExpression* &insertLocation)
{
	//First, check if there's a subtree.  If so, insert into that instead.
	if(subtreeBuilder != nullptr)
	{
		subtreeBuilder->binaryOperatorInsert(nodeToInsert, subtreeBuilder->treeRoot);
	}
	else
	{
		//Keep track of whether or not the item was successfully added.
		bool added = false;
		//Don't try to add a binary operator if the root is a null pointer.
		if(insertLocation != nullptr)
		{
			//If not, check the precedence of the location.  If the precedence is greater,
			//Swap locations, and make the target a child of this insertion.
			if(nodeToInsert->getPrecedence() >= insertLocation->getPrecedence())
			{
				MathExpression* insertLocationTemp = insertLocation;
				insertLocation = nodeToInsert;
				//Then, make the insert location a child of this node.
				added = nodeToInsert->add(insertLocationTemp);
			}
			else
			{
				//If the precedence of this operator is less,
				//this operator should become a child of the target operator.
				//First, remove the right child of the target operator.
				MathExpression* rightChild = insertLocation->remove(1);
				//Then, add this as a child of the operator.
				added = insertLocation->add(nodeToInsert);
				if(rightChild != nullptr)
				{
					//Add the node on the right.
					added = nodeToInsert->add(rightChild);
				}
				else
				{
					//If you got a child that was a null pointer, something's wrong.
					//Throw an exception.
					this->clear();
					throw operatorInsertException();
				}
			}
		}
		//If this was successfully added, make it the previously added operator.
		if(added)
			previousExpression = nodeToInsert;
		else
		{
			//If the expression couldn't be added, clean up and throw an exception.
			this->clear();
			delete nodeToInsert;
			throw operatorInsertException();
		}
	}
}

void ConcreteBuilder::addToVariableList(char letter, OperandNode* variable)
{
	//Reference used: http://www.cplusplus.com/reference/map/map/insert/
	variables.insert(std::pair<char, OperandNode*>(letter, variable));
}

void ConcreteBuilder::assignVariables()
{
	//Reference used: 
	//check if there are any variables to assign in here.  If so, assign them.
	if(variables.size() > 0)
	{
		std::cout << "Assigning variables:" << std::endl;
		//This is probably kind of bad.  I don't use map all that often..
		char lastChar = ' ';
		int value = 0;
		for(auto variableIterator = variables.begin(); variableIterator != variables.end(); variableIterator++)
		{
			//If this is a different letter from last time, ask to assign it.
			//If it's the same one, you can just use the same value as last time.
			if(variableIterator->first != lastChar)
			{
				bool keepGoing = true;
				while(keepGoing)
				{
					std::cout << "Set value for variable " << variableIterator->first << ": " << std::endl;
					//some weirdness happens if I don't use getline here...
					std::string input;
					getline(std::cin, input);
					try
					{
						value = stoi(input);
						keepGoing = false;
					}
					catch(std::invalid_argument invalid)
					{
						std::cout << "ERROR:  You must enter a number." << std::endl;
					}
					catch(std::out_of_range rangeExceeded)
					{
						std::cout << "ERROR:  Cannot store a number of this size." << std::endl;
					}
				}
			}
			variableIterator->second->setValue(value);
			//Mark that this is the previous character for the next iteration.
			lastChar = variableIterator->first;
		}
	}
}

ConcreteBuilder::~ConcreteBuilder()
{
	//No checking for null pointers should be needed - this is always initialized.
	delete nodeFactory;
}
