#include "Zombie.hpp"

// Creates a zombie on the STACK and makes it announce itself

void	randomChump(std::string name)
{
	Zombie	newZombieInStack(name);

	newZombieInStack.announce();
}
