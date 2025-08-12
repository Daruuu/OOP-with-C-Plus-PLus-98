#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

/*
int main()
{
	//	Case 01
	Point a(2.0f, 2.0f);
	std::cout << "Position of vertex A: " << a.getX() << ", " << a.getY() << std::endl;
	Point b(1.0f, 5.0f);
	std::cout << "Position of vertex B: " << b.getX() << ", " << b.getY() << std::endl;
	Point c(3.5f, 4.0f);
	std::cout << "Position of vertex C: " << c.getX() << ", " << c.getY() << std::endl;

	// Vertex to find in the coordinate plane
	Point insideTheTriangle(2.0f, 4.0f);

	std::cout << "This case is correct: " << std::endl;
	std::cout << bsp(a, b, c, insideTheTriangle) << std::endl;

	//	Case 02 that fails
	Point a1(-6.0f, 4.0f);
	Point b1(2.0f, -3.0f);
	Point c1(2.0f, 7.0f);


	Point outsideTheTriangle(2.0f, 2.0f);

	std::cout << "Point on edge: " << bsp(a1, b1, c1, outsideTheTriangle) <<
		std::endl;
		#1#

	return 0;
}
*/

int main()
{
	// Caso 01
	Point a(2.0f, 2.0f);
	Point b(1.0f, 5.0f);
	Point c(3.5f, 4.0f);

	std::cout << CYAN << "=== Triangle vertices ===" << RESET << std::endl;
	std::cout << GREEN << "Vertex A: " << RESET << a.getX() << ", " << a.getY() << std::endl;
	std::cout << GREEN << "Vertex B: " << RESET << b.getX() << ", " << b.getY() << std::endl;
	std::cout << GREEN << "Vertex C: " << RESET << c.getX() << ", " << c.getY() << std::endl;

	// Punto a evaluar
	Point insideTheTriangle(2.0f, 4.0f);
	std::cout << YELLOW << "\nPoint to test: " << RESET
			  << insideTheTriangle.getX() << ", "
			  << insideTheTriangle.getY() << std::endl;

	std::cout << CYAN << "\n=== Checking if point is inside triangle ===" << RESET << std::endl;
	bool result = bsp(a, b, c, insideTheTriangle);

	if (result)
		std::cout << GREEN << "✅ The point is inside the triangle" << RESET << std::endl;
	else
		std::cout << RED << "❌ The point is outside the triangle" << RESET << std::endl;

	return 0;
}
