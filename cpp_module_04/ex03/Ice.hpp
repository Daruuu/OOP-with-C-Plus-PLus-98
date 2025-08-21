#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	AMateria* clone() const; //	override from AMateria
	void use(ICharacter& target); //	override from AMateria
};

#endif //ICE_HPP
