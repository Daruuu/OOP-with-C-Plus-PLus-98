#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits.h>

class ScalarConverter
{

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

private:
	static bool isChar(const std::string &literal);
	static bool isInteger(const std::string &literal);
	static bool isDouble(const std::string &literal);
	static bool isFloat(const std::string &literal);

	static bool convertToChar(const std::string &literal);
	static bool convertToInteger(const std::string &literal);
	static bool convertToDouble(const std::string &literal);
	static bool convertToFloat(const std::string &literal);

	void printChar(char valueCharacter);
	void printInteger(int valueInteger);
	void printDouble(double valueDouble);
	void printFloat(float valueFloat);

public:
	~ScalarConverter();

	static void convert(const std::string &literal);
};
#endif