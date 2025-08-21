#include "AMateria.hpp"

AMateria::AMateria() : type_("AMateria Default")
{
	std::cout << GREEN << "[AMateria] default constructor called." << RESET
		<< std::endl;
}

AMateria::AMateria(std::string const& type) : type_(type)
{
	std::cout << GREEN << "[AMateria] constructor with type called." << RESET
		<< std::endl;
}

AMateria::AMateria(const AMateria& other) : type_(other.type_)
{
	std::cout << CYAN << "[AMateria copy] constructor called" << RESET
		<< std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type_ = other.type_;
	std::cout << CYAN << "[AMateria copy] assignment operator called." << RESET
		<< std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << RED << "[AMateria destructor] called for " << RESET << type_
		<< std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << this->type_ << " on " << target.getName() << " *"
		<< std::endl;
}

std::string const& AMateria::getType() const
{
	return this->type_;
}
