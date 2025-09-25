#include "Intern.hpp"

Intern::Intern()
{
	std::cout << BLUE << "{INTERN} default constructor called." << RESET
		<< std::endl;
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "{INTERN} default destructor called." << RESET
		<< std::endl;
}


AForm* Intern::makeForm(const std::string nameForm,
						const std::string targetForm)
{
	std::string formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (createForms[3])(const std::string&) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm,
	};

	for (int i = 0; i < 3; ++i)
	{
		if (nameForm == formTypes)
		{
			std::cout << "Intern creates " << nameForm << " to target " <<
				targetForm << std::endl;
			return createForms[i](targetForm);
		}
	}
	std::cout << "Error: Form type not found :(" << std::endl;
	return NULL;
}
