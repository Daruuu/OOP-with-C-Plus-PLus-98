#include "Dog.hpp"

#include "Brain.hpp"

Dog::Dog()
{
	type_ = "Dog";
	this->brain_ = new Brain();	//	init brain pointer
	std::cout << "[Dog " << BLUE << "created with Brain.]" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	this->brain_ = new Brain(*other.brain_);	//	deep copy
	std::cout << CYAN <<  "[Dog deep copy] constructor called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->brain_;
		this->brain_ = new Brain(*other.brain_);	// deep copy
	}
	std::cout << CYAN << "[Dog deep copy] assignment operator called" << RESET
	<< std::endl;
	return *this;
}

Dog::~Dog()
{
	delete brain_;
	std::cout << RED << "Dog and Brain destructor called for " << RESET << type_
	<< std::endl;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << "Dog sound: Guaooo" << RESET
	<< std::endl;
}
