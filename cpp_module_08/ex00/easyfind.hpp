#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename  T::iterator easyfind(T &container, int valueToFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), valueToFind);
	if (it == container.end())
		throw std::runtime_error("value not found in container");
	return it;
}

#endif
