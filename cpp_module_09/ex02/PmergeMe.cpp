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
	for (int i = 1; i < argc; i++)
	{
		char* endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || argv[i] == endptr)
		{
			std::cerr << "Error: invalid charaters in argument '" << argv[i] <<
				"'";
			return false;
		}
		if (value <= 0)
		{
			std::cerr << "Error: Only positive integers are allowed (found: " <<
				value << ")";
			return false;
		}
		if (value > INT_MAX)
		{
			std::cerr << "Error: value overflows integer limit '" << argv[i] <<
				"'";
			return false;
		}
		vectorInteger_.push_back(static_cast<int>(value));
		listInteger_.push_back(static_cast<int>(value));
	}
	return true;
}
