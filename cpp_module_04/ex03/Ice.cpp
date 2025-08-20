#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria()
{
	this->type_ = "Ice";
}

Ice::Ice(const Ice& other) : AMateria()
{
}

Ice& Ice::operator=(const Ice& other)
{
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at <name> *" << std::endl;
}
