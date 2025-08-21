#include "ICharacter.hpp"

ICharacter::~ICharacter()
{
	std::cout << RED << "[ICharacter] destructor called." << RESET
	<< std::endl;
}
