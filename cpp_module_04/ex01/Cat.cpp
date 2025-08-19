#include "Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	std::cout << BLUE << "Cat created." << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << CYAN <<  "Cat copy constructor called." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << CYAN << "Cat copy assignment operator called" << RESET
	<< std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called for " << RESET << type_
	<< std::endl;
}

void Cat::makeSound() const
{
	std::cout << MAGENTA << "Cat sound: miauuuu. " << RESET
	<< std::endl;
}
