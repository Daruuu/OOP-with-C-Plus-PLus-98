#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <ostream>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::processSequence(int argc, char** argv)
{
	for (int i = 0; i < argc - 1; ++i)
	{
		char* endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || *argv == endptr)
		{
			std::cerr << utils::ErrorInvalidChar << value << "'\n";
			return false;
		}
		if (value <= 0)
		{
			std::cerr << utils::ErrorNegativeNumber << value << ")\n";
			return false;
		}
		if (value > INT_MAX)
		{
			std::cerr << utils::ErrorOverflowNumber << value << "'\n";
			return false;
		}
		vectorInteger_.push_back(static_cast<int>(value));
		listInteger_.push_back(static_cast<int>(value));
	}
	utils::printContainer(vectorInteger_);
	return true;
}
