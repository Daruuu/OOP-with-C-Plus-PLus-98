#include <iostream>

#include "Span.hpp"

void test_case_maxIntegers()
{
	try
	{
		Span sp(5);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483648);
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

void test_case_onlyOneNumberInContainer()
{
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
int main()
{
	// test_case_maxIntegers();
	test_case_onlyOneNumberInContainer();
	/*
	try
	{
		Span sp(5);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
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
	*/

	return (0);
}
