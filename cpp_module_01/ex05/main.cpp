#include <iostream>

#include "Harl.hpp"

// int main(int argc, char** argv)
int main(void)
{
	std::cout <<  "this is a main" << std::endl;
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}
