#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
	std::cout << YELLOW << "[WrongAnimal] default constructor called." << RESET
	<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_)
{
	std::cout << YELLOW <<  "[WrongAnimal] copy constructor called." << RESET << type_
	<< std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	std::cout << YELLOW << "[WrongAnimal] copy assignment operator called" << RESET
	<< type_ << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "[WrongAnimal] " << RESET << "destructor called for "
	<< type_ << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << YELLOW << "[WrongAnimal] sound(): generic sound-> " << RESET
	<< type_ << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type_;
}
