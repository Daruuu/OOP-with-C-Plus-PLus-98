#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

// Colores ANSI
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

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
