#ifndef FIXED_HPP
#define FIXED_HPP

#define	RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <iostream>

class Fixed
{

private:
	int					fixedPointValue_;
	static const int	fractionalBits_ = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator =(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
#endif //FIXED_HPP
