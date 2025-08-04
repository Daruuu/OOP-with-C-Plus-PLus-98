#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string	type_;

public:

	Weapon() {}
	Weapon(std::string type);

	std::string	getType();
	void		setType(std::string newType);

};

#endif //WEAPON_HPP
