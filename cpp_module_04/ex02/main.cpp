#include "AAnimal.hpp"
// #include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
int main()
{
	// const AAnimal* base = new Animal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << "---------------------\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "---------------------\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// base->makeSound();

	// delete base;
	delete i;
	delete j;

	return (0);
}
*/

int main()
{
	std::cout << "---- Test 1: AAnimal no se puede instanciar ----" << std::endl;
	//	not work because now class AAnimal is abstract
	// AAnimal a;
	// AAnimal* a2 = new AAnimal();

	std::cout << std::endl << "---- Test 2: Polimorfismo con AAnimal* ----" << std::endl;
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << "---------------------\n";

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "---------------------\n";

	std::cout << "*********************************\n";
	dog->makeSound(); // should bark
	cat->makeSound(); // should meow
	std::cout << "*********************************\n";

	delete dog;
	delete cat;

	std::cout << std::endl << "---- Test 3: Destructores virtuales ----" << std::endl;
	const AAnimal* test = new Dog();
	delete test; // si AAnimal destructor no es virtual → leak

	std::cout << std::endl << "---- Test 4: Copia y asignación ----" << std::endl;
	Dog basic;
	Dog copy(basic);      // copy constructor
	Dog assigned;
	assigned = basic;     // copy assignment

	std::cout << std::endl << "---- Test 5: Array de AAnimal* ----" << std::endl;
	const AAnimal* animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal[" << i << "] type: " << animals[i]->getType() << " → ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << std::endl << "---- FIN DE LOS TESTS ----" << std::endl;

	return 0;
}