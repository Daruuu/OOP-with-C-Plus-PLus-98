#include <cstring>
#include <ctime>
#include <iostream>
#include <stdlib.h>

#include "iter.hpp"

//	add casting because we can test with douible or float
template <typename T>
void incrementElement(T& v)
{
	v += static_cast<T>(1);
}

template <typename T>
void printElement(const T& v) {
	std::cout << v << "\n";
}

void Iter_IncrementsEachIntegerElement()
{
	std::cout << GREEN << "############ Case ARRAY with Integers ############"
		<< RESETT << std::endl;

	const int lengthArray = (rand() % 10) + 3;
	int* arrayIntegers = NULL;

	try
	{
		arrayIntegers = new int[lengthArray];
		std::cout << YELLOW << "LENGHT OF INTEGER ARRAY is: " << lengthArray << RESETT
			<< std::endl;
	}
	catch (...)
	{
		std::cout << "Allocation faild" << std::endl;
	}

	for (int i = 0; i < lengthArray; ++i)
	{
		arrayIntegers[i] = (std::rand() % 20);
		std::cout << "array[" << i << "] = " << arrayIntegers[i] << std::endl;
	}

	::iter(arrayIntegers, lengthArray, incrementElement<int>);

	std::cout << YELLOW << "Array after call ITER: " << RESETT << std::endl;
	for (int i = 0; i < lengthArray; ++i)
	{
		std::cout << "array[" << i << "] = " << arrayIntegers[i] << std::endl;
	}

	delete[] arrayIntegers;
	arrayIntegers = NULL;
}

void Iter_IncrementsEachDoubleElement()
{
	std::cout << GREEN << "\n ############ Case ARRAY with Double ############"
		<< RESETT << std::endl;

	const int lengthArray = (std::rand() % 5) + 3;
	double* arrayDouble = NULL;

	try
	{
		arrayDouble = new double[lengthArray];
		std::cout << BLUE << "LENGHT OF DOUBLE ARRAY is: " << lengthArray << RESETT
			<< std::endl;
	}
	catch (...)
	{
		std::cout << "Allocation faild" << std::endl;
	}

	for (int i = 0; i < lengthArray; ++i)
	{
		arrayDouble[i] = (std::rand() / ( RAND_MAX / 30.0));
		std::cout << "array double [" << i << "] = " << arrayDouble[i] << std::endl;
	}

	std::cout << "BEFORE:\n" << std::endl;
	::iter(arrayDouble, lengthArray, incrementElement<double>);

	std::cout << BLUE << "Array after call ITER: " << RESETT << std::endl;
	for (int i = 0; i < lengthArray; ++i)
	{
		std::cout << "array[" << i << "] = " << arrayDouble[i] << std::endl;
	}

	delete[] arrayDouble;
	arrayDouble = NULL;
}

void Iter_IncrementsEachFloatElement()
{
	std::cout << GREEN << "\n############ Case ARRAY with Floats ############" << RESETT << std::endl;

	const size_t lengthFloat = (std::rand() % 5) + 3;
	float* arrayFloat  = NULL;
	try
	{
		arrayFloat = new float[lengthFloat];
	}
	catch (...)
	{
		std::cout << "Allocation faild" << std::endl;
	}

	for (size_t i = 0; i < lengthFloat; ++i) {
		arrayFloat[i] = (std::rand() / (RAND_MAX / 10.0f));
	}
	std::cout << CYAN << "Before: \n";
	::iter(arrayFloat, lengthFloat, printElement<float>);
	std::cout << RESETT << std::endl;

	::iter(arrayFloat, lengthFloat, incrementElement<float>);

	std::cout << YELLOW << "After increment: \n";
	::iter(arrayFloat, lengthFloat, printElement<float>);
	std::cout << RESETT << std::endl;
	delete[] arrayFloat;
}

void Iter_HandlesConstCharArrayWithoutModification()
{
	std::cout << GREEN << "\n############ Case CONST ARRAY with Chars ############" << RESETT << std::endl;

	const char constArray[] = "Hello";

	const size_t lengthChar = std::strlen(constArray);

	std::cout << CYAN << "Printing const array:\n";
	::iter(constArray, lengthChar, printElement<char>);  // Usa const overload
	std::cout << RESETT << std::endl;
}

void Iter_HandlesConstStringArrayProperly()
{
	std::cout << GREEN << "\n############ Case CONST ARRAY with Chars ############" << RESETT << std::endl;

	const std::string constArray[] = {"Hello", "world", "in", "c++ 98"};

	std::cout << RED << "Printing const array of string:\n";
	::iter(constArray, constArray->length() - 1, printElement<std::string>);  // Usa const overload
	std::cout << RESETT << std::endl;

}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Iter_IncrementsEachIntegerElement();
	Iter_IncrementsEachDoubleElement();
	Iter_IncrementsEachFloatElement();
	Iter_HandlesConstCharArrayWithoutModification();
	Iter_HandlesConstStringArrayProperly();

	return (0);
}
