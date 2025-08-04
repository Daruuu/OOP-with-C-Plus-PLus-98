#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name_;
	Weapon&		weapon_;

public:
	HumanA(const std::string& name, Weapon& weapon); // pasamos referencia
	HumanA(Weapon myWeapon);

	void	attack();

};

#endif //HUMANA_HPP
