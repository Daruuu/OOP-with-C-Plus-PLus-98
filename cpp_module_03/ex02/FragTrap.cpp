#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << GREEN << "FragTrap Default constructor called" << RESET
	<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << GREEN << "FragTrap " << name_ << " with " << YELLOW  "NAME" << GREEN " is created!" << RESET
	<< std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << BLUE << "ScavTrap copy constructor called" << RESET
	<< std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << MAGENTA << "FragTrap Assignment operator called" << RESET
	<< std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called for " << name_ << RESET
	<< std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints_ > 0 && energyPoints_ > 0)
	{
		std::cout << YELLOW << "FragTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!" << RESET
		<< std::endl;
		energyPoints_--;
	}
	else if (hitPoints_ <= 0)
	{
		std::cout << "FragTrap " << name_ << " cannot attack because it's out of hit points!"
		<< std::endl;
	}
	else
		std::cout << "FragTrap " << name_ << " is out of energy and cannot attack!"
		<< std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name_ << " requests a positive high five!"
	<< std::endl;
}
