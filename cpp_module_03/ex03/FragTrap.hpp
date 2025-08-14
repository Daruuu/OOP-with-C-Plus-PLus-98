#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// adding virtual DiamondTrap only has one instance of Claptrap
class FragTrap : virtual public ClapTrap
{
private:

public:
	//	canonical form
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void attack(const std::string& target);
	//	new method
	void highFivesGuys(void);
};

#endif //FRAGTRAP_HPP
