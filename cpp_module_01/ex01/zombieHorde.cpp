#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	if (name.empty())
		return NULL;

	return (new Zombie(name));
}
