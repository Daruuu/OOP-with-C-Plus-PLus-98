#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== Test 1: Basic instances ===" << std::endl;
	std::cout << GREEN << "========== Store in STACK: ==========" << RESET << std::endl;
	std::cout << GREEN << "----------------------------------" << RESET << std::endl;

    Animal a;
    a.makeSound();

    Dog d;
    d.makeSound();

    Cat c;
    c.makeSound();

	std::cout << GREEN << "----------------------------------" << RESET << std::endl;

    std::cout << "\n=== Test 2: Polymorphism with pointers ===" <<
    	std::endl;
	std::cout << GREEN << "************ Store in HEAP: ************" << RESET << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
	std::cout << GREEN << "----------------------------------" << RESET << std::endl;

    delete dog; // virtual destructor → first Dog, after Animal
    delete cat; // virtual destructor → first Cat, after Animal

    std::cout << "\n=== Test 3: Copy constructor & assignment ===" << std::endl;
	std::cout << GREEN << "************ Store in HEAP: ************" << RESET
	<< std::endl;
	std::cout << CYAN << "----------------------------------" << std::endl;

    Dog dog1;
    Dog dog2(dog1);   // copy constructor

    Cat cat1;
    Cat cat2;
    cat2 = cat1;      // copy assignment
	std::cout << CYAN << "----------------------------------" << RESET
	<< std::endl;

    std::cout << "\n=== Test 4: Array of Animals ===" << std::endl;
    const Animal* animals[4];

    for (int i = 0; i < 2; ++i)
    {
    	animals[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i)
    {
    	animals[i] = new Cat();
    }

	std::cout << "\n=== Test 1: Basic instances with WrongAnimals ===" << std::endl;
	WrongAnimal wa;
	wa.makeSound();

	WrongCat wc;
	wc.makeSound();

	std::cout << "\n=== Test 2: Polymorphism without virtual ===" << std::endl;
	const WrongAnimal* wrong = new WrongCat();

	std::cout << "Type: " << wrong->getType() << std::endl;
	wrong->makeSound(); // should call WrongAnimal::makeSound()

	delete wrong;

	std::cout << "\n=== Test 3: Copy & Assignment ===" << std::endl;
	WrongCat wc1;
	WrongCat wc2(wc1);   // copy constructor
	WrongCat wc3;
	wc3 = wc1;           // copy assignment

	for (int i = 0; i < 4; ++i)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
	}
	std::cout << "\n=== All tests finished ===" << std::endl;

    return 0;
}

