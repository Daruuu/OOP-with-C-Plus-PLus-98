#include "Fixed.hpp"

#include <cmath>

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

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	// 00000000 00000000 00000000 00101010   ← 42 in binary before shift
	// 00000000 00000000 00101010 00000000   ← after shift
	this->fixedPointValue_ = intValue << fractionalBits_;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	//	(1 << 8 ) = 256
	//	42.42f * (256) = 10859.52
	//	rounf ( 10859.52) = 10860
	this->fixedPointValue_ = roundf(floatValue * (1 << fractionalBits_));
}

float Fixed::toFloat() const
{
	return (float) this->fixedPointValue_ / (1 << fractionalBits_);
}

int Fixed::toInt() const
{
	return this->fixedPointValue_ >> fractionalBits_;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
