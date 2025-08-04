#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name_;
	Weapon		weapon_;

public:
	HumanB();

	void	attack();

};

#endif //HUMANB_HPP
