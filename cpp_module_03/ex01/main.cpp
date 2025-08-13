#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("ClapTest01");

    claptrap.attack("Moulinex");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.attack("Moulinex Beta");
    claptrap.takeDamage(12);
    claptrap.attack("Moulinex 2.0");
    return 0;
}
