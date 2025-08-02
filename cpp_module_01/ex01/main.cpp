#include <iomanip>

#include "Zombie.hpp"

int main(void)
{
	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	int	n = 4;

	Zombie*	horde = zombieHorde(n, "c++ is the best");

	// zombieHorde->zombieHorde(n, "c++ is the best");

	for (int i = 0; i < n; ++i)
	{
		horde[i].announce();
	}

	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	delete[]  horde;
	return (0);
}
