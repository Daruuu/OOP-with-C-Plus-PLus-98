#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>
#include <cmath>
#include <errno.h>
#include <iostream>
#include <limits>

#define RESETT   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

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