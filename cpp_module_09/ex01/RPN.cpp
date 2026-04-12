#include "RPN.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"

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

static void printStackVisual(size_t step, char token, const std::stack<int>& stk)
{
	std::cout << "Step " << std::setw(2) << step << " | Token: '" << token << "'\t→ Stack: [";

	if (stk.empty())
	{
		std::cout << " empty ";
	}
	else
	{
		std::stack<int> temp = stk;           // copia para no modificar el original
		std::vector<int> elements;

		while (!temp.empty())
		{
			elements.push_back(temp.top());
			temp.pop();
		}

		for (int i = static_cast<int>(elements.size()) - 1; i >= 0; --i)
			std::cout << " " << elements[i] << (i > 0 ? "," : " ");
	}
	std::cout << "]\n";
}

int RPN::calculate(const std::string& expression, bool visualize)
{
	std::stack<int> stk;
	size_t step = 0;

	if (visualize)
	{
		std::cout << GREEN << "=== RPN VISUALIZER START ===\n" << RESET;
		std::cout << "Expression: \"" << expression << "\"\n\n";
	}

	for (size_t i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];

		if (std::isspace(c))
			continue;

		++step;

		if (std::isdigit(c))
		{
			stk.push(c - '0');
			if (visualize)
				printStackVisual(step, c, stk);
		}
		else if (isOperator(c))
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error");

			int b = stk.top(); stk.pop();
			int a = stk.top(); stk.pop();

			int result = performOperation(a, b, c);
			stk.push(result);

			if (visualize)
				printStackVisual(step, c, stk);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (stk.size() != 1)
		throw std::runtime_error("Error");

	if (visualize)
		std::cout << "\n=== FINAL RESULT: " << stk.top() << " ===\n";

	return stk.top();
}

//	"7 5 *"
//	"7 5 2 * -"
/*
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
*/
