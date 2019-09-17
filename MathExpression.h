// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

#ifndef _MATH_EXPR
#define _MATH_EXPR

#include "Command.h"
#include "Visitor.h"

class MathExpression
{
	public:
		MathExpression();
		//returns true on success, false on failure.
		virtual void accept(Visitor* visitor) = 0;
		virtual bool add(MathExpression* addExpression) = 0;
		//Removes a child and returns a pointer to the removed child.
		virtual MathExpression* remove(int index) = 0;
		virtual MathExpression* getChild(int index) = 0;
		virtual int getPrecedence() = 0;
		virtual ~MathExpression();
};

#endif