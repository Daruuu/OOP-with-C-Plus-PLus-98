#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	{
		std::cout << GREEN << "--- Test 1: ShrubberyCreationForm ---" << RESET << std::endl;
		try
		{
			Bureaucrat highGrade("HighGrade", 1);
			Bureaucrat midGrade("MidGrade", 50);
			Bureaucrat lowGrade("LowGrade", 150);

			// ShrubberyCreationForm shrub("garden");
			ShrubberyCreationForm shrub("shrubbery");

			std::cout << shrub << std::endl;

			std::cout << GREEN << "--- Case with low grade bureaucrat: ---" << RESET << std::endl;
			lowGrade.signForm(shrub);
			lowGrade.executeForm(shrub);

			std::cout << GREEN << "--- Case with mid grade bureaucrat: ---" << RESET << std::endl;
			midGrade.signForm(shrub);
			midGrade.executeForm(shrub);
		}
		catch (std::exception &e)
		{
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << GREEN << "--- Test 2: RobotomyRequestForm ---" << RESET << std::endl;
		try
		{
			Bureaucrat highGrade("buro01", 1);
			Bureaucrat midGrade("burocrat 02", 50);
			Bureaucrat lowGrade("burocrata 03", 150);

			RobotomyRequestForm robo("TargetRobot");

			std::cout << robo << std::endl;

			std::cout << GREEN << "\n--- Case 1: Execute without signing ---" << RESET << std::endl;
			highGrade.executeForm(robo);

			std::cout << GREEN << "\n--- Case 2: Signed but low grade bureaucrat ---" << RESET << std::endl;
			lowGrade.signForm(robo);
			lowGrade.executeForm(robo);

			std::cout << GREEN << "\n--- Case 3: Signed and executed by high grade ---" << RESET << std::endl;
			highGrade.signForm(robo);
			highGrade.executeForm(robo);

			std::cout << GREEN << "\n--- Case 4: Signed and executed by BUROCRAT 02 ---" << RESET << std::endl;
			midGrade.signForm(robo);
			midGrade.executeForm(robo);
		}
		catch (std::exception &e)
		{
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << GREEN << "\n--- Test: PresidentialPardonForm ---" << RESET << std::endl;
		try
		{
			Bureaucrat top("TopDog", 1);
			Bureaucrat signer("Signer", 25);
			Bureaucrat low("LowGuy", 150);

			PresidentialPardonForm pardon("Abcd");

			std::cout << pardon << std::endl;

			std::cout << GREEN << "\n--- Case 1: Execute without signing ---" << RESET << std::endl;
			top.executeForm(pardon);

			std::cout << GREEN << "\n--- Case 2: Sign with low grade ---" << RESET << std::endl;
			low.signForm(pardon);

			std::cout << GREEN << "\n--- Case 3: Signed but executed by low grade ---" << RESET << std::endl;
			signer.signForm(pardon);
			low.executeForm(pardon);

			std::cout << GREEN << "\n--- Case 4: Signed and executed by top grade ---" << RESET << std::endl;
			top.signForm(pardon);
			top.executeForm(pardon);
		}
		catch (std::exception& e)
		{
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
