// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include "Interpreter.h"

Interpreter::Interpreter()
:targetInvoker(nullptr)
{

}

Interpreter::Interpreter(Invoker * initInvoker)
:targetInvoker(initInvoker)
{
	
}

void Interpreter::interpret()
{
	//First, convert from infix strings to postfix commands.
	Queue<Command<int>*> interpretedCommands;
	try
	{
		interpretedCommands = inputToPostfix();
	}
	catch(missingParenthesis e)
	{
		//If a missing parenthesis error was caught, give an output.
		std::cout << "Could not interpret input:  Closed parenthesis found without matching open parenthesis." << std::endl;
	}
	while(!interpretedCommands.is_empty())
		targetInvoker->enqueueCommand(interpretedCommands.dequeue());
}

Command<int>* Interpreter::interpretToken(std::string token, AbstractCommandFactory<int>* commandFactory)
{
	Stack<int>* calculationStack = targetInvoker->getResultStack();
	
	//Check for empty spaces.
	if(token == "")
		return commandFactory->unrecognizedCommand();
	//Check for common types of operators.
	if(token == "+")
		return commandFactory->addCommand();
	if(token == "-")
		return commandFactory->subtractCommand();
	if(token == "*")
		return commandFactory->multiplyCommand();
	if(token == "/")
		return commandFactory->divideCommand();
	if(token == "%")
		return commandFactory->moduloCommand();
	if(token == "(")
		return commandFactory->leftParenthesisCommand();
	if(token == ")")
		return commandFactory->rightParenthesisCommand();
	if(this->isOperand(token))
	{
		//try to do this.  If you can't do it, raise an error and return an unrecognized command.
		try
		{
			return commandFactory->numberCommand(stoi(token));
		}
		catch(std::out_of_range rangeError)
		{
			std::cout << "Out of range number detected." << std::endl;
			return commandFactory->unrecognizedCommand();
		}
	}
	//If we're here and nothing has been returned, this isn't a recognized command.
	return commandFactory->unrecognizedCommand();
}

Queue<Command<int>*> Interpreter::inputToPostfix()
{
	std::string token;
	//Create a stringstream to extract the input from the user (extractor).
	std::stringstream extractor(this->getText());
	//Create a queue of strings that will become the postfix expression.
	Queue<Command<int>*> postfixExpression;
	//Create a stack for operators.
	Stack<Command<int>*> operators;
	//Create a factory for the single token interpretation.
	ConcreteCommandFactory<int> commandFactory = ConcreteCommandFactory<int>(targetInvoker->getResultStack());
	while(getline(extractor, token, ' '))
	{
		//Interpret the token and convert it into a command.
		Command<int>* commandFromToken = interpretToken(token, &commandFactory);
		int commandPrecedence = commandFromToken->getPrecedence();
		//If the token has the precedence that indicates it is an operand, simply enqueue it.
		if(commandPrecedence == OPERAND_PRC)
			postfixExpression.enqueue(commandFromToken);
		//Otherwise, assume this is an operator or a parentheses
		else
		{
			//First, check if it's a parentheses.
			if(commandPrecedence == LEFT_PAREN_PRC)
			{
				//If it's a left parentheses, push it onto the stack.
				operators.push(commandFromToken);
			}
			else if(commandPrecedence == RIGHT_PAREN_PRC)
			{
				//Pop the elements from the stack and append until found matching open parenthesis.
				while(operators.top()->getPrecedence() != LEFT_PAREN_PRC)
				{
					postfixExpression.enqueue(operators.top());
					operators.pop();
					//If the operators stack is empty by now, and we never found "(", 
					//Clear the command queue, then throw an exception.
					if(operators.is_empty())
					{
						while(!postfixExpression.is_empty())
						{
							Command<int>* commandToDelete = postfixExpression.dequeue();
							if(commandToDelete != nullptr)
								delete commandToDelete;
						}
						delete commandFromToken;
						throw missingParenthesis();
					}
				}
				//Delete this object and get rid of + delete the matching left parenthesis.
				delete commandFromToken;
				delete operators.top();
				operators.pop();
			}
			else
			{
				//if it's not a parentheses, and the stack is empty, add this to the stack.
				if(operators.is_empty())
					operators.push(commandFromToken);
				else
				{
          // COMMENT: You should implement the precedence function on
          // the command object since it is better place there.
			//RESPONSE:  precedence is now a property of commands.
          
					//Otherwise, keep popping elements off of the stack until this item has < or = precedence,
					//Or untill the stack is empty.
					while(!operators.is_empty() and operators.top()->getPrecedence() < commandPrecedence)
					{
						postfixExpression.enqueue(operators.top());
						operators.pop();
					}
					operators.push(commandFromToken);
				}
				
			}
			
		}
	}
	//Push all of the leftover operators on the stack onto the postfix expression.
	while(!operators.is_empty())
	{
		postfixExpression.enqueue(operators.top());
		operators.pop();
	}
	return postfixExpression;
}
