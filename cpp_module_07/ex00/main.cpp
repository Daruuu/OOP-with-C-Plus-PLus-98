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

struct Item
{
	int value;
	const char* name;

	// comparamamos por 'value'
	bool operator<(const Item& other) const
	{
		return (value < other.value);
	}
};


//	INVALID IMPLEMENTATION
template <typename T>
T max_normal(const T &a, const T &b)
{
	return (a < b) ? b : a;
}

//	VALID IMPLEMENTATION
template <typename T>
T max_stepanov(T a, T b)
{
	return b < a ? a : b;
}

void test_case_returnOfTwoObjects()
{
	Item a = {10, "A"};
	Item b = {10, "B"};  // mismo valor, distinto objeto

	Item r1 = max_normal(a, b);
	Item r2 = max_stepanov(a, b);

	std::cout << "max_normal:  " << r1.name << std::endl;
	std::cout << "max_stepanov: " << r2.name << std::endl;

}
template <typename  T1, typename T2, typename RT>
RT max(T1 a, T2 b)
{
	return b < a ? RT(a) : RT(b);
}

int main( void )
{
	// ::max<int, double, double> (4, 7,2);
	// ::max<double, int, double>(4, 7,2);

	std::cout << "case <int, double, double> := [" << ::max<int, double, double> (4, 7.2) << "]" << std::endl;
	std::cout << "case <double, int, double> := [" << ::max<double, int, double>(4, 7.2)<< "]" << std::endl;

	// test_case_returnOfTwoObjects();
	/*
	const char* a = "hello";
	const char* b = a;  // mismo puntero

	const char* originalMax = std::max(a, b);  // C++98
	const char* customizeMax = ::max(a, b);  // C++98

	std::cout << "my original  return = [" << originalMax << "]" << std::endl;
	std::cout << "my customize return = [" << customizeMax << "]" << std::endl;
	*/

	// std::srand(static_cast<unsigned int>(std::time(NULL)));
	// testMinFunction();
	// testMaxFunction();
	// testSwapFunction();

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