#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	AMateria* clone() const; // overrride from AMateria
	void use(ICharacter& target); // overrride from AMateria
};

#endif //CURE_HPP
