#include "Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	this->brain_ = new Brain();	//	init brain pointer
	std::cout <<  "[Cat " << BLUE << "created with Brain.]" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	this->brain_ = new Brain(*other.brain_);

	std::cout << CYAN <<  "[Cat deep copy] constructor called." << RESET
	<< std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->brain_;
		this->brain_ = new Brain(*other.brain_);	// deep copy
	}
	std::cout << CYAN << "[Cat deep copy] assignment operator called" << RESET
	<< std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain_;
	std::cout << RED << "Cat and Brain destructor called for " << RESET << type_
	<< std::endl;
}

void Cat::makeSound() const
{
	std::cout << MAGENTA << "Cat sound: Miauuuu." << RESET
	<< std::endl;
}
