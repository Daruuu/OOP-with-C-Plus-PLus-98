#ifndef STARTING_WITH_CPP_DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
public:

	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void makeSound() const;
};

#endif //STARTING_WITH_CPP_DOG_HPP