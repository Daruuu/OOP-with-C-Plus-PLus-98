#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << GREEN << "[AAnimal] default constructor called." << RESET
	<< std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type_(other.type_)
{
	std::cout << CYAN <<  "[AAnimal copy] constructor called." << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	std::cout << CYAN << "[AAnimal copy] assignment operator called" << RESET << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << RED << "[AAnimal] destructor called for " << RESET << type_
	<< std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << MAGENTA << "AAnimal sound called for " << RESET << type_
	<< std::endl;
}

std::string AAnimal::getType() const
{
	return this->type_;
}
