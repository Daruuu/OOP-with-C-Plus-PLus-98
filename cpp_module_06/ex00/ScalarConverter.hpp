#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	static bool isChar(const std::string &literal);

public:
	static void convert(const std::string &literal);

};
#endif