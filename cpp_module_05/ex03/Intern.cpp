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

const char* Intern::NoExistsFormException::what() const throw()
{
	return ("Type of form doesn't exist !");
}


//	STATIC PRIVATES METHODS

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& nameForm,
						const std::string& targetForm)
{
	std::string formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*createForms[3])(const std::string&) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm,
	};

	for (int i = 0; i < 3; ++i)
	{
		if (nameForm == formTypes[i])
		{
			std::cout << "Intern creates " << CYAN << nameForm << RESET << " to target " <<
				targetForm << std::endl;
			return createForms[i](targetForm);
		}
	}
	throw NoExistsFormException();
}
