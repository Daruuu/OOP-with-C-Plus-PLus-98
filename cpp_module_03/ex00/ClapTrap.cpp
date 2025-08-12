#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("Default"), hitPoints_(10), energyPoints_(10),
						attackDamage_(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name_(other.name_),
											hitPoints_(other.hitPoints_),
											energyPoints_(other.energyPoints_),
											attackDamage_(other.attackDamage_)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name_ = other.name_;
		this->hitPoints_ = other.hitPoints_;
		this->energyPoints_ = other.energyPoints_;
		this->attackDamage_ = other.attackDamage_;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << name_ << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name_(name), hitPoints_(10),
											energyPoints_(10), attackDamage_(0)
{
	std::cout << "ClapTrap name constructor called for " << name_ << std::endl;
}

std::string ClapTrap::getName() const { return this->name_; }

int ClapTrap::getHitPoints() const
{
	return this->hitPoints_;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints_;
}

int ClapTrap::getAttackDamage() const
{
	return this->attackDamage_;
}

void ClapTrap::setName(const std::string& name)
{
	this->name_ = name;
}

void ClapTrap::setHitPoints(int hit_points)
{
	this->hitPoints_ = hit_points;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
	this->energyPoints_ = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
	this->attackDamage_ = attack_damage;
}

/*

When ClapTrap repairs itself, it regains <amount> hit points. Attacking and repairing
each cost 1 energy point.

Of course, ClapTrap can’t do anything if it has no hit points or
energy points left.

However, since these exercises serve as an introduction, the ClapTrap
instances should not interact directly with one another, and the parameters will not refer
to another instance of ClapTrap
*/

// When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
void ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ <= 0 || energyPoints_ <= 0)
	{
		std::cout << "ClapTrap " << name_ << " cannot attack!" << std::endl;
		return;
	}
	energyPoints_--;
	std::cout << "ClapTrap " << name_ << " attacks " << target
		<< ", causing " << attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints_ -= amount;
	if (hitPoints_ < 0)
		hitPoints_ = 0;
	std::cout << "ClapTrap " << name_ << " takes " << amount
		<< " points of damage! Remaining HP: " << hitPoints_ << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ <= 0 || energyPoints_ <= 0)
	{
		std::cout << "ClapTrap " << name_ << " cannot attack!" << std::endl;
		return;
	}
	hitPoints_ += amount;
	energyPoints_--;
	std::cout << "ClapTrap " << name_ << " repairs itself for "
		<< amount << " HP! Total HP: " << hitPoints_ << std::endl;
}
