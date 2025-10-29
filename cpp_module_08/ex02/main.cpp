#include "MutantStack.hpp"
#include <iostream>
#include <list>

void test_case_subject()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(10);
	std::cout << "\nNumber at top of stack: " << mstack.top() << std::endl;

	std::cout <<  "Size of stack: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(-2147483647);

	std::cout <<  "\nSize of stack: "<< mstack.size() << std::endl;

	MutantStack<int>::iterator itb = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (itb != ite) {
		std::cout << *itb << std::endl;
		++itb;
	}

	std::stack<int> testStack(mstack);
}

void test_case_usingDouble()
{
	MutantStack<double> stackOfDouble;

	stackOfDouble.push(10.80);
	stackOfDouble.push(1.0);
	std::cout << "\nNumber at top of stack: " << stackOfDouble.top() << std::endl;

	std::cout <<  "Size of stack: "<< stackOfDouble.size() << std::endl;
	stackOfDouble.push(3.42);
	stackOfDouble.push(42);
	stackOfDouble.push(-2147483647);

	std::cout <<  "\nnew size of stack: "<< stackOfDouble.size() << std::endl;

	MutantStack<double>::iterator itb = stackOfDouble.begin();
	MutantStack<double>::iterator ite = stackOfDouble.end();

	while (itb != ite) {
		std::cout << *itb << std::endl;
		++itb;
	}
	// std::stack<double> testStack(stackOfDouble);
	// std::list<int> testList(mstack.begin(), mstack.end());
}

void test_case_usingList()
{
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {

	// test_case_subject();
	// test_case_usingDouble();
	test_case_usingList();

	return 0;
}
