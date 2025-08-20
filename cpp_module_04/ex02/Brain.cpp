#include "Brain.hpp"

Brain::Brain()
{
	std::cout << MAGENTA << "Brain created." << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << MAGENTA<<  "Brain copy constructor called." << RESET << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas_[i] = other.ideas_[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			ideas_[i] = other.ideas_[i];
		}
	}
	std::cout << MAGENTA << "Brain copy assignment operator called" << RESET << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called." << RESET
	<< std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	this->ideas_[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return ideas_[index];
}
