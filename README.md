# C++98 Core Concepts

This repository contains my progress through the **C++ modules from 42 School**, implemented in **C++98**.
It showcases fundamental concepts of **Object-Oriented Programming (OOP)** and good coding practices in C++.

## 🚀 Content

### C++ Project Setup: Dependencies and Build Tools
Dependency management in C++ involves handling external libraries, packages, and dependencies required by a project.  
It includes downloading, installing, and linking libraries to build and run C++ programs.

[Setup Section(Makefile., CMake)](/dependencies_and_build_tools.md)

[Compilers, Debugging, and Standards Section](/compile_debug.md)

---

### [📦 cpp00 – First steps in C++](/cpp_module_00/subject/en.subject_cpp00.pdf)

* Compilation with `Makefile`
* Standard I/O (`iostream`)
* Basic classes (`PhoneBook`, `Contact`)
* Using `new` / `delete`
* Introduction to dynamic memory

### 📦 [cpp01 – Classes and dynamic allocation](cpp_module_01/subject/en.subjectcpp_01.pdf)

* Pointers and references
* **Stack vs Heap**
* Constructors and destructors
* Exercises with objects (`Zombie`, `Weapon`, `Human`)

### 📦 [cpp02 – Operator overloading](/cpp_module_02/subject/en.subjectcpp_02.pdf)

* **Operator overloading**
* Copy, assignment and object lifetime
* Fixed-point number implementation
* Encapsulation best practices

### 📦 [cpp03 – Inheritance](/cpp_module_03/subject/en.subject_cpp_03.pdf)

* **Base and derived classes**
* **Single and multiple inheritance**
* `virtual` keyword and the diamond problem
* Exercises with `ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap`

### 📦 [cpp04 – Polymorphism and abstract classes](/cpp_module_04/subject/en.subject_cpp_04.pdf)

* **Dynamic polymorphism**
* `virtual` methods and `override`
* Abstract classes and interfaces
* Composition vs aggregation (`Animal`, `Brain`, `Cat`, `Dog`)
* Magical materials (`AMateria`, `Cure`, `Ice`, `Character`, `MateriaSource`)

---

## 📖 Key Concepts Learned

* Object-Oriented Programming (OOP)
* Encapsulation, Abstraction, Inheritance, and Polymorphism
* Dynamic memory management in C++98
* Function and operator overloading
* Abstract classes vs Interfaces
* Good practices with `Makefile` and compilation flags

---

## 🛠️ Technologies

* **C++98** (required by 42 School)
* **Makefile**
* **g++ / clang++** with strict flags (`-Wall -Wextra -Werror`)

---

## 📌 Future Work

* Continue with modules **cpp05 – cpp09**
* Add UML diagrams for each module
* Improve testing with `assert` and `doctest`


---