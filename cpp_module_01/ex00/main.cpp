#include <iomanip>

#include "Zombie.hpp"

int main(void)
{
	std::cout << std::setw(30) << "---------------------------------------" << std::endl;
	Zombie*	heapZombie = new Zombie("heap zombie");

	heapZombie->announce();

	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	randomChump("stack Zombie");

	delete heapZombie;
	return (0);
}
