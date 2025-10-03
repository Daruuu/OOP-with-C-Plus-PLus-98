#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cstring>

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

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 1 && std::isprint(literal[0]) \
		&& std::isalpha(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInteger(const std::string& literal)
{
	char *ptr = &literal;

		// literal.at(0) == '-')
	if (literal.length() < 1 && literal.max_size() > 11)
	{
		return false;
	}
	strtol(literal.c_str(), &ptr, 10);
	//	42.
	return (*ptr == '\0' && literal.find('.') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	char *ptr;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		return true;
	}
	strtof(literal.c_str(), &ptr);
	// return (*ptr == 'f');
	return (false);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
}

void ScalarConverter::convert(const std::string& literal)
{
}
