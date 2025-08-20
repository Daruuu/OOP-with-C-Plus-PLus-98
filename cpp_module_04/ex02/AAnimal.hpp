#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type_;

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif //AANIMAL_HPP