#include <iostream>
#include <vector>

#include "ScalarConverter.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main(int argc, char* argv[])
{
	(void)argv;
	(void)argc;

	/*
	if (argc != 2)
	{
		std::cerr << RED << "Error: invalid num of args. :(" << RESET << std::endl;
		return (1);
	}
	*/

	std::vector<std::string> vectorTestChars;
	vectorTestChars.push_back("a");
	vectorTestChars.push_back("d");
	vectorTestChars.push_back("D");
	vectorTestChars.push_back("A");
	vectorTestChars.push_back("A");
	vectorTestChars.push_back("N");
	vectorTestChars.push_back("Z");

	// Casos que deben fallar
	vectorTestChars.push_back("2");      // dígito
	vectorTestChars.push_back("ab");     // más de un char
	vectorTestChars.push_back("@");      // símbolo
	vectorTestChars.push_back(" ");      // espacio
	vectorTestChars.push_back("");       // vacío
	vectorTestChars.push_back("\n");     // no imprimible (newline)
	vectorTestChars.push_back("\t");

	std::cout << GREEN << "======== TESTING OF CHARACTERS CASES:========\n" <<
		RESET << std::endl;

	for (std::vector<std::string>::size_type i = 0; i < vectorTestChars.size();
		++i)
	{
		std::cout << "Test Characters [" << i << "]: " << "[" << vectorTestChars[i] << "] -> ";
		ScalarConverter::convert(vectorTestChars[i]);
	}

	std::vector<std::string> vectorTestIntegers;
	// {"1", "2", "100", "1000", "2147483647"};
	vectorTestIntegers.push_back("1");
	vectorTestIntegers.push_back("2");
	vectorTestIntegers.push_back("100");
	vectorTestIntegers.push_back("200");
	vectorTestIntegers.push_back("500");
	vectorTestIntegers.push_back("700");
	vectorTestIntegers.push_back("900");
	vectorTestIntegers.push_back("2147483647");
	vectorTestIntegers.push_back("2147483649");

	std::cout << GREEN << "======== TESTING OF INTEGERS CASES:========\n" <<
		RESET << std::endl;

	for (std::vector<std::string>::size_type i = 0; i < vectorTestIntegers.
		size(); ++i)
	{
		std::cout << "Test Integers [" << i << "]: " << "[" << vectorTestIntegers[i] << "] -> ";
		ScalarConverter::convert(vectorTestIntegers[i]);
	}

	std::vector<std::string> vectorTestFloat;

	vectorTestFloat.push_back("5.0");
	vectorTestFloat.push_back("6.7f");
	vectorTestFloat.push_back("9876543.21");
	vectorTestFloat.push_back("9.87654321f");
	vectorTestFloat.push_back("987.654321f");
	vectorTestFloat.push_back("987654.321f");
	vectorTestFloat.push_back("9876543.21f");
	vectorTestFloat.push_back("0.0000987654321f");
	vectorTestFloat.push_back("2147483647.100");

	std::cout << GREEN << "======== TESTING OF FLOAT CASES:========\n" << RESET
		<< std::endl;

	for (std::vector<std::string>::size_type i = 0; i < vectorTestFloat.size();
		++i)
	{
		std::cout << "Test Float[" << i << "]: " << "[" << vectorTestChars[i] << "] -> ";
		ScalarConverter::convert(vectorTestChars[i]);
	}
	return (0);
}
