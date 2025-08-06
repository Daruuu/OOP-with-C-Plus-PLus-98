#include "Replace.hpp"

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "Usage: " << RESET << argv[0] << " <filename> <s1> <s2>\n";
		return 1;
	}

	std::cout << GREEN << "[INFO] Starting replace process...\n" << RESET;


	Replace replace(argv[1], argv[2], argv[3]);
	replace.replaceInFile();

	std::cout << GREEN << "[INFO] Finished! Output file: " << argv[1] << ".replace\n" << RESET;

	return 0;
}
