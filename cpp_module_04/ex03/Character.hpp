#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

/*
* Debe almacenar un nombre (std::string name_).
* Inventario de 4 slots (AMateria* inventory_[4]).
* Destructor: borra las materias que quedan en inventario.
* Copia profunda: cuando copies un Character, debes clonar cada AMateria del inventario.
*/

class Character : public ICharacter
{
private:
	std::string name_;
	AMateria* inventory_[4];

public:
	Character();
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	//ovverride from ICharacter ?
};

#endif //CHARACTER_HPP
