#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->type_ = "ice";
	std::cout <<  "[Ice " << BLUE << "created] with type " << type_ << "." << RESET
	<< std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << CYAN << "[Ice deep copy] constructor called." << RESET
		<< std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << CYAN << "[Ice deep copy] assignment operator called" << RESET
	<< std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << RED << "[Ice] destructor called for " << RESET << type_
	<< std::endl;
}

AMateria* Ice::clone() const
{
	std::cout << MAGENTA << "[Clone Ice] called for " << RESET << type_
	<< std::endl;
	return (new Ice());
}

/*
*<name> is the name of the Character passed as a parameter. Don’t print the angle
brackets (< and >).
*/
//	TODO: update getType to is from target Interface
void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << getType() << " *" << std::endl;
}
