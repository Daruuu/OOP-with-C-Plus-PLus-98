#include <iomanip>

#include "Zombie.hpp"

int main(void)
{
	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	Zombie*	zombieHorde = new Zombie();

	zombieHorde->zombieHorde(4, "c++ is the best");

	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	delete  zombieHorde;
	return (0);
}
