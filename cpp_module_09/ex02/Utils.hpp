#ifndef NAMESPACEUTILS_HPP
#define NAMESPACEUTILS_HPP
#include <iostream>

namespace utils
{
	const std::string ErrorInvalidChar = "Error: invalid characters in argument '";
	const std::string ErrorNegativeNumber = "Error: Only positive integers are allowed (found: ";
	const std::string ErrorOverflowNumber= "Error: value overflows integer limit '";

	template <typename T>
	void printContainer(const T& container)
	{
		typename T::const_iterator it;
		for (it = container.begin(); it != container.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

#endif //NAMESPACEUTILS_HPP
