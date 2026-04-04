#include <unistd.h>
#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	if (!btc::validateFilePermissions(av[1]) || !btc::validateFileExtension(av[1]))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		// Cargar la base de datos (esto asume que llamas a loadDatabase() dentro de tu constructor)
		BitcoinExchange btc;
		
		// Procesar el fichero de entrada pasado por argumento
		btc.processInputFile(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
