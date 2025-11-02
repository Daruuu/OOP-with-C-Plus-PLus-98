#include "MutantStack.hpp"
#include <iostream>
#include <list>

void test_case_subject()
{
	std::cout << GREEN << "***** TEST CASE: SUBJECT *****" << RESETT <<
		std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(10);
	std::cout << "\nNumber at top of stack: " << mstack.top() << std::endl;

	std::cout << "Size of stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(1);
	mstack.push(-2147483647);
	std::cout << "\nSize of stack: " << mstack.size() << std::endl;

	mstack.pop();

	std::cout << "\nSize of stack after use pop(): " << mstack.size() <<
		std::endl;

	MutantStack<int>::iterator itb = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	int i = 0;
	while (itb != ite)
	{
		std::cout << "Stack[" << i << "]=" << *itb << std::endl;
		++i;
		++itb;
	}

	std::stack<int> testStack(mstack);
}

void test_case_usingDouble()
{
	std::cout << GREEN << "\n***** TEST CASE: MUTANSTACK with Double: *****" <<
		RESETT << std::endl;
	MutantStack<double> stackOfDouble;

	stackOfDouble.push(10.80);
	stackOfDouble.push(1.0);
	std::cout << "\nNumber at top of stack: " << stackOfDouble.top() <<
		std::endl;

	std::cout << "Size of stack: " << stackOfDouble.size() << std::endl;
	stackOfDouble.push(3.42);
	stackOfDouble.push(42);
	stackOfDouble.push(-2147483647);

	std::cout << "\nnew size of stack: " << stackOfDouble.size() << std::endl;

	MutantStack<double>::iterator itb = stackOfDouble.begin();
	MutantStack<double>::iterator ite = stackOfDouble.end();

	while (itb != ite)
	{
		std::cout << *itb << std::endl;
		++itb;
	}
	// std::stack<double> testStack(stackOfDouble);
	// std::list<int> testList(mstack.begin(), mstack.end());
}

void test_case_usingList()
{
	std::cout << GREEN << "\n***** TEST CASE: LINKED LIST: *****" << RESETT <<
		std::endl;
	std::list<int> lst;

	std::cout << "Add 2 numbers to list: 5, 17\n"<< std::endl;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Size of list: " << lst.size() << std::endl;
	std::cout << "\nLast element of the list: [" << lst.back() << "]" << std::endl;

	lst.pop_back();
	std::cout << RED << "remove using pop_back(): " << RESETT << std::endl;

	lst.push_back(42);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Create 2 iterators\n" << std::endl;
	std::list<int>::iterator it_b = lst.begin();
	std::list<int>::iterator it_e = lst.end();

	int i = 0;
	while (it_b != it_e)
	{
		std::cout << "List[" << i << "] = " << *it_b << std::endl;
		++it_b;
		i++;
	}
}

int main()
{
	// test_case_subject();
	// test_case_usingDouble();
	test_case_usingList();

	return 0;
}
