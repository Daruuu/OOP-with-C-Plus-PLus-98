#include "DiamondTrap.hpp"

/**
 * @brief Default constructor for DiamondTrap.
 *
 * Execution steps:
 * 1. Calls ClapTrap constructor with "Default_clap_name" (virtual base).
 * 2. Calls ScavTrap default constructor.
 * 3. Calls FragTrap default constructor.
 * 4. Initializes DiamondTrap::name_ to "Default".
 * 5. Sets hitPoints_, energyPoints_, and attackDamage_ to values
 *    from FragTrap and ScavTrap.
 */
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name_("Default")
{
	hitPoints_ = 100;      // From FragTrap
	attackDamage_ = 30;    // From FragTrap
	energyPoints_ = 50;    // From ScavTrap
	std::cout << GREEN << "DiamondTrap default constructor called for "
			  << name_ << RESET << std::endl;
}

/**
 * @brief Constructor with name parameter.
 *
 * Execution steps:
 * 1. Calls ClapTrap constructor with name + "_clap_name" (virtual base).
 * 2. Calls ScavTrap constructor with name.
 * 3. Calls FragTrap constructor with name.
 * 4. Initializes DiamondTrap::name_ to name.
 * 5. Sets hitPoints_, energyPoints_, and attackDamage_.
 *
 * @param name The DiamondTrap name.
 */
DiamondTrap::DiamondTrap(const std::string& name) :
ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name)
{
	hitPoints_ = 100;      // From FragTrap
	attackDamage_ = 30;    // From FragTrap
	energyPoints_ = 50;    // From ScavTrap
	std::cout << GREEN << "DiamondTrap constructor called for "
			  << name_ << RESET << std::endl;
}
/**
 * @brief Copy constructor.
 *
 * Execution steps:
 * 1. Calls ClapTrap copy constructor
 * 2. Calls ScavTrap copy constructor
 * 3. Calls FragTrap copy constructor
 * 4. Copies DiamondTrap::name_
 *
 * @param other the DiamondTrap object to copy
 */
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name_(other.name_)
{
	std::cout << BLUE << "DiamondTrap copy constructor called"
			  << RESET << std::endl;
}

/**
 * @brief Copy assignment operator.
 *
 * Execution steps:
 * 1. Checks for self-assignment.
 * 2. Calls ClapTrap assignment operator.
 * 3. Copies DiamondTrap::name_.
 *
 * @param other The DiamondTrap object to assign from.
 * @return Reference to this DiamondTrap.
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << MAGENTA << "DiamondTrap assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name_ = other.name_;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called for "
			  << name_ << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << CYAN
			  << "I am " << name_
			  << " and my ClapTrap name is " << ClapTrap::name_
			  << RESET << std::endl;
}
