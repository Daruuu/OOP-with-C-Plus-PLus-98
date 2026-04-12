#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) { *this = other; }

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->stack_ = other.stack_;
	}
	return *this;
}

RPN::~RPN() {}

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
			throw std::runtime_error("Error: Division by zero");
		return (a / b);
	}
	return 0;
}

int RPN::calculate(const std::string& expression)
{
	std::stack<int> stack;

	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];

		// ignore spaces
		if (std::isspace(c))
			continue;

		// Si es un dígito
		if (std::isdigit(c))
		{
			stack.push(c - '0');
		}
		// Si es un operador
		else if (isOperator(c))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Insufficient operands");

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			int result = performOperation(a, b, c);
			stack.push(result);
		}
		else
		{
			throw std::runtime_error("Error: Invalid character in expression");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error(
			"Error: The expression is incomplete or has too many operands");

	return stack.top();
}

bool RPN::validateInput(const std::string& expression)
{
	if (expression.empty())
		return false;

	std::stack<int> numberStack;
	std::stack<int> operatorStack;

	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];

		if (std::isspace(c))
		{
			continue;
		}
		if (std::isdigit(c))
		{
			numberStack.push(c - '0');
		}
		else if (isOperator(c))
		{
			operatorStack.push(c);
		}
	}
	if (numberStack.size() - 1 != operatorStack.size())
		return false;

	return true;
}

