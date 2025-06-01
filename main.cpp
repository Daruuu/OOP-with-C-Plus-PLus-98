#include <iostream>

// no es recomendable utlizar namespace cuando utilizas mas de una libreria.
// using namespace std;
int main()
{
	// const char *lang = "C++";
	// std::cout << "Hello and welcome to " << lang << "!\n";
	std::cout << "Hello and welcome to c++" << "!\n";

	for (int i = 1; i <= 5; i++)
	{
		std::cout << "i = " << i << std::endl;
	}

	std::cout << "Hello world :)" << std::endl;

	//	Create const Variables

	const double PI = 3.14;
	int	radius =  4;
	double	area = PI * radius * radius;

	std::cout << "Area of circle with radius:" << radius << " is " << area << std::endl;

	return 0;
	// TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}