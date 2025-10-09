#include <iostream>
#include "Serializer.hpp"

#define RESETT   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void testCaseBase(void)
{
	std::cout << GREEN << "CASE 1: Case Base" << RESETT << std::endl;

	Data *data = new Data;
	data->name = "case base 01";
	data->value = 100;

	std::cout << "\nOriginal data - Address: " << data
			  << "\nName: " << data->name
			  << "\nValue: " << data->value << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(data);

	std::cout << "Serialized: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized data - Address: " << deserialized
			  << "\nName: " << deserialized->name
			  << "\nValue: " << deserialized->value << std::endl;

	std::cout << "Pointers are equal: "
			  << (data == deserialized ? "true" : "false") << std::endl;

	delete data;
}

void testCaseMultipleObjects()
{
	std::cout << GREEN << "\nCASE 2: Multiple distinct objects" << RESETT << std::endl;

	Data *a = new Data;
	a->name = "obj-A";
	a->value = 10;

	Data *b = new Data;
	b->name = "obj-B";
	b->value = 20;

	uintptr_t rawA = Serializer::serialize(a);
	uintptr_t rawB = Serializer::serialize(b);

	std::cout << "A raw: " << rawA << ", B raw: " << rawB << std::endl;

	delete a; delete b;
}

void testCaseNullPointer()
{
	std::cout << GREEN << "\nCASE 3: NULL pointer:" << RESETT << std::endl;

	Data* nullPtr = NULL;

	uintptr_t rawNull = Serializer::serialize(nullPtr);

	Data* backNull = Serializer::deserialize(rawNull);

	std::cout << "Raw value: " << rawNull << "\n";
	std::cout << "Pointer restored: " << backNull << "\n";
	std::cout << "Is NULL: " << (backNull == NULL ? "true" : "false") << std::endl;
}

void testStackObjects()
{
	std::cout << GREEN << "\nCASE 4: Stack object:" << RESETT << std::endl;

	Data localData;
	localData.name = "stackData";
	localData.value = 55;

	uintptr_t rawLocal = Serializer::serialize(&localData);

	Data* backLocal = Serializer::deserialize(rawLocal);
	std::cout << "Address local: " << &localData << "\n";
	std::cout << "Deserialized ptr: " << backLocal << "\n";
	std::cout << "Equal pointers: " << (&localData == backLocal ? "true" : "false") << "\n";
}

int main()
{
	testCaseBase();
	testCaseMultipleObjects();
	testCaseNullPointer();
	testStackObjects();
	return (0);
}
