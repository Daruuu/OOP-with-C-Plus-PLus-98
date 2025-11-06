#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <set>

void test_case_subject()
{
	std::cout << GREEN << "***** TEST CASE: SUBJECT *****" << RESETT <<
		std::endl;
	MutantStack<int> mstack;

	std::cout << "\nAdd 2 numbers: [5, 10]\n" << std::endl;

	mstack.push(5);
	mstack.push(10);

	std::cout << "\nNumber at top of stack: " << mstack.top() << std::endl;

	std::cout << "\nSize of stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(1);
	mstack.push(-2147483647);
	mstack.push(2147483647);
	std::cout << "\nSize of stack: " << mstack.size() << std::endl;

	//mstack.pop();

	//std::cout << "\nSize of stack after use pop(): " << mstack.size() << std::endl;

	MutantStack<int>::iterator itb = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	int i = 1;
	while (itb != ite)
	{
		std::cout << "Stack[" << i << "]=" << *itb << std::endl;
		++i;
		++itb;
	}
}

void test_case_usingDouble()
{
	std::cout << GREEN << "\n***** TEST CASE: MUTANSTACK with Double: *****" <<
		RESETT << std::endl;

	MutantStack<double> stackOfDouble;
	int index;

	std::cout << "\nPushing elements: 10.8, 1.0" << std::endl;

	stackOfDouble.push(10.80);
	stackOfDouble.push(1.0);

	std::cout << "Top element: [" << stackOfDouble.top() << "]" <<
		std::endl;

	std::cout << "Size of stack: " << stackOfDouble.size() << std::endl;
	std::cout << "\nPushing more: 3.42, 42, -2147483647.0" << std::endl;

	stackOfDouble.push(3.42);
	stackOfDouble.push(42);
	stackOfDouble.push(-2147483647);

	std::cout << "\nnew size: " << stackOfDouble.size() << std::endl;

	std::cout << "\nUsing an alias of iterator, call 'pos':\n";

	MutantStack<double>::iterator pos;
	index = 1;
	for (pos = stackOfDouble.begin(); pos != stackOfDouble.end(); ++pos) {
		// *pos = toupper(*pos);
		std::cout << "  [" << index++ << "] = " << *pos << std::endl;
	}
	// type of the collection

	std::cout << "\nUsing 2 alias of iterator, begin and end:\n";
	MutantStack<double>::iterator itb = stackOfDouble.begin();
	MutantStack<double>::iterator ite = stackOfDouble.end();
	index = 0;
	while (itb != ite)
	{
		std::cout << "  [" << index++ << "] = " << *itb << std::endl;
		++itb;
	}
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


	lst.push_back(42);
	lst.push_back(737);
	lst.push_back(37);
	lst.push_back(7);
	lst.push_back(7);
	lst.push_back(-0);

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
	std::cout << RED << "remove 2 times using pop_back(): " << RESETT << std::endl;
	lst.pop_back();
	lst.pop_back();
	std::cout << "Top after 2 removes in list: " << lst.front() << std::endl;
	std::cout << "Size after popping: " << lst.size() << std::endl;
}

int main()
{
	test_case_subject();
	test_case_usingDouble();
	test_case_usingList();

	return 0;
}
