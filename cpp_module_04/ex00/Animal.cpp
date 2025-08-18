#include "Animal.hpp"


Animal::Animal() : type_("Animal")
{
	std::cout << BLUE << "Animal default constructor called." << BLUE << std::endl;
}

Animal::Animal(const Animal& other) : type_(other.type_)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	std::cout << CYAN << "Animal copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called for " << RESET << type_
	<< std::endl;
}

void Animal::makesound()
{
	std::cout << "Animal sound called for " << type_
	<< std::endl;
}
