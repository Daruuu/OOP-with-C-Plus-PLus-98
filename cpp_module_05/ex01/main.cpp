#include "AForm.hpp"

int main()
{
	{
		std::cout << GREEN << "\n--- Test 3: Invalid form (gradeToSign too high: 0) ---" << RESET << std::endl;
		try {
			AForm f("Invalid AForm High", 0, 50);
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << GREEN << "\n--- Test 3: Invalid form (gradeToExecute too low: 200) ---" << RESET << std::endl;
		try {
			AForm f("Invalid AForm Low", 50, 200);
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << GREEN << "\n--- Test 4: Bureaucrat with enough grade signs AForm ---" << RESET << std::endl;
		try {
			Bureaucrat b("Signer", 40);

			AForm formEnoughGrade("Contract", 50, 60);

			std::cout << formEnoughGrade << RESET << std::endl;

			formEnoughGrade.beSigned(b);

			std::cout << "After signing:\n" << formEnoughGrade << RESET << std::endl;

		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << GREEN << "\n--- Test 5: Bureaucrat with low grade ---" << RESET << std::endl;
		try {
			Bureaucrat b("Intern", 120);
			AForm f("TopSecret", 50, 60);

			f.beSigned(b);
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
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
			AForm formValid("Tax AForm", 50, 60);
			std::cout << formValid << RESET << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}
	*/
	return 0;
}
