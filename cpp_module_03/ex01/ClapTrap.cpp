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
	std::cout << "ClapTrap destructor called for " << name_
	<< std::endl;
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

/**
 * @brief   Attacks a target, causing damage equal to attackDamage_.
 *          Costs 1 energy point to perform the attack.
 *          Does nothing if hitPoints_ <= 0 or energyPoints_ <= 0.
 *
 * @param   target The name of the entity being attacked.
 */
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

/**
 * @brief   Reduces the ClapTrap's hit points by the given amount.
 *          If hitPoints_ drops below 0, it is set to 0.
 *
 * @param   amount The amount of damage to take.
 */
void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints_ -= amount;
	if (hitPoints_ < 0)
		hitPoints_ = 0;
	std::cout << "ClapTrap " << name_ << " takes " << amount
		<< " points of damage! Remaining HP: " << hitPoints_ << std::endl;
}

/**
 * @brief   Repairs the ClapTrap by increasing hitPoints_ by the given amount.
 *          Costs 1 energy point to perform the repair.
 *          Does nothing if hitPoints_ <= 0 or energyPoints_ <= 0.
 *
 * @param   amount The amount of HP to restore.
 */
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
