#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#include <cstddef>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		// jim.setWeapon(club);
		jim.attack();
		// jim.setWeapon(nullptr);
		// Weapon test();
		// test->setType = "abc";
		// jim.setWeapon();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
