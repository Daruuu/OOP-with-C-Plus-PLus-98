#include "PmergeMe.hpp"
#include <cctype>

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

void PmergeMe::processSequence(char** argv)
{
	unsigned int i = 0;
	unsigned int count = 0;

	while (argv[i] != NULL)
	{
		if (isdigit(argv[i]))
			++count;
	}
	for (unsigend int number; number < )

}

