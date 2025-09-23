#include "Bureaucrat.hpp"
#include "../../cpp_module_02/ex03/Fixed.hpp"

int	main()
{
    // Caso 1: Burócrata válido y decremento
    try {
        std::cout << GREEN << "--- Test 1: Crear en 150 y decrementar ---" << RESET << std::endl;

        Bureaucrat b1("BuroLow", 150);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << "Exception atrapada: " << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "\n--- Test 2: Crear en 151 ---\n" << RESET << std::endl;
        Bureaucrat b2("BuroInvalid", 151);
    }
    catch (const std::exception& e) {
        std::cout << "Exception atrapada: " << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "\n--- Test 3: Crear en 0 ---\n" << RESET << std::endl;
        Bureaucrat b3("BuroInvalidHigh", 0);
    }
    catch (const std::exception& e) {
        std::cout << "Exception atrapada: " << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "\n--- Test 4: Crear en 1 y hacer incrementGrade() ---\n" << RESET << std::endl;
        Bureaucrat b4("BuroTop", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << "Exception atrapada: " << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "\n--- Test 5: Crear en 75 y jugar con increment/decrement ---\n" << RESET << std::endl;
        Bureaucrat b5("BuroMid", 75);
        std::cout << b5 << std::endl;
        b5.incrementGrade();
        std::cout << "Después de increment: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "Después de decrement: " << b5 << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception atrapada: " << e.what() << std::endl;
    }

    // Caso 6: Copia y asignación
    std::cout << GREEN << "\n--- Test 6: Copy constructor y assignment ---\n" << RESET << std::endl;
    Bureaucrat original("Original", 42);
    Bureaucrat copia(original);
    Bureaucrat asignado;
    asignado = original;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copia:    " << copia << std::endl;
    std::cout << "Asignado: " << asignado << std::endl;

    return 0;
}
