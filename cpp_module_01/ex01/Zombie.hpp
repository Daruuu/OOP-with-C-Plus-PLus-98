#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name_;

public:
	Zombie();
	~Zombie();

	//	setter
	void	setName(std::string name);
	//	methods
	void	announce();

};

Zombie*	zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP
