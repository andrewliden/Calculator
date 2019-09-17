#include "ConcreteFactory.h"

template <typename T>
ConcreteCommandFactory<T>::ConcreteCommandFactory()
:AbstractCommandFactory<T>()
{
	
}

template <typename T>
ConcreteCommandFactory<T>::ConcreteCommandFactory(Stack<T>* initTarget)
:AbstractCommandFactory<T>(initTarget)
{
	
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::numberCommand(T inputNumber)
{
	return new Operand<T>(this->targetStack, inputNumber);
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::addCommand()
{
	return new AddCommand<T>(this->targetStack);
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::subtractCommand()
{
	return new SubtractCommand<T>(this->targetStack);
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::moduloCommand()
{
	return new ModuloCommand<T>(this->targetStack);
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::multiplyCommand()
{
	return new MultiplyCommand<T>(this->targetStack);
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::divideCommand()
{
	return new DivideCommand<T>(this->targetStack);
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::unrecognizedCommand()
{
	return new UnrecognizedCommand<T>();
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::leftParenthesisCommand()
{
	return new LeftParenthesisCommand<T>();
}

template <typename T>
Command<T>* ConcreteCommandFactory<T>::rightParenthesisCommand()
{
	return new RightParenthesisCommand<T>();
}

