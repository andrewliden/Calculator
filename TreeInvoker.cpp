// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "TreeInvoker.h"
#include "ConcreteVisitor.h"

TreeInvoker::TreeInvoker()
:resultStack(nullptr), expression(nullptr)
{
	
}

void TreeInvoker::setStack(Stack<int>* newResultStack)
{
	resultStack = newResultStack;
}

void TreeInvoker::executeCommands()
{
	
	//Create a visitor.
	Visitor* visitor = new ConcreteVisitor();
	
	if(expression != nullptr)
	{
		//Provided it exists, visit the expression.  
		//Recursion should take care of the rest.
		//Then, get the stack from the visitor.
		try
		{
			expression->accept(visitor);
		}
		catch(CalculatorException::overflow overflow)
		{
			std::cout << "Cannot calculate:  Overflow occured." << std::endl;
			resultStack->clear();
		}
		catch(CalculatorException::underflow underflow)
		{
			std::cout << "Cannot calculate:  Overflow occured." << std::endl;
			resultStack->clear();
		}
		catch(CalculatorException::byZero byZero)
		{
			std::cout << "Cannot calculate:  Division by zero detected." << std::endl;
			resultStack->clear();
		}
		catch(Stack<int>::empty_exception empty)
		{
			std::cout << "Cannot calculate:  An operand is missing.  Likely cause:  mismatched parenthesis or operator." << std::endl;
			resultStack->clear();
		}
		delete expression;
	}
	//when done, delete the expression & the visitor.
	delete visitor;
}

void TreeInvoker::setExpression(MathExpression* newExpression)
{
	expression = newExpression;
}

void TreeInvoker::showResult()
{
	//First, check for error cases.
	if(resultStack->is_empty())
		//Error to show to the user if there was nothing on the stack.
		std::cout << "Could not calculate result - missing or invalid input." << std::endl;
	else if(resultStack->size() > 1)
		//Error to show if there were too many operands.
		std::cout << "Could not calculate result - Likely cause: operands given without a matching operator." << std::endl;
	else
		std::cout << "Result:  " << resultStack->top() << std::endl;
	resultStack->clear();
}

TreeInvoker::~TreeInvoker()
{
	
}