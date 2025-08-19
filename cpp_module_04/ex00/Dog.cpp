#include "Dog.hpp"

Dog::Dog()
{
	type_ = "Dog";
	std::cout << BLUE << "Dog created." << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << CYAN <<  "Dog copy constructor called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << CYAN << "Dog copy assignment operator called" << RESET
	<< std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called for " << RESET << type_
	<< std::endl;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << "Dog sound " << RESET << type_
	<< std::endl;
}
