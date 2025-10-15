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

void testSwapFunction()
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

int main( void )
{
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