#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define	RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Fixed
{
private:
	int fixedPointValue_;
	static const int fractionalBits_ = 8;

public:
	// CONSTRUCTORS / DESTRUCTOR / ASSIGNMENT OPERATOR

	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed& other);
	Fixed& operator =(const Fixed& other);
	~Fixed();

	// ACCESSORS AND CONVERSION METHODS

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	/*
	 * COMPARISON OPERATOR OVERLOADS
	 * Allow comparing two Fixed objects using:
	 * >, <, >=, <=, ==, !=
	*/
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;

	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;

	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	/*
	 * ARITHMETIC OPERATOR OVERLOADS
	 * Allow performing math operations (+, -, *, /)
	 * directly between Fixed objects.
	*/
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;

	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	/*
	 * INCREMENT / DECREMENT OPERATOR OVERLOADS
	 * Pre-increment (++x) and post-increment (x++),
	 * pre-decrement (--x) and post-decrement (x--).
	*/
	Fixed& operator++();	//pre-increment
	Fixed operator++(int);	//pos-increment

	Fixed& operator--();	//pre-decrement
	Fixed operator--(int);	//pos-decrement

	/*
	 * STATIC MIN / MAX FUNCTIONS
	 * Return a reference to the smallest or largest value
	 * between two Fixed objects (overloaded for const and non-const).
	*/

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);

	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif //FIXED_HPP
