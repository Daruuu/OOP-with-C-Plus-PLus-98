#include "Zombie.hpp"

/**
 * create an instance of an object Zombie
 * and allocate in the HEAP.
 */
Zombie* Zombie::zombieHorde(int N, std::string name)
{
	if (name.empty())
		return NULL;

	return (new Zombie(name));
}
