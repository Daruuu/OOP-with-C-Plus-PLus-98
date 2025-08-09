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
	std::cout << RED "Destructor called" RESET << std::endl;
}

int Fixed::getRawBits() const
{
	return (this->fixedPointValue_);
}

void Fixed::setRawBits(int const raw)
{
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
	return (float)this->fixedPointValue_ / (1 << fractionalBits_);
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
//	COMPARISON OPERATORS OVERLOAD----------------------------------
bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixedPointValue_ > other.fixedPointValue_);
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->fixedPointValue_ < other.fixedPointValue_;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->fixedPointValue_ >= other.fixedPointValue_;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->fixedPointValue_ <= other.fixedPointValue_;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->fixedPointValue_ == other.fixedPointValue_;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->fixedPointValue_ != other.fixedPointValue_;
}

//	4 ARITHMETIC OPERATORS

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue_ + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue_ - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->fixedPointValue_ * other.getRawBits()) >> fractionalBits_);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	if (other.getRawBits() == 0)
	{
		std::cout << "Error: divide 0" << std::endl;
		return (result);
	}
	result.setRawBits((this->fixedPointValue_ << fractionalBits_) / other.getRawBits());
	return result;
}

//	2 increment and 2 decrement (reference and value)
Fixed& Fixed::operator++()
{
	++this->fixedPointValue_;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++fixedPointValue_;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	--this->fixedPointValue_;
	return (*this);
}

Fixed& Fixed::operator--(int)
{
	Fixed tmp(*this);
	--fixedPointValue_;
	return (*this);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}
