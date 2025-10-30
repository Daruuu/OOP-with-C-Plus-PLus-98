#include <iostream>

#include "Span.hpp"

void test_case_TwoMaxValuesInVector()
{
	std::cout << GREEN << "\n***** [Test 01]:  TWO MAX VALUE IN CONTAINER *****\n" << RESETT << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(-2147483647);
		sp.addNumber(2147483647);
		for (unsigned int i = 0; i < sp.size(); i++)
		{
			std::cout << sp[i] << " ";
		}
		
		std::cout << "Shortest Span : "<< sp.shortestSpan()  << std::endl;
		std::cout << "Longest Span : "<< sp.longestSpan()  << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << "Leng Error: " << e.what() << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << "Overflow Error: " << e.what() << std::endl;
	}
}

void test_case_onlyOneValueInContainer()
{
	std::cout << GREEN << "\n***** [Test 02]:  ONLY 1 VALUE IN CONTAINER *****\n" << RESETT << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(3);
		std::cout << "Shortest Span : "<< sp.shortestSpan()  << std::endl;
		std::cout << "Longest Span : "<< sp.longestSpan()  << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << "Leng Error: " << e.what() << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << "Overflow Error: " << e.what() << std::endl;
	}
}

void test_case_withXNumbers()
{
	std::cout << GREEN << "\n***** [Test 03]:  X VALUES IN CONTAINER *****\n" << RESETT << std::endl;
	try
	{
		Span sp(6);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span : "<< sp.shortestSpan()  << std::endl;
		std::cout << "Longest Span : "<< sp.longestSpan()  << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << RED << "Leng Error: " << e.what() << RESETT << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << RED << "Overflow Error: " << e.what() << RESETT << std::endl;
	}
}

void test_case_emptyContainer()
{
	std::cout << GREEN << "\n***** [Test 04]: EMPTY CONTAINER *****\n" << RESETT << std::endl;
	try
	{
		Span sp(5);
		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << "Leng Error: " << e.what() << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << "Overflow Error: " << e.what() << std::endl;
	}
}

void test_case_maxCapacity()
{
	std::cout << GREEN << "\n***** [Test 05]: MAX CAPACITY *****\n" << RESETT << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << "Leng Error: " << e.what() << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << "Overflow Error: " << e.what() << std::endl;
	}
}

void test_case_largeContainerVector()
{
	std::cout << GREEN << "\n***** [Test 06]: Large CAPACITY of 10.000 *****\n" << RESETT << std::endl;
	try
	{
		int length = 10000;

		Span sp(length);
		for (int i = 0; i < length; ++i)
		{
			sp.addNumber(i);
		}
		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << "Leng Error: " << e.what() << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << "Overflow Error: " << e.what() << std::endl;
	}
}

int main()
{
	test_case_TwoMaxValuesInVector();
	// test_case_onlyOneValueInContainer();
	// test_case_withXNumbers();
	// test_case_emptyContainer();
	// test_case_maxCapacity();
	test_case_largeContainerVector();

	return (0);
}
