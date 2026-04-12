#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN& other) { *this = other; }

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
	}
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int a, int b, char operation)
{
	if (operation == '+')
		return a + b;
	if (operation == '-')
		return a - b;
	if (operation == '*')
		return a * b;
	if (operation == '/')
	{
		if (b == 0)
			throw std::runtime_error(utils::errorDivisionByZero);
		return (a / b);
	}
	throw std::runtime_error("ErrorR");
}

//	"7 5 *"
//	"7 5 2 * -"
int RPN::calculate(const std::string& expression)
{
	std::stack<int> localStack;
	for (size_t i = 0; i < expression.length(); i++)
	{
		char currentChar = expression[i];

		if (std::isspace(currentChar))
			continue;

		if (std::isdigit(currentChar))
		{
			localStack.push(currentChar - '0');
		}
		else if (isOperator(currentChar))
		{
			if (localStack.size() < 2)
			{
				throw std::runtime_error(utils::errorInvalidOperands);
			}
			// b es el de arriba, a es el de abajo
			int b = localStack.top();
			localStack.pop();

			int a = localStack.top();
			localStack.pop();

			localStack.push(performOperation(a, b, currentChar));
		}
		else
		{
			throw std::runtime_error(utils::errorInvalidCharacters);
		}
	}

	if (localStack.size() != 1)
	{
		throw std::runtime_error(utils::errorInvalidExpression);
	}
	return localStack.top();
}
