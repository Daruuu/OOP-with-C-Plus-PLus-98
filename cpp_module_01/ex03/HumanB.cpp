#include "HumanB.hpp"

HumanB::HumanB()
{
}

void HumanB::attack()
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
	<< std::endl;
}
