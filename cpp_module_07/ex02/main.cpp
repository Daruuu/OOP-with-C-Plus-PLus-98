#include <iostream>

#include "Array.hpp"

void test_emptyArray()
{
	std::cout << GREEN << " ********** [TEST 01] EMPTY ARRAY ********** " << RESETT << std::endl;
	try
	{
		Array<int> arrayIntegers;
		std::cout << "Array size: " << arrayIntegers.size() << std::endl;
	}
	catch (...)
	{
		std::cout << "unexpected exception\n" << std::endl;
	}
}

void test_ArrayWithTeenNumbers()
{
	std::cout << GREEN << " **********  [TEST 02] ARRAY of 10 elements: ********** " << RESETT << std::endl;
	try
	{
		Array<int> arrayIntegers(10);
		std::cout << "Array size: " << arrayIntegers.size() << std::endl;
		for (unsigned int i = 0; i < arrayIntegers.size(); ++i)
		{
			arrayIntegers[i] = i * 2;
		}
		for (unsigned int i = 0; i < arrayIntegers.size(); ++i)
			std::cout << "a[" << i << "] = " << arrayIntegers[i] << "\n";
		std::cout << "\n";
	}
	catch (...)
	{
		std::cout << "unexpected exception\n" << std::endl;
	}
}


void test_copyConstructor() {
	std::cout << GREEN << "[TEST 03] Copy constructor\n" << RESETT;

	Array<int> original(3);
	for (unsigned int i = 0; i < original.size(); ++i)
		original[i] = i + 1;

	Array<int> copy(original);
	copy[0] = -432;

	std::cout << "Original[0]: " << original[0] << "\n";
	std::cout << "Copy[0]: " << copy[0] << "\n\n";
}

void test_assignmentOperator()
{
	std::cout << GREEN << "[TEST 04] Assignment operator\n" << RESETT;

	try
	{
		Array<int> a(2);
		a[0] = 10; a[1] = 20;
		Array<int> b;
		b = a;
		b[1] = 42;
		// b[2] = 2147483647;

		std::cout << "a[1]: " << a[1] << "\n";
		std::cout << "b[1]: " << b[1] << "\n";
		std::cout << "b[2]: " << b[2] << "\n\n";
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "Caught out_of_range exception: "
				  << e.what() << RESETT << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Unexpected std::exception: "
				  << e.what() << RESETT << "\n";
	}
	catch (...)
	{
		std::cout << "unexpected exception\n" << std::endl;
	}
}

void test_outOfRange() {
	std::cout << GREEN << "\n[TEST 05] Out of Range Exception\n" << RESETT;

	Array<int> a(2);
	try {
		std::cout << a[5] << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Exception: " << e.what() << RESETT << "\n\n";
	}
}

int main()
{
	test_emptyArray();
	test_ArrayWithTeenNumbers();
	test_copyConstructor();
	test_assignmentOperator();
	test_outOfRange();
	return (0);
}
