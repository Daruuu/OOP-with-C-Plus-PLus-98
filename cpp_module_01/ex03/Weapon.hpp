#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string	type_;

public:

	Weapon(std::string type);
	~Weapon();

	const std::string&	getType() const;
	void		setType(std::string type);

};

#endif //WEAPON_HPP
