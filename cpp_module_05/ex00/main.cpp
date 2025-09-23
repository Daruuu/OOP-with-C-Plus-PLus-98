#include "Bureaucrat.hpp"
#include "../../cpp_module_02/ex03/Fixed.hpp"

int main()
{
	{
		try
		{
			std::cout << GREEN <<
				"--- Test 1: Create with grade 150 and decrement ---"
				<< RESET << std::endl;

			Bureaucrat b1("BuroLow", 150);
			std::cout << CYAN << b1 << RESET << std::endl;
			b1.decrementGrade();
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET <<
				std::endl;
		}
	}

	{
		// Case 2: Invalid bureaucrat (too low grade: 151)
		try
		{
			std::cout << GREEN << "\n--- Test 2: Create with grade 151 ---"
				<< RESET << std::endl;

			Bureaucrat b2("BuroInvalid", 151);
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET <<
				std::endl;
		}
	}

	{
		// Case 3: Invalid bureaucrat (too high grade: 0)
		try
		{
			std::cout << GREEN << "\n--- Test 3: Create with grade 0 ---"
				<< RESET << std::endl;

			Bureaucrat b3("BuroInvalidHigh", 0);
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET <<
				std::endl;
		}
	}

	{
		try
		{
			std::cout << GREEN <<
				"\n--- Test 4: Create with grade 1 and increment ---"
				<< RESET << std::endl;

			Bureaucrat b4("BuroTop", 1);
			std::cout << CYAN << b4 << RESET << std::endl;
			b4.incrementGrade();
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET <<
				std::endl;
		}
	}

	{
		try
		{
			std::cout << GREEN <<
				"\n--- Test 5: Create with grade 75 and play with increment/decrement ---"
				<< RESET << std::endl;

			Bureaucrat b5("BuroMid", 75);
			std::cout << CYAN << b5 << RESET << std::endl;

			b5.incrementGrade();
			std::cout << CYAN << b5 << RESET << std::endl;
			b5.incrementGrade();
			std::cout << CYAN << b5 << RESET << std::endl;
			b5.incrementGrade();

			std::cout << YELLOW << "After increment: " << b5 << RESET <<
				std::endl;

			b5.decrementGrade();
			std::cout << YELLOW << "After decrement: " << b5 << RESET <<
				std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Exception caught: " << e.what() << RESET <<
				std::endl;
		}
	}

	// Case 6: Copy constructor and assignment operator
	std::cout << GREEN << "\n--- Test 6: Copy constructor and assignment ---"
		<< RESET << std::endl;

	Bureaucrat original("Original", 42);
	Bureaucrat copy(original); // copy constructor
	Bureaucrat assigned;
	assigned = original; // assignment operator

	std::cout << MAGENTA << "Original: " << original << RESET << std::endl;
	std::cout << MAGENTA << "Copy:     " << copy << RESET << std::endl;
	std::cout << MAGENTA << "Assigned: " << assigned << RESET << std::endl;

	return 0;
}
