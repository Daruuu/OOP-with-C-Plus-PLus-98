#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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
    	animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
    	animals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete animals[i];

	/*
    std::cout << "\n=== Test 5: WrongAnimal vs WrongCat (no virtual) ===" << std::endl;
    class WrongAnimal {
    public:
        void makeSound() const { std::cout << "WrongAnimal sound\n"; }
        ~WrongAnimal() { std::cout << "WrongAnimal destructor\n"; }
    };

    class WrongCat : public WrongAnimal {
    public:
        void makeSound() const { std::cout << "Meow???\n"; }
        ~WrongCat() { std::cout << "WrongCat destructor\n"; }
    };

    const WrongAnimal* wa = new WrongCat();
    wa->makeSound(); // sorpresa: imprime "WrongAnimal sound", no "Meow???"
    delete wa;       // se llama solo ~WrongAnimal (no virtual destructor)

	*/
    std::cout << "\n=== All tests finished ===" << std::endl;
    return 0;
}

