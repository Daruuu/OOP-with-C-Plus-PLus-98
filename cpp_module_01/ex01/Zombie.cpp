#include "Zombie.hpp"

#define RESET       "\033[0m"
#define MAGENTA     "\033[35m"
#define GREEN       "\033[32m"
#define RED         "\033[31m"
#define CYAN        "\033[36m"
#define YELLOW      "\033[33m"

Zombie::Zombie()
{
	this->name_ = "";
	std::cout << MAGENTA << "[Zombie]" << GREEN << "[Constructor] "
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << MAGENTA << "[Zombie]" << RED << "[Destructor] "
	<< std::endl;
}

std::string	Zombie::getName()
{
	return (this->name_);
}

void	Zombie::setName(std::string name)
{
	this->name_ = name;
}

void Zombie::announce()
{
	std::cout << MAGENTA << "[Zombie]" << CYAN << "[Announce] "
			  << YELLOW << this->name_ << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
