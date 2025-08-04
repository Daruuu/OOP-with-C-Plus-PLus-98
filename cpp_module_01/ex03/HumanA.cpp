#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA()
{
}

HumanA::HumanA(Weapon myWeapon)
{
}

void HumanA::attack()
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
	<< std::endl;
}
