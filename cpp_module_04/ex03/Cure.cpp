#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->type_ = "cure";
	std::cout <<  "[Cure" << BLUE << "created] with type " << type_ << "." << RESET
	<< std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << CYAN << "[Cure deep copy] constructor called." << RESET
		<< std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		std::cout << CYAN << "[Cure deep copy] assignment operator called." << RESET
		<< std::endl;
	}
}

Cure::~Cure()
{
	std::cout << RED << "[Cure] destructor called for " << RESET << type_
	<< std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << MAGENTA << "[Clone Cure] called for " << RESET << type_
	<< std::endl;
	return (new Cure());
}

//	TODO: update getType to is from target Interface
void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals "<< getType() << "’s wounds *" << std::endl;
}
