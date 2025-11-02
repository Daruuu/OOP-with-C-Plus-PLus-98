#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
	this->type_ = type;
	std::cout << BLUE << "Constructor Weapon with parameter: " << RESET << CYAN << "[" << type_  << "]" << RESET
	<< std::endl;
}

Weapon::~Weapon()
{
	std::cout << RED << "Destructor Weapon " << MAGENTA "[" << type_ << "]" << MAGENTA << RESET
	<< std::endl;
}

const std::string& Weapon::getType() const
{
	return (this->type_);
}

void Weapon::setType(std::string type)
{
	this->type_ = type;
}

