#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name_ = name;
}

Zombie::~Zombie(){ }

//	add brainzzz out
void Zombie::announce() { }

//	usamos el HEAP
//	al usar new Object()
//	use Delete() para hacer un free
Zombie *Zombie::newZombie(std::string name)
{

	if (name.compare(NULL))
		this->name_ = "";

	Zombie* newZombie = new Zombie();
	this->name_ = name;
	return newZombie;
}

//	se instancia en STACK

void	randomChump(std::string name)
{
	// if (name.compare(NULL))
		// this->name_ = "";
	// this->name_ = name;
	Zombie	newZombieInStack(name);
	newZombieInStack.announce();

}


