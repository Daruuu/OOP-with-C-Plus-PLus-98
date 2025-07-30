#include "Zombie.hpp"

Zombie::Zombie(){ }

Zombie::~Zombie(){ }

void Zombie::announce()
{

}

Zombie Zombie::newZombie(std::string name)
{
	Zombie* newZombie = new Zombie();
	if (name.compare(NULL))
		this->name_ = "";
	this->name_ = name;
	return *newZombie;
}

void Zombie::randomChump(std::string name)
{
	if (name.compare(NULL))
		this->name_ = "";
	this->name_ = name;
}


