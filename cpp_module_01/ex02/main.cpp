# include <iostream>

int	main(void)
{
	std::string greeting = "HI THIS IS BRAIN";

	std::string &stringPTR = greeting;

	std::string &stringREF = greeting;

	std::cout << "Address of greeting: ["<< &greeting << "]" << std::endl;

	std::cout << "Value of greeting: "<< greeting << std::endl;

	std::cout << "-------------------------------"<< std::endl;

	std::cout << "Address of stringPTR: "<< stringPTR << std::endl;
	std::cout << "Value of stringPTR: "<< &stringPTR << std::endl;

	std::cout << "-------------------------------"<< std::endl;

	std::cout << "Value of stringREF : "<< &stringREF << std::endl;

	return (0);
}

/*
#include <iostream>
using namespace std;

int main()
{
    // declare variables
    int var1 = 3;
    int var2 = 24;
    int var3 = 17;

    // print address of var1
    cout << "Address of var1: "<< &var1 << endl;

    // print address of var2
    cout << "Address of var2: " << &var2 << endl;

    // print address of var3
    cout << "Address of var3: " << &var3 << endl;
}
*/
