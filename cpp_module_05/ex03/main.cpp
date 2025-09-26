#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << GREEN << "\n=== ex03: Intern & Forms Test ===\n" << RESET << std::endl;

    Intern intern;

    Bureaucrat boss("Boss", 1);
    Bureaucrat employee("Employee", 140);

	std::cout << BLUE << "\n[1] Create ShrubberyCreationForm\n" << RESET;
    try {
        AForm* shrub = intern.makeForm("shrubbery creation", "Home");
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }
    catch (std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

	std::cout << BLUE << "\n[2] Create RobotomyRequestForm\n" << RESET;
    try {
        AForm* robo = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*robo);
        boss.executeForm(*robo);
        delete robo;
    }
    catch (std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

	std::cout << BLUE << "\n[3] Create PresidentialPardonForm with low bureaucrat\n" << RESET;
    try {
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        employee.signForm(*pardon);
        employee.executeForm(*pardon);
        delete pardon;
    }
    catch (std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

	std::cout << BLUE << "\n[4] Try invalid form type\n" << RESET;
    try {
        AForm* wrong = intern.makeForm("coffee request", "Office");
        boss.signForm(*wrong);
        boss.executeForm(*wrong);
        delete wrong;
    }
    catch (Intern::NoExistsFormException& e) {
        std::cerr << MAGENTA << "Intern exception: " << e.what() << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << RED << "Other exception: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n=== End of Tests ===\n" << RESET << std::endl;
    return 0;
}

/*
int main()
{
	try
	{
		std::cout << "=== CPP05 EX03: Intern & Forms ===" << std::endl;

		Intern intern;

		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Mid", 50);
		Bureaucrat newEmployee("Newbie", 140);

		std::string formNames[4] = {
			"shrubbery creation",
			"unknown form", //error case
			"robotomy request",
			"presidential pardon",
		};

		for (int i = 0; i < 4; i++)
		{
			std::cout << GREEN << "\n===== Requesting form: " << formNames[i] <<
				" =====\n" << RESET <<
				std::endl;

			AForm* form = intern.makeForm(formNames[i], "TargetX");
			if (!form)
			{
				continue;
			}

			std::cout << *form << std::endl;

			newEmployee.signForm(*form);
			newEmployee.executeForm(*form);

			mid.signForm(*form);
			mid.executeForm(*form);

			boss.signForm(*form);
			boss.executeForm(*form);

			delete form; // Free memory (avoid leaks)
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
	return 0;
}
*/

/*
int main()
{
	std::cout << GREEN << "--- Test 1: Create valid form ---" << RESET <<
		std::endl;

	Intern intern01;

	AForm* form = intern01.makeForm("robotomy request", "Bender");
	if (form)
	{
		Bureaucrat boss("Boss", 1);

		// Boss sign and execute
		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}

	// === Caso 2: Crear un formulario inválido ===
	AForm* invalidCase = intern01.makeForm("unknown form", "TargetX");
	if (invalidCase)
	{
		delete invalidCase;
	}
	return 0;
}
*/
