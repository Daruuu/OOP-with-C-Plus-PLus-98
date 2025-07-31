#include "Zombie.hpp"

int main(void)
{
	Zombie*	heapZombie = new Zombie("heap zombie");

	if (heapZombie)
		heapZombie->announce();

	heapZombie->randomChump("stack Zombie");

	delete heapZombie;
	return (0);
}
