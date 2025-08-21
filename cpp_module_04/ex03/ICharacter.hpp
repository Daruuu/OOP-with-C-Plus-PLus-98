#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

/*
 * Inventario de 4 slots (AMateria* inventory[4]).
 * equip() → añade la Materia en el primer slot vacío.
 * unequip() → no borra la Materia, solo la desapega.
 * use(idx, target) → llama a inventory[idx]->use(target).

Regla importante: copia profunda en constructor de copia y operador de asignación.
 */

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {};

	virtual std::string const& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif //ICHARACTER_HPP
