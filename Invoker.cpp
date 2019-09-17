// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "Invoker.h"
#include "CalculatorExceptions.h"

Invoker::Invoker()
: resultStack(Stack<int>()), commandQueue(Queue<Command<int>*>())
{

}

Queue<Command<int>*>* Invoker::getCommandQueue()
{
	return &commandQueue;
}

Stack<int>* Invoker::getResultStack()
{
	return &resultStack;
}

void Invoker::enqueueCommand(Command<int>* inputCommand)
{
	commandQueue.enqueue(inputCommand);
}

void Invoker::executeCommands()
{
	while(!commandQueue.is_empty())
	{
		Command<int>* commandToExecute = commandQueue.dequeue();
		if(commandToExecute != nullptr)
		{
			try
			{
				commandToExecute->execute();
			}
			catch(Stack<int>::empty_exception empty)
			{
				std::cout << "Missing parameters:  Could not calculate command" << std::endl;
			}
			catch(CalculatorException::unrecognized unrecognized)
			{
				//On encountering an unrecognized command, clear the commandQueue and result stack.
				std::cout << "Unrecognized command encountered.  Expression cleared." << std::endl;
				clear();
			}
			catch(CalculatorException::byZero byZero)
			{
				//On encountering a divide/modulo by zero error, explain there was a divide by 0 detected.
				std::cout << "Cannot divide or perform modulo by zero.  Expression cleared." << std::endl;
				clear();
			}
			catch(CalculatorException::overflow overflow)
			{
				//On encountering an overflow error, explain the issue.
				std::cout << "Encountered overflow.  Expression cleared." << std::endl;
				clear();
			}
			catch(CalculatorException::underflow underflow)
			{
				//On encountering an underflow error, explain the issue.
				std::cout << "Encountered underflow.  Expression cleared." << std::endl;
				clear();
			}
			catch(CalculatorException::leftoverParenthesis leftoverParen)
			{
				//On encountering a leftover parenthesis, explain the issue.
				std::cout << "Error encountered when parsing parentheses." << std::endl;
				clear();
			}
			delete commandToExecute;
		}
	}
}

void Invoker::showResult()
{
	//First, check for error cases.
	if(resultStack.is_empty())
		//Error to show to the user if there was nothing on the stack.
		std::cout << "Could not calculate result - missing or invalid input." << std::endl;
	else if(resultStack.size() > 1)
		//Error to show if there were too many operands.
		std::cout << "Could not calculate result - Likely cause: operands given without a matching operator." << std::endl;
	else
		std::cout << "Result:  " << resultStack.top() << std::endl;
	//After showing a result, clear the command queue and result stack.
	clear();
}

Invoker::~Invoker()
{
	clear();
}

void Invoker::clear()
{
	//Delete all the commands on the queue.
	while(!commandQueue.is_empty())
	{
		Command<int>* commandToDelete = commandQueue.dequeue();
		if(commandToDelete != nullptr)
			delete commandToDelete;
	}
	resultStack.clear();
}