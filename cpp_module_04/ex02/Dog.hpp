#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Dog : public AAnimal
{
private:
	Brain* brain_;

public:

	Dog();	//	init here Brain pointer
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void makeSound() const;
};

#endif //DOG_HPP