#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << GREEN << "ScavTrap Default constructor called" << RESET
	<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << GREEN << "ScavTrap " << name_ << " with " << YELLOW  "NAME" << GREEN " is created!" << RESET
	<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << BLUE << "ScavTrap copy constructor called" << RESET
	<< std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << MAGENTA << "ScavTrap Assignment operator called" << RESET
	<< std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << name_ << RESET
	<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints_ > 0 && energyPoints_ > 0)
	{
		std::cout << YELLOW << "ScavTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!" << RESET
		<< std::endl;
		energyPoints_--;
	}
	else if (hitPoints_ <= 0)
	{
		std::cout << "ScavTrap " << name_ << " cannot attack because it's out of hit points!"
		<< std::endl;
	}
	else
		std::cout << "ScavTrap " << name_ << " is out of energy and cannot attack!"
		<< std::endl;
}

void ScavTrap::guardGate() const
{
	std::cout << CYAN << "ScavTrap " << name_ << " is now in Gate keeper mode." << RESET
	<< std::endl;
}
