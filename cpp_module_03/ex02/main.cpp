#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap claptrap("Clap-9000");

	claptrap.attack("Moulinex");
	claptrap.takeDamage(3);
	claptrap.beRepaired(5);
	claptrap.attack("Moulinex Beta");
	claptrap.takeDamage(12);
	claptrap.attack("Moulinex 2.0");

	std::cout << std::endl;

	ScavTrap scavtrap("Scav");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(10);
	scavtrap.attack("Moulinx");
	scavtrap.takeDamage(50);
	scavtrap.attack("Moulinex 2.0");
	scavtrap.guardGate();

	std::cout << std::endl;
    return 0;
}
