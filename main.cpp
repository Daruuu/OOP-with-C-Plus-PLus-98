#include <iostream>

// no es recomendable utlizar namespace cuando utilizas mas de una libreria.
// using namespace std;

int main()
{
	int	i = 0;

	int	*ptr_i = &i;
	int	&ref_i = i;

	std::cout << "int i = " << i << std::endl;

	std::cout << "ptr_i = " << ptr_i << std::endl;

	std::cout << "ref_i = " << ref_i << std::endl;

	std::cout << "ref_i = " << &ref_i << std::endl;

	return 0;
}

/*
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
	std::cout << "------- CREATE CONST VARIABLES -------" << std::endl;

	const double PI = 3.14;
	int	radius =  4;
	double	area = PI * radius * radius;

	std::cout << "Area of circle with radius:" << radius << " is " << area << std::endl;

	std::cout << "------- GET INPUT FROM KEYBOARD an Character and Integer -------" << std::endl;

	char	c_a;
	int		num;
	std::cout << "Enter a character and an integer: ";
	std::cin >> c_a >> num;
	std::cout << "Character: " << c_a << std::endl;
	std::cout << "Number: " << num << std::endl;

	std::cout << "------- ARITHMETIC OPERATIONS -------" << std::endl;

	int	a, b;

	a = 10;
	b = 20;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl;
	std::cout << "a % b: " << (a % b) << std::endl;

	std::cout << "------- PRE INCREMENT AND POST INCREMENT -------" << std::endl;

	int x = 10;
	int y = ++x;  // x = 11, y = 11
	int z = x++;  // x = 12, z = 11

	std::cout << "int x: 10" << std::endl;
	std::cout << "++y: " << y << std::endl;
	std::cout << "++z: " << z << std::endl;


	return 0;
	// TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
*/