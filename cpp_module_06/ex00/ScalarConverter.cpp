#include "ScalarConverter.hpp"

#include <iostream>

//	======= CONSTRUCTORS =======

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

//	======= METHODS TO CHECK IF TYPE IS CORRECT =======

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 1 && std::isprint(literal[0]) \
		&& std::isalpha(literal[0]) && !std::isdigit(literal[0]));
}

/**
 *
 * std::string::npos = "no encontrado" en operaciones de strings.
 * Internamente es size_t(-1) (el valor más grande que puede tener size_t).
 * Siempre debes compararlo cuando uses funciones como:
 * find, rfind, find_first_of, find_last_of, etc.
 * @return
 */
bool ScalarConverter::isInteger(const std::string& literal)
{
	char *ptr;

	if (literal.empty() || literal.length() > 11)
		return false;
	strtol(literal.c_str(), &ptr, 10);
	return (*ptr == '\0' && literal.find('.') == std::string::npos);
}

/**
 * double is almost always implemented using the 8-byte.
 * IEEE 754 double-precision format.
 */

bool ScalarConverter::isDouble(const std::string& literal)
{
	char *ptr;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		return true;
	}
	strtod(literal.c_str(), &ptr);
	return (*ptr == '\0');
}

/**
 * float is almost always implemented using the 4-byte.
 * IEEE 754 single-precision format.
 */

bool ScalarConverter::isFloat(const std::string& literal)
{
	char *ptr;

	if (literal == "nanf" || literal == "+inf" || literal == "-inf")
		return true;
	if (literal.empty() || literal[literal.size() -1] != 'f')
		return false;

	//	remove 'f'
	std::string numberWithoutF= literal.substr(0, literal.size() - 1);

	strtod(numberWithoutF.c_str(), &ptr);
	return (*ptr == '\0');
}

/*
bool ScalarConverter::convertToChar(const std::string& literal)
{
}

bool ScalarConverter::convertToInteger(const std::string& literal)
{
}

bool ScalarConverter::convertToDouble(const std::string& literal)
{
}

bool ScalarConverter::convertToFloat(const std::string& literal)
{
}
*/

//	======= MAIN METHOD OF CLASS ======

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal) == true)
	{
		std::cout << "is char\n" << std::endl;
	}
	else if (isInteger(literal) == true)
	{
		std::cout << "is integer number\n" << std::endl;
	}
	else if (isDouble(literal) == true)
	{
		std::cout << "is double number\n" << std::endl;
	}
	else if (isFloat(literal) == true)
	{
		std::cout << "is float number\n" << std::endl;
	}
	else
		std::cout << RED << "error type\n" << RESET << std::endl;
}
