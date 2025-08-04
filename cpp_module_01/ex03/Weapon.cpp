#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type_ = type;
	std::cout << "Constructor Weapon with parameter: " << type_ << " called." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destructor Weapon " << type_ << " called." << std::endl;
}

const std::string& Weapon::getType() const
{
	return (this->type_);
}

void Weapon::setType(std::string type)
{
	this->type_ = type;
}

