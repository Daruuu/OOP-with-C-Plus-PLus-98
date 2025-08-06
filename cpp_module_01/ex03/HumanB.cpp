#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL)
{
	std::cout << GREEN << "[Constructor HumanB] " << name_ << RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << RED << "[Destructor HumanB] " << name_ << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}

void	HumanB::attack() const
{
	if (this->weapon_)
		std::cout << CYAN << this->name_ << " attacks with his "
				  << this->weapon_->getType() << RESET << std::endl;
	else
		std::cout << YELLOW << this->name_ << " has NO weapon to attack." << RESET << std::endl;
}
