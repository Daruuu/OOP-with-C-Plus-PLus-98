#include <iomanip>

#include "Zombie.hpp"

int main(void)
{
	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	//Zombie*	zombieHorde = new Zombie();
	int	n = 4;
	Zombie*	zombieHorde = zombieHorde(n, "c++ is the best");
	//zombieHorde->zombieHorde(n, "c++ is the best");

	std::cout << std::setw(30) << "---------------------------------------" << std::endl;

	delete[]  zombieHorde;
	return (0);
}
