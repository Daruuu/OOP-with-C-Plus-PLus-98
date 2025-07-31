#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name_ = name;
	std::cout << "Zombie Constructor:" << this->name_ << std::endl;
}

Zombie::~Zombie()
{

	std::cout << "Zombie Destructor:" << this->name_ << std::endl;
}

//	add brainzzz out
void	Zombie::announce()
{
	std::cout << this->name_ << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
