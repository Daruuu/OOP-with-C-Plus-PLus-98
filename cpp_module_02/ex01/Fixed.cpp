#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : fixedPointValue_(0)
{
	std::cout << BLUE "Default constructor called" RESET
	<< std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << GREEN "Copy constructor called" RESET << std::endl;
	this->fixedPointValue_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << YELLOW "Copy assignment operator called" RESET << std::endl;

	if (this != &other)
		this->fixedPointValue_ = other.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor of Fixed" RESET
	<< std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << CYAN "getRawBits member function called." RESET
	<< std::endl;
	return (this->fixedPointValue_);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << CYAN "setRawBits member function called." RESET
	<< std::endl;
	this->fixedPointValue_ = raw;
}
