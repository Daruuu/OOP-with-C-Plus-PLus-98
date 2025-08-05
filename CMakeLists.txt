cmake_minimum_required(VERSION 3.22.1)
project(Starting_with_Cpp)

set(CMAKE_CXX_STANDARD 98)

add_executable(Starting_with_Cpp main.cpp
)

set(CMAKE_CXX_STANDARD 98)

add_executable( Ex02_phonebook
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

add_executable( Cpp_01_ex03
        cpp_module_01/ex03/main.cpp
        cpp_module_01/ex03/Weapon.cpp
        cpp_module_01/ex03/Weapon.hpp
        cpp_module_01/ex03/HumanA.cpp
        cpp_module_01/ex03/HumanA.hpp
        cpp_module_01/ex03/HumanB.cpp
        cpp_module_01/ex03/HumanB.hpp
)

add_executable( Cpp_01_ex04
        cpp_module_01/ex04/main.cpp
        cpp_module_01/ex04/Replace.cpp
        cpp_module_01/ex04/Replace.hpp
)
