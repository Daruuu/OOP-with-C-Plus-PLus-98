#include "Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	this->brain_ = new Brain();	//	init brain pointer
	std::cout << BLUE << "Cat created with Brain." << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->brain_ = new Brain(*other.brain_);

	std::cout << CYAN <<  "Cat deep copy constructor called." << RESET
	<< std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain_;
		this->brain_ = new Brain(*other.brain_);	// deep copy
	}
	std::cout << CYAN << "Cat deep copy assignment operator called" << RESET
	<< std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Cat and Brain destructor called for " << RESET << type_
	<< std::endl;
}

void Cat::makeSound() const
{
	std::cout << MAGENTA << "Cat sound: miauuuu. " << RESET
	<< std::endl;
}
