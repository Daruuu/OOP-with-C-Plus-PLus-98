#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	void learnMateria(AMateria*);
	// createMateria(std::string const &);

};

/*
learnMateria(AMateria*)
Copies the Materia passed as a parameter and stores it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique.
• createMateria(std::string const &)
Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
 */

#endif //MATERIASOURCE_HPP