cmake_minimum_required(VERSION 3.22.1)
project(Starting_with_Cpp)

set(CMAKE_CXX_STANDARD 98)

add_executable(Starting_with_Cpp main.cpp
)

set(CMAKE_CXX_STANDARD 98)

add_executable(Ex02_phonebook
        cpp_module_00/ex02/tests.cpp
        cpp_module_00/ex02/Account.cpp
        cpp_module_00/ex02/Account.hpp
)


set(CMAKE_CXX_STANDARD 98)

add_executable(Ex00
        cpp_module_01/ex00/Zombie.cpp
        cpp_module_01/ex00/Zombie.hpp
)

set(CMAKE_CXX_STANDARD 98)

add_executable(Cpp_01_ex01
        cpp_module_01/ex01/main.cpp
        cpp_module_01/ex01/Zombie.hpp
        cpp_module_01/ex01/zombieHorde.cpp
)

add_executable(Cpp_01_ex03
        cpp_module_01/ex03/main.cpp
        cpp_module_01/ex03/Weapon.cpp
        cpp_module_01/ex03/Weapon.hpp
        cpp_module_01/ex03/HumanA.cpp
        cpp_module_01/ex03/HumanA.hpp
        cpp_module_01/ex03/HumanB.cpp
        cpp_module_01/ex03/HumanB.hpp
)

add_executable(Cpp_01_ex04
        cpp_module_01/ex04/main.cpp
        cpp_module_01/ex04/Replace.cpp
        cpp_module_01/ex04/Replace.hpp
)

add_executable(Cpp_01_ex05
        cpp_module_01/ex05/main.cpp
        cpp_module_01/ex05/Harl.cpp
        cpp_module_01/ex05/Harl.hpp
)

add_executable(Cpp_02_ex03
        cpp_module_02/ex03/main.cpp
        cpp_module_02/ex03/Fixed.cpp
        cpp_module_02/ex03/Fixed.hpp
        cpp_module_02/ex03/Point.cpp
        cpp_module_02/ex03/Point.hpp
)

add_executable(Cpp_03_ex03
        cpp_module_03/ex03/main.cpp
        cpp_module_03/ex03/ClapTrap.hpp
        cpp_module_03/ex03/ClapTrap.cpp
        cpp_module_03/ex03/ScavTrap.hpp
        cpp_module_03/ex03/ScavTrap.cpp
        cpp_module_03/ex03/FragTrap.hpp
        cpp_module_03/ex03/FragTrap.cpp
        cpp_module_03/ex03/DiamondTrap.hpp
        cpp_module_03/ex03/DiamondTrap.cpp
)

add_executable(Cpp04_ex00
        cpp_module_04/ex00/main.cpp
        cpp_module_04/ex00/Animal.cpp
        cpp_module_04/ex00/Dog.cpp
        cpp_module_04/ex00/Dog.hpp
        cpp_module_04/ex00/Cat.cpp
        cpp_module_04/ex00/Cat.hpp
        cpp_module_04/ex00/WrongCat.cpp
        cpp_module_04/ex00/WrongCat.hpp
        cpp_module_04/ex00/WrongAnimal.cpp
        cpp_module_04/ex00/WrongAnimal.hpp
)

add_executable(Cpp04_ex01
        cpp_module_04/ex01/main.cpp
        cpp_module_04/ex01/Animal.cpp
        cpp_module_04/ex01/Dog.cpp
        cpp_module_04/ex01/Dog.hpp
        cpp_module_04/ex01/Cat.cpp
        cpp_module_04/ex01/Cat.hpp
        cpp_module_04/ex01/WrongCat.cpp
        cpp_module_04/ex01/WrongCat.hpp
        cpp_module_04/ex01/WrongAnimal.cpp
        cpp_module_04/ex01/WrongAnimal.hpp
        cpp_module_04/ex01/Brain.cpp
        cpp_module_04/ex01/Brain.hpp

)

add_executable(Cpp04_ex02
        cpp_module_04/ex02/main.cpp
        cpp_module_04/ex02/AAnimal.cpp
        cpp_module_04/ex02/AAnimal.hpp
        cpp_module_04/ex02/Dog.cpp
        cpp_module_04/ex02/Dog.hpp
        cpp_module_04/ex02/Cat.cpp
        cpp_module_04/ex02/Cat.hpp
        cpp_module_04/ex02/WrongCat.cpp
        cpp_module_04/ex02/WrongCat.hpp
        cpp_module_04/ex02/WrongAnimal.cpp
        cpp_module_04/ex02/WrongAnimal.hpp
        cpp_module_04/ex02/Brain.cpp
        cpp_module_04/ex02/Brain.hpp

)
add_executable(Cpp04_ex03
        cpp_module_04/ex03/main.cpp
        cpp_module_04/ex03/AMateria.cpp
        cpp_module_04/ex03/AMateria.hpp
        cpp_module_04/ex03/Ice.cpp
        cpp_module_04/ex03/Ice.hpp
        cpp_module_04/ex03/Cure.cpp
        cpp_module_04/ex03/Cure.hpp
)
