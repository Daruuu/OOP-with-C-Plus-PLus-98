#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
private:
	std::string	name_;

public:
	Zombie();
	~Zombie();
	//	methods
	void	announce();
	Zombie	newZombie(std::string name);
	void	randomChump(std::string name);

};

#endif //ZOMBIE_HPP
