#include <cstdlib>
#include <ctime>
#include <iostream>
#include  "whatever.hpp"

void testMaxFunction()
{
	std::cout << GREEN << "\n********** TEST OF MAX FUNCTION TEMPLATE ********** \n" << RESETT << std::endl;
	int caseIntegerA = 200;
	int caseIntegerB = 300;

	double caseDoubleA = 220.25;
	double caseDoubleB = 265.800;

	float caseFloatA = 234324234.0f;
	float caseFloatB = 23.234f;

	std::cout << CYAN << "CASE INTEGER: max(a, b): " << ::max(caseIntegerA, caseIntegerB) << std::endl;

	std::cout << "CASE DOUBLE: max(a, b): " << ::max(caseDoubleA, caseDoubleB) << std::endl;

	std::cout << "CASE FLOAT: max(a, b): " << ::max(caseFloatA, caseFloatB) << RESETT << std::endl;
}

void testMinFunction()
{
	std::cout << GREEN << "\n********** TEST OF MIN FUNCTION TEMPLATE ********** \n" << RESETT << std::endl;
	int caseIntegerA = 200;
	int caseIntegerB = 300;

	double caseDoubleA = 220.25;
	double caseDoubleB = 265.800;

	float caseFloatA = 234324234.0f;
	float caseFloatB = 23.234f;

	std::cout << BLUE << "CASE INTEGER: max(a, b): " << ::min(caseIntegerA, caseIntegerB) << std::endl;

	std::cout << "CASE DOUBLE: max(a, b): " << ::min(caseDoubleA, caseDoubleB) << std::endl;

	std::cout << "CASE FLOAT: max(a, b): " << ::min(caseFloatA, caseFloatB) << RESETT << std::endl;
}

static void testSwapForInt(int a, int b, const std::string& typeName)
{
	int originalA = a;
	int originalB = b;

	std::cout << BLUE << "CASE " << typeName << " BEFORE (a=" << a << ", b=" << b << ")" << std::endl;
	::swap(a, b);
	std::cout << "CASE " << typeName << " AFTER (a=" << a << ", b=" << b << ")" << RESETT << std::endl;

	if (a == originalB && b == originalA)
		std::cout << "swap OK" << std::endl;
	else
		std::cout << "swap KO" << std::endl;
}

static void testSwapForDouble(double a, double b, const std::string& typeName)
{
	double originalA = a;
	double originalB = b;

	std::cout << BLUE << "CASE " << typeName << " BEFORE (a=" << a << ", b=" << b << ")" << std::endl;
	::swap(a, b);
	std::cout << "CASE " << typeName << " AFTER (a=" << a << ", b=" << b << ")" << RESETT << std::endl;

	if (a == originalB && b == originalA)
		std::cout << "swap OK" << std::endl;
	else
		std::cout << "swap KO" << std::endl;
}

static void testSwapForFloat(float a, float b, const std::string& typeName)
{
	float originalA = a;
	float originalB = b;

	std::cout << BLUE << "CASE " << typeName << " BEFORE (a=" << a << ", b=" << b << ")" << std::endl;
	::swap(a, b);
	std::cout << "CASE " << typeName << " AFTER (a=" << a << ", b=" << b << ")" << RESETT << std::endl;

	if (a == originalB && b == originalA)
		std::cout << "swap OK" << std::endl;
	else
		std::cout << "swap KO" << std::endl;
}

void testSwapFunction()
{
	std::cout << GREEN << "\n********** TEST OF SWAP FUNCTION TEMPLATE ********** \n" << RESETT << std::endl;
	int intA = rand() % 1001;
	int intB = rand() % 1001;

	double doubleA = static_cast<double>(rand());
	double doubleB = static_cast<double>(rand());

	float floatA = static_cast<float>(rand()) / 1000.0f;;
	float floatB = static_cast<float>(rand()) / 1000.0f;;

	testSwapForInt(intA, intB, "INTEGER");
	testSwapForDouble(doubleA, doubleB, "DOUBLE");
	testSwapForFloat(floatA, floatB, "FLOAT");
}

int main( void )
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	testMinFunction();
	testMaxFunction();
	testSwapFunction();

	return (0);
}

/*
int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
*/