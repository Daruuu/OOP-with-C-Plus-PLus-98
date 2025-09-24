#include "Form.hpp"
#include "../../cpp_module_02/ex03/Fixed.hpp"

int main()
{
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

	{
		std::cout << GREEN << "\n--- Test 3: Invalid form (gradeToSign too high: 0) ---" << RESET << std::endl;
		try {
			Form f("Invalid Form High", 0, 50);
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << GREEN << "\n--- Test 3: Invalid form (gradeToExecute too low: 200) ---" << RESET << std::endl;
		try {
			Form f("Invalid Form Low", 50, 200);
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}


	{
		std::cout << GREEN << "\n--- Test 4: Bureaucrat with enough grade signs Form ---" << RESET << std::endl;
		try {
			Bureaucrat b("Signer", 40);

			Form formEnoughGrade("Contract", 50, 60);

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
			Form f("TopSecret", 50, 60);

			f.beSigned(b);
		}
		catch (const std::exception& e) {
			std::cout << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}




	return 0;
}
