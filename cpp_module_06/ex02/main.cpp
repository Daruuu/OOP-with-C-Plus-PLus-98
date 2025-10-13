#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void randomCases(int maxTestCases)
{
	std::cout << GREEN << "===== RANDOM TESTS =====" << RESETT << std::endl;

	for (int i = 1; i <= maxTestCases; ++i)
	{
		Base* obj = generate();
		Base& ref = *obj;
		std::cout << BLUE << "=== Test " << i << " ===" << RESETT << std::endl;

		std::cout << "Address of pointer (obj):"<< &obj << std::endl;
		std::cout << "Address stored in pointer (pointer to object):"<< obj << std::endl;
		std::cout << "Address of referenced object (ref):"<< &ref << std::endl;

		std::cout << "Pointer version: ";
		identify(obj);

		std::cout << "Reference version: ";
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}
}

void manualTestWithThreeBaseObjects()
{
	std::cout << GREEN << "\n===== MANUAL TESTS =====" << RESETT << std::endl;

	A a;
	B b;
	C c;

	Base* baseA = &a;
	Base* baseB = &b;
	Base* baseC = &c;

	// --- Test A ---
	std::cout << YELLOW << "\n[TEST A]" << RESETT << std::endl;

	std::cout << "Pointer version: ";
	identify(baseA);

	std::cout << "Reference version: ";
	identify(a);

	// --- Test B ---
	std::cout << YELLOW << "\n[TEST B]" << RESETT << std::endl;

	std::cout << "Pointer version: ";
	identify(baseB);

	std::cout << "Reference version: ";
	identify(b);

	// --- Test C ---
	std::cout << YELLOW << "\n[TEST C]" << RESETT << std::endl;

	std::cout << "Pointer version: ";
	identify(baseC);

	std::cout << "Reference version: ";
	identify(c);

	std::cout << "\n" << CYAN << "Addresses for verification:" << RESETT << std::endl;
	std::cout << "A at " << &a << std::endl;
	std::cout << "B at " << &b << std::endl;
	std::cout << "C at " << &c << std::endl;

	std::cout << std::endl;
}

void edgeCase()
{
	std::cout << GREEN << "===== EDGE CASES =====" << RESETT << std::endl;

	std::cout << "Null pointer test: ";

	Base* nullPtr = NULL;
	identify(nullPtr);
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	randomCases(4);
	// manualTestWithThreeBaseObjects();
	// edgeCase();
	return 0;
}
