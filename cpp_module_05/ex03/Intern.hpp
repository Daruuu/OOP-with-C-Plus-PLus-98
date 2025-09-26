#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#define SHRUBBERRY		"shrubbery creation"
#define ROBOTO			"robotomy request"
#define PRESIDENTIAL	"presidential pardon"

class Intern
{
private:
	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);

public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& obj);
	~Intern();

	//	form creation method
	AForm* makeForm(const std::string& nameForm, const std::string& targetForm);

	class NoExistsFormException : public std::exception
	{
	public:
		const char* what() const throw();
	};

};

#endif
