#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type_ = "wrongCat";
	std::cout << GREEN << "[WrongCat] default constructor called." << RESET
	<< std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << GREEN <<  "[WrongCat] copy constructor called." << RESET
	<< std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << GREEN << "[WrongCat] copy assignment operator called." << RESET
	<< std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "[WrongCat] " << RESET << "destructor called for " << type_ << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << GREEN << "[WrongCat] sound(): Miauuu (won't be called via base)" << RESET
	<< std::endl;
}
