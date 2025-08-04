#include <iomanip>

#include "Zombie.hpp"

int main(void)
{
	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	int	n = 3;

	Zombie*	horde = zombieHorde(n, "horde 01");

	for (int i = 0; i < n; ++i)
	{
		horde[i].announce();
	}

	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	delete[]  horde;
	return (0);
}
