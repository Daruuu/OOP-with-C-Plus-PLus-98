#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL)
{
	std::cout << " Constructor HumanB: " << this->name_ << std::endl;
}

HumanB::~HumanB()
{
	std::cout << " Destructor HumanB: " << name_ << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}

void	HumanB::attack() const
{
	if (this->weapon_)
		std::cout << this->name_ << " attacks with his " << this->weapon_->getType() << std::endl;
	else
	{
		std::cout << this->name_ << " has NO weapon to attack." << std::endl;
	}
}
