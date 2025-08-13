#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string name_;
	int hitPoints_;
	int energyPoints_;
	int attackDamage_;

public:
	//	canonical form
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	//	Extra constructor
	ClapTrap(const std::string& name);

	//	getters
	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;

	//	setters
	void setName(const std::string& name);
	void setHitPoints(int hit_points);
	void setEnergyPoints(int energy_points);
	void setAttackDamage(int attack_damage);

	//	methods
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP
