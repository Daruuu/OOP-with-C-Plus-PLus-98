#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: name_(name), weapon_(weapon) { }

HumanA::~HumanA()
{
	std::cout << "Destructor HumanA with name: " << this->name_
	<< std::endl;
}

void	HumanA::attack() const
{
	std::cout << this->name_ << " attacks with his " << this->weapon_.getType()
	<< std::endl;
}
