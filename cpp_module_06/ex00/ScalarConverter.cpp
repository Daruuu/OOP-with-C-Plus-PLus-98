#include "ScalarConverter.hpp"

//	======= CONSTRUCTORS =======

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

static void printImpossibleAll()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

//	======= METHODS TO CHECK IF TYPE IS CORRECT =======

bool ScalarConverter::isChar(const std::string& literal)
{
	/*
	return (literal.length() == 1 && std::isprint(literal[0]) \
		&& !std::isdigit(literal[0]));
	*/
	return (literal.length() == 1 && std::isprint(literal[0])
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
	if (literal.empty())
		return false;
	if (literal[0] == '+' || literal[0] == '-')
	{
		if (literal.size() == 1)
			return false;
	}
	if (isspace(literal[0]) || isspace(literal[literal.size()-1]))
		return false;

	char* endPtr;
	errno = 0;

	long value = std::strtol(literal.c_str(), &endPtr, 10);

	if (*endPtr != '\0')
		return false;

	if (errno == ERANGE || value > std::numeric_limits<int>::max() || value <
		std::numeric_limits<int>::min())
		return false;

	if (literal.find('.') != std::string::npos)
		return false;
	return true;
}

/**
 * double is almost always implemented using the 8-byte.
 * IEEE 754 double-precision format.
 * 5.18
 * 5.184023023423904820394
 */

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return false;

	char* endPtr;
	errno = 0;

	std::strtod(literal.c_str(), &endPtr);
	if (*endPtr != '\0')
		return false;

	if (errno == ERANGE)
		return false;

	return true;
}

/**
 * float is almost always implemented using the 4-byte.
 * IEEE 754 single-precision format.
 */

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return false;

	if (literal.empty() || literal[literal.size() - 1] != 'f')
		return false;

	//	remove 'f'
	std::string numberWithoutF = literal.substr(0, literal.size() - 1);

	if (numberWithoutF.empty())
		return false;

	char* endPtr;
	errno = 0;
	std::strtod(numberWithoutF.c_str(), &endPtr);
	//	check overflow or underflow
	if (*endPtr != '\0' || errno == ERANGE)
		return false;

	return (true);
}

// ======================= METHODS TO CONVERT =====================

void ScalarConverter::convertToChar(const std::string& literal)
{
	char c = literal[0];

	printChar(c);
	printInteger(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::convertToInteger(const std::string& literal)
{
	long numberConvert = std::strtol(literal.c_str(), NULL, 10);

	if (numberConvert > std::numeric_limits<int>::max()
		|| numberConvert < std::numeric_limits<int>::min())
	{
		printImpossibleAll();
		return;
	}

	int i = static_cast<int>(numberConvert);

	printChar(static_cast<char>(i));
	printInteger(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void ScalarConverter::convertToDouble(const std::string& literal)
{
	double d = 0.0;
	errno = 0;

	if (literal == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else
	{
		errno = 0;
		char* endPtr;
		d = std::strtod(literal.c_str(), &endPtr);

		if (*endPtr != '\0' || errno == ERANGE)
		{
			printImpossibleAll();
			return;
		}
	}

	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible\n";
	else
		printChar(static_cast<char>(d));

	if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		printInteger(static_cast<int>(d));

	printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::convertToFloat(const std::string& literal)
{
	float f = 0.0f;
	errno = 0;

	if (literal == "nanf")
		f = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "+inff")
		f = std::numeric_limits<float>::infinity();
	else if (literal == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else
	{
		// rm 'f' if exist
		std::string num = literal;
		if (num[num.size() - 1] == 'f')
			num = num.substr(0, num.size() - 1);

		errno = 0;
		char* endPtr;
		f = std::strtof(num.c_str(), &endPtr);

		if (*endPtr != '\0' || errno == ERANGE)
		{
			printImpossibleAll();
			return;
		}
	}

	if (std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible\n";
	else
		printChar(static_cast<char>(f));

	if (std::isnan(f) || std::isinf(f)
		|| f > std::numeric_limits<int>::max()
		|| f < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		printInteger(static_cast<int>(f));

	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::printChar(char valueCharacter)
{
	std::cout << "char: ";
	if (std::isprint(valueCharacter))
		std::cout << "'" << valueCharacter << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInteger(int valueInteger)
{
	std::cout << "int: " << valueInteger<< std::endl;
}

void ScalarConverter::printDouble(double valueDouble)
{
	std::cout << "double: " << valueDouble;
	if (valueDouble == static_cast<int>(valueDouble))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::printFloat(float valueFloat)
{
	std::cout << "float: " << valueFloat;
	if (valueFloat == static_cast<int>(valueFloat))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

//	======= MAIN METHOD OF CLASS ======

/*
void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal) == true)
	{
		std::cout << YELLOW << "is char\n" << RESETT << std::endl;
	}
	else if (isInteger(literal) == true)
	{
		std::cout << BLUE << "is integer number\n" << RESETT << std::endl;
	}
	else if (isDouble(literal) == true)
	{
		std::cout << MAGENTA << "is double number\n" << RESETT << std::endl;
	}
	else if (isFloat(literal) == true)
	{
		std::cout << CYAN << "is float number\n" << RESETT << std::endl;
	}
	else
		std::cout << RED << "error type\n" << RESETT << std::endl;
}
*/
void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal) == true)
	{
		convertToChar(literal);
		// std::cout << YELLOW << "is char\n" << RESETT << std::endl;
	}
	else if (isInteger(literal) == true)
	{
		convertToInteger(literal);
		// std::cout << BLUE << "is integer number\n" << RESETT << std::endl;
	}
	else if (isDouble(literal) == true)
	{
		convertToDouble(literal);
		// std::cout << MAGENTA << "is double number\n" << RESETT << std::endl;
	}
	else if (isFloat(literal) == true)
	{
		// std::cout << CYAN << "is float number\n" << RESETT << std::endl;
		convertToFloat(literal);
	}
	else
		std::cout << RED << "Error: invalid input\n" << RESETT << std::endl;
}

