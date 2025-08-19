#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== Test 1: Basic instances ===" << std::endl;
    std::cout << GREEN << "========== Stored in STACK ==========" << RESET << std::endl;
    std::cout << GREEN << "-------------------------------------" << RESET << std::endl;

    // Objects created on stack → automatically destroyed at the end of scope
    Animal a;
    a.makeSound();

    Dog d;
    d.makeSound();

    Cat c;
    c.makeSound();

    std::cout << GREEN << "-------------------------------------" << RESET << std::endl;

    // ---------------------------------------------------------------
    std::cout << "\n=== Test 2: Polymorphism with pointers ===" << std::endl;
    std::cout << GREEN << "************ Stored in HEAP ************" << RESET << std::endl;

    // Objects created on heap → must be deleted manually
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    dog->makeSound(); // should call Dog::makeSound()
    cat->makeSound(); // should call Cat::makeSound()

    std::cout << GREEN << "-------------------------------------" << RESET << std::endl;

    delete dog; // thanks to virtual destructor → Dog then Animal
    delete cat; // thanks to virtual destructor → Cat then Animal

    // ---------------------------------------------------------------
    std::cout << "\n=== Test 3: Copy constructor & assignment ===" << std::endl;
    std::cout << GREEN << "************ Stored in STACK ************" << RESET << std::endl;
    std::cout << CYAN << "-------------------------------------" << RESET << std::endl;

    Dog dog1;
    Dog dog2(dog1);   // copy constructor

    Cat cat1;
    Cat cat2;
    cat2 = cat1;      // copy assignment operator

    std::cout << CYAN << "-------------------------------------" << RESET << std::endl;

    // ---------------------------------------------------------------
    std::cout << "\n=== Test 4: Array of Animals ===" << std::endl;
    const Animal* animals[4];

	int size = sizeof(animals) / sizeof(animals[0]);

    for (int i = 0; i < size; ++i) {
    	if (i % 2 == 0)
			animals[i] = new Dog();
    	else
			animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    // ---------------------------------------------------------------
    std::cout << "\n=== WrongAnimal tests (no virtual functions) ===" << std::endl;

    std::cout << "\n--- Test 1: Basic instances ---" << std::endl;
    WrongAnimal wa;
    wa.makeSound();

    WrongCat wc;
    wc.makeSound();

    std::cout << "\n--- Test 2: Polymorphism without virtual ---" << std::endl;
    const WrongAnimal* wrong = new WrongCat();

    std::cout << "Type: " << wrong->getType() << std::endl;
    wrong->makeSound();
    // ⚠️ Calls WrongAnimal::makeSound() instead of WrongCat::makeSound()
    // because makeSound() is NOT virtual

    delete wrong;
    // ⚠️ Only WrongAnimal destructor is called (not WrongCat) if destructor is not virtual

    std::cout << "\n--- Test 3: Copy & Assignment ---" << std::endl;
    WrongCat wc1;
    WrongCat wc2(wc1);   // copy constructor
    WrongCat wc3;
    wc3 = wc1;           // copy assignment

    // ---------------------------------------------------------------
    std::cout << "\n=== All tests finished ===" << std::endl;
    return 0;
}


/*
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
*/

