#pragma once

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

	//	getter & setter	
	
	std::string	getName();
	void		setName(std::string name);

	//	methods
	void	announce();
	Zombie	*zombieHorde(int N, std::string name);

};

#endif //ZOMBIE_HPP
