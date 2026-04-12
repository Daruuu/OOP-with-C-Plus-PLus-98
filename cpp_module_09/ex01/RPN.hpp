#ifndef STARTING_WITH_CPP_RPN_HPP
#define STARTING_WITH_CPP_RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	static int calculate(const std::string& expression);
	static bool validateInput(const std::string& expression);

private:
	// Actuará como una pila (stack) usando push_back y pop_back
	std::stack<int> stack_;

	static bool isOperator(char c);
	static int performOperation(int a, int b, char operation);
};

#endif //STARTING_WITH_CPP_RPN_HPP
