#include "HumanA.hpp"
#include "Weapon.hpp"

#include <iostream>

// HumanA::HumanA() { }

HumanA::HumanA(const std::string& name, Weapon& weapon)
{
	this->name_ = name;
	new Weapon(weapon);
}

void	HumanA::attack()
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
	<< std::endl;
}
