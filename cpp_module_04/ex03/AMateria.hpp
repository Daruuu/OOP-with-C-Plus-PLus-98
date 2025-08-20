#ifndef AMATERIA_HPP
#define AMATERIA_HPP

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

/**
* ¿Qué es una forward declaration?
* En C++ significa declarar la existencia de una clase sin incluir toda su definición.
* Básicamente, le dices al compilador:
* “Oye, existe una clase llamada ICharacter, ya te enseñaré luego cómo es,
* pero por ahora solo necesito saber que existe”.
 */

// Forward declaration para no romper dependencias circulares
class ICharacter;

class AMateria
{
protected:
	std::string type_;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	virtual AMateria* clone() const = 0;	//pure functions (abstract class)
	virtual void use(ICharacter& target);	// default or override optional

	std::string const& getType() const; //Returns the materia type
};
#endif //AMATERIA_HPP