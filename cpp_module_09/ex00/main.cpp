#include <unistd.h>
#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac == 2 && !btc::validateFilePermissions(av[1]) && !btc::validateFileExtension(av[1]))
	{
		std::cerr << "Error in validation file or extension file : " << av[0];
		return 1;
	}
	try
	{

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
