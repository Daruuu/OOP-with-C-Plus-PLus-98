#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>

#include "AForm.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#define SHRUBBERRY		"shrubbery creation"
#define ROBOTO			"robotomy request",
#define PRESIDENTIAL	"presidential pardon"

class Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& obj);
	~Intern();

	//	form creation method
	AForm* makeForm(const std::string nameForm, const std::string targetForm);
};

#endif
