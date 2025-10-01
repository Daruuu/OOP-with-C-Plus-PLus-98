#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: invalid num of args. :(" << RESET << std::endl;
		return (1);
	}

	return (0);
}

