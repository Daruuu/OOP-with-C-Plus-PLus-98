#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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

			ShrubberyCreationForm shrub("garden");

			std::cout << shrub << std::endl;

			std::cout << "--- Testing with low grade bureaucrat: ---" << std::endl;
			lowGrade.signForm(shrub);
			lowGrade.executeForm(shrub);

			std::cout << "--- Testing with mid grade bureaucrat: ---" << std::endl;
			midGrade.signForm(shrub);
			midGrade.executeForm(shrub);
		}
		catch (std::exception &e)
		{
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
/*
{
	std::cout << GREEN << "--- Test 1: Valid Burocrata ---" << RESET << std::endl;
	try
	{
		Bureaucrat b1("BuroLow", 100);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\n--- Test 2: Valid form ---" << RESET << std::endl;
	try {
		Form formValid("Tax Form", 50, 60);
		std::cout << formValid << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
	}
}
*/
