#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: name_(name), weapon_(weapon)
{
	std::cout << GREEN << "[Constructor HumanA] " << name_ << RESET << std::endl;
}

HumanA::~HumanA()
{
	std::cout << RED << "[Destructor HumanA] " << this->name_ << RESET << std::endl;
}

void	HumanA::attack() const
{
	std::cout << CYAN << this->name_ << " attacks with his ["
			  << this->weapon_.getType() << "]" << RESET << std::endl;
}
