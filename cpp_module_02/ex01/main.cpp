#include <iostream>

#include "Fixed.hpp"

int main()
{
	std::cout << "[We are in the main of ex 00]"
			<< std::endl;
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
