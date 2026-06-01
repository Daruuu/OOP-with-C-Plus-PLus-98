#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <vector>

namespace utils
{
	enum { DEBUG = 0 };

	const std::string DefaultMessage=
		"Usage: ./PmergeMe At least 2 integer numbers positives";
	const std::string ErrorInvalidChar =
		"Error: invalid characters in argument '";
	const std::string ErrorNegativeNumber =
		"Error: Only positive integers are allowed (found: ";
	const std::string ErrorOverflowNumber =
		"Error: value overflows integer limit '";
	const std::string ErrorDuplicateNumber =
	"Error: duplicate number '";
	const std::string ErrorAlreadySorted =
	"Error: sequence is already sorted, buen intento. :(";

	template <typename T>
	void printContainer(const T& container, const std::string titleMessage)
	{
		if (!titleMessage.empty())
			std::cout << "*** " << titleMessage << " ***\n";

		typename T::const_iterator it;
		for (it = container.begin(); it != container.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	void printSequencePairs(const T& container)
	{
		typename T::const_iterator it;
		for (it = container.begin(); it != container.end(); ++it)
		{
			std::cout << "(" << it->first << ", " << it->second
				<< ")" << std::endl;
		}
	}

	template <typename TContainer>
	bool isSortedContainer(const TContainer& c)
	{
		if (c.size() <= 1)
			return true;

		typename TContainer::const_iterator prev = c.begin();
		typename TContainer::const_iterator it = c.begin();
		++it;

		for (; it != c.end(); ++it, ++prev)
		{
			if (*it < *prev)
			{
				return false;
			}
		}
		return true;
	}
}

#endif //UTILS_HPP
