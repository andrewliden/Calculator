#ifndef _CALC_ERR
#define _CALC_ERR

//Defines a set of exceptions that can occur with the calculator.
class CalculatorException
{
	public:
		class overflow {};
		class underflow {};
		class byZero {};
		class unrecognized {};
		class leftoverParenthesis {};
		class parenthesisError {};
};

#endif