#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Creating default DiamondTrap ===" << std::endl;
	DiamondTrap dt1;
	dt1.whoAmI();
	dt1.attack("Enemy1");

	std::cout << "\n=== Creating DiamondTrap with name 'Hero' ===" << std::endl;
	DiamondTrap dt2("Hero");
	dt2.whoAmI();
	dt2.attack("Enemy2");

	std::cout << "\n=== Copying DiamondTrap dt2 to dt3 ===" << std::endl;
	DiamondTrap dt3(dt2);
	dt3.whoAmI();
	dt3.attack("Enemy3");

	std::cout << "\n=== Assigning dt1 = dt2 ===" << std::endl;
	dt1 = dt2;
	dt1.whoAmI();
	dt1.attack("Enemy4");

	std::cout << "\n=== Exiting main, destructors will be called ===" << std::endl;
	return 0;
}
