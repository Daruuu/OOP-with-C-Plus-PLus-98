#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void printContainer(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void test_case_sequenceContainer_vector()
{
	std::vector<int>  sequenceVector;// = {1, 100};
	sequenceVector.push_back(30);
	sequenceVector.push_back(50);
	sequenceVector.push_back(70);
	sequenceVector.push_back(90);
	sequenceVector.push_back(100);

	std::cout << BLUE << "\n******* TEST CASES OF VECTOR: ******\n" << RESETT << std::endl;
	printContainer(sequenceVector);

	try
	{
		std::cout << "Size of vector: " << sequenceVector.size() << std::endl;
		// std::vector<int>::iterator it = easyfind(sequenceVector, 10);
		std::vector<int>::iterator it = easyfind(sequenceVector, 30);

		std::cout << "Value of vector found: [" << *it << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}

void test_case_sequenceContainer_list()
{
	std::list<int>  sequenceList;
	sequenceList.push_back(20);
	sequenceList.push_back(400);
	sequenceList.push_back(60);
	sequenceList.push_back(800);
	sequenceList.push_back(900);
	sequenceList.push_back(100);

	std::cout << GREEN << "\n******* TEST CASES OF LIST: ******\n" << RESETT << std::endl;
	printContainer(sequenceList);

	try
	{
		std::cout << "Size of list: " << sequenceList.size() << std::endl;

		std::list<int>::iterator it = easyfind(sequenceList, 00);

		std::cout << "Value of vector found: [" << *it << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESETT << "\n";
	}
}

void test_case_sequenceContainer_deque()
{
	std::deque<int>  sequenceDeque;

	sequenceDeque.push_front(20);
	sequenceDeque.push_back(4080);
	sequenceDeque.push_front(90);
	sequenceDeque.push_back(80);
	sequenceDeque.push_back(-900);
	sequenceDeque.push_back(-100);

	std::cout << GREEN << "\n******* TEST CASES OF DEQUE: ******\n" << RESETT << std::endl;
	printContainer(sequenceDeque);

	try
	{
		std::cout << "Size of deque: " << sequenceDeque.size() << std::endl;

		std::deque<int>::iterator it = easyfind(sequenceDeque, -100);

		std::cout << "Value of deque found: [" << *it << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESETT << "\n";
	}
}

int main()
{
	test_case_sequenceContainer_vector();
	test_case_sequenceContainer_list();
	test_case_sequenceContainer_deque();

	return (0);
}
