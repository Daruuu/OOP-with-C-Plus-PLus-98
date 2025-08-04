#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
{
	this->name_ = name;
	new Weapon(weapon);
}

void	HumanA::attack()
{
	std::cout << this->name_ << " attacks with his " << this->weapon_.getType()
	<< std::endl;
}
