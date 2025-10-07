#include <iostream>
#include <vector>

#include "ScalarConverter.hpp"

#define RESETT   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void runTestGroup(const std::string& groupName, const std::vector<std::string>& testCases)
{
	std::cout << GREEN
			<< "======== TESTING " << groupName << " CASES ========\n"
			<< RESETT << std::endl;

	for (std::vector<std::string>::size_type i = 0; i < testCases.size(); ++i)
	{
		std::cout << CYAN << "[" << groupName << " " << i << "] "
		  << RESETT << "Input: [" << testCases[i] << "] → ";
		ScalarConverter::convert(testCases[i]);
	}
	std::cout << std::endl;

}

std::vector<std::string> vectorTestCharacters()
{
	std::vector<std::string> vectorTestChars;

	vectorTestChars.push_back("a");
	vectorTestChars.push_back("F");
	vectorTestChars.push_back("D");
	vectorTestChars.push_back("A");
	vectorTestChars.push_back("A");
	vectorTestChars.push_back("N");
	vectorTestChars.push_back("Z");

	// Casos que deben fallar
	vectorTestChars.push_back("2");
	vectorTestChars.push_back("ab");
	vectorTestChars.push_back("@");
	vectorTestChars.push_back(" ");
	vectorTestChars.push_back("");
	vectorTestChars.push_back("\\n");
	vectorTestChars.push_back("\t");

	return vectorTestChars;
}

std::vector<std::string> vectorTestIntegers()
{
	// {"1", "2", "100", "1000", "2147483647"};
	std::vector<std::string> vectorTestIntegers;

	vectorTestIntegers.push_back("1");
	vectorTestIntegers.push_back("2");
	vectorTestIntegers.push_back("100");
	vectorTestIntegers.push_back("200");
	vectorTestIntegers.push_back("500");
	vectorTestIntegers.push_back("700");
	vectorTestIntegers.push_back("900");
	vectorTestIntegers.push_back("2147483647");
	vectorTestIntegers.push_back("2147483648");
	vectorTestIntegers.push_back("-2147483647");
	vectorTestIntegers.push_back("-2147483648");
	vectorTestIntegers.push_back("-2147483649");
	vectorTestIntegers.push_back("21474836481");
	vectorTestIntegers.push_back("F");

	return vectorTestIntegers;
}

std::vector<std::string> vectorTestDouble()
{
	std::vector<std::string> tests;
	tests.push_back("5.0");
	tests.push_back("0.0");
	tests.push_back("-4.2");
	tests.push_back("4.2...");
	tests.push_back("6.7");
	tests.push_back("9876543.21");
	tests.push_back("0.0000987");
	tests.push_back("nan");
	tests.push_back("+inf");
	tests.push_back("-inf");
	tests.push_back("1e99999");
	return tests;
}

std::vector<std::string> vectorTestFloat()
{
	std::vector<std::string> vectorTestFloat;

	vectorTestFloat.push_back("5.0");
	vectorTestFloat.push_back("6.7f");
	vectorTestFloat.push_back("9876543.21");
	vectorTestFloat.push_back("9.87654321f");
	vectorTestFloat.push_back("987.654321f");
	vectorTestFloat.push_back("987654.321f");
	vectorTestFloat.push_back("9876543.21f");
	vectorTestFloat.push_back("65.0f");
	vectorTestFloat.push_back("0.0000987654321f");
	vectorTestFloat.push_back("0.0000f87654321f");
	vectorTestFloat.push_back("0.000087654321ff");
	vectorTestFloat.push_back("2147483647.100");
	vectorTestFloat.push_back("9223372036854775807.2147483647");

	return vectorTestFloat;
}

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

	runTestGroup("CHARACTERS", vectorTestCharacters());

	runTestGroup("INTEGERS", vectorTestIntegers());

	runTestGroup("FLOATS", vectorTestFloat());
	runTestGroup("DOUBLES", vectorTestDouble());

	return (0);
}
