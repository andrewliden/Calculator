// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#include <climits>
#include "Command.h"
//Precedence scheme:
// Lower Precedence -> Do this operation first.
//Unrecognized	Operand	P E M/% D A S		LeftParenthesis
//			-2		 -1	0 1   2 2 3 3 		INT_MAX
#define UNRECOGNIZED_PRC -2
#define OPERAND_PRC -1
#define RIGHT_PAREN_PRC 0
#define EXPONENT_PRC 1
#define MUL_PRC 2
#define MODULO_PRC 2
#define DIV_PRC 2
#define ADD_PRC 3
#define SUB_PRC 3
#define LEFT_PAREN_PRC INT_MAX

template <typename T>
Command<T>::Command()
:targetStack(nullptr), precedence(0)
{
	
}

template <typename T>
Command<T>::Command(Stack<T> * initTargetStack)
:targetStack(initTargetStack), precedence(0)
{
	
}

template <typename T>
Command<T>::Command(Stack<T> * initTargetStack, int initPrecedence)
:targetStack(initTargetStack), precedence(initPrecedence)
{
	
}

template <typename T>
void Command<T>::setTargetStack(Stack<T>* newTargetStack)
{
	targetStack = newTargetStack;
}

template <typename T>
int Command<T>::getPrecedence()
{
	return precedence;
}

template <typename T>
Command<T>::~Command()
{
	
}