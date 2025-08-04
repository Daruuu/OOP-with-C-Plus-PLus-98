#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name_;
	Weapon&		weapon_;	//is a reference

public:
	HumanA(const std::string& name, Weapon& weapon); // pasamos referencia
	~HumanA();

	void	attack() const;

};

#endif //HUMANA_HPP
