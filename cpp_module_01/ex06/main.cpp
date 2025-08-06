#include <iostream>

#include "Harl.hpp"

static int getLevelIndex(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			return (i);
	}
	return (42);
}

int main(int ac, char** av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
		return (1);
	}

	int index = getLevelIndex(av[1]);

	switch (index)
	{
		case 0:
			harl.complain("DEBUG");
			break;
		case 1:
			harl.complain("INFO");
			break;
		case 2:
			harl.complain("WARNING");
			break;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cerr << RED << "[ Probably complaining about insignificant problems ]" << RESET
				<< std::endl;
	}
	return 0;
}
