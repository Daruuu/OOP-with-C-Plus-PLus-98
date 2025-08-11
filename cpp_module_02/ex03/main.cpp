#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

int main()
{
	//	Case 01
	Point a(2.0f, 2.0f);
	Point b(1.0f, 5.0f);
	Point c(3.5f, 4.0f);

	// Puntos para probar
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

	return 0;
}
