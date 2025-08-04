#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL) { }

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}

void HumanB::attack()
{
	if (this->weapon_)
		std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << std::endl;

	else
	{
		std::cout << this->name_ << " has NO weapon to attack." << std::endl;
	}
}
