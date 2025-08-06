#include "Zombie.hpp"

/**
 * create an instance of an object Zombie
 * and allocate in the HEAP.
 */
Zombie*	newZombie(std::string name)
{
	return new Zombie(name);
}
