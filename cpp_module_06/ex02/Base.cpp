#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base* generate()
{
	// std::srand(std::time(NULL));
	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "Generated class A" << std::endl;
		return new A();
	case 1:
		std::cout << "Generated class B" << std::endl;
		return new B();
	case 2:
		std::cout << "Generated class C" << std::endl;
		return new C();
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	if (p == NULL)
	{
		std::cout << "Null Pointer" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "invalid type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{}
	std::cout << "unknow type" << std::endl;
}
