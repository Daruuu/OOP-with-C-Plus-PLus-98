#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits.h>
#include <cstdlib>
#include <string>
#include <cstring>

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

	static void convertToChar(const std::string& literal);
	static void convertToInteger(const std::string& literal);
	static void convertToDouble(const std::string& literal);
	static void convertToFloat(const std::string& literal);

	static void printChar(char valueCharacter);
	static void printInteger(int valueInteger);
	static void printDouble(double valueDouble);
	static void printFloat(float valueFloat);

public:
	~ScalarConverter();

	static void convert(const std::string &literal);
};
#endif