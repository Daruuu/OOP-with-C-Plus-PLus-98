# 🧠 C++ Module 01 - Memory Allocation and References

This module focuses on memory management in C++, including dynamic allocation, references, and the differences between stack and heap memory.

## 🎯 Learning Objectives

- Understand memory allocation with `new` and `delete`
- Master the concept of references in C++
- Learn about stack vs heap memory
- Practice with dynamic object creation
- Understand function parameter passing mechanisms
- Learn about memory leaks and proper cleanup

## 📁 Exercises Overview

### Exercise 00: Zombie Horde
**Files**: `Zombie.hpp`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`

Introduction to dynamic memory allocation and object lifecycle management.

**Key Concepts**:
- Dynamic memory allocation with `new`
- Memory deallocation with `delete`
- Stack vs heap memory
- Object constructors and destructors
- Function parameter passing

**Class Structure**:
```cpp
class Zombie {
private:
    std::string name_;

public:
    Zombie(std::string name);
    ~Zombie();
    void announce();
};

// Global functions
Zombie* newZombie(std::string name);  // Heap allocation
void randomChump(std::string name);   // Stack allocation
```

**Learning Focus**:
- Understanding when to use stack vs heap allocation
- Proper memory management practices
- Constructor and destructor execution order
- Function parameter passing mechanisms

### Exercise 01: Zombie Horde (Array)
**Files**: `Zombie.hpp`, `Zombie.cpp`, `zombieHorde.cpp`, `main.cpp`

Advanced memory management with arrays of dynamically allocated objects.

**Key Concepts**:
- Dynamic array allocation with `new[]`
- Array deallocation with `delete[]`
- Managing arrays of objects
- Memory management best practices

**Function Signature**:
```cpp
Zombie* zombieHorde(int N, std::string name);
```

**Learning Focus**:
- Array allocation and deallocation
- Managing multiple objects
- Memory leak prevention
- Proper cleanup procedures

### Exercise 02: Memory Management
**Files**: `main.cpp`

A comprehensive exercise focusing on memory management concepts and best practices.

**Key Concepts**:
- Memory allocation strategies
- Resource management
- RAII (Resource Acquisition Is Initialization)
- Memory leak detection

**Learning Focus**:
- Understanding memory lifecycle
- Proper resource cleanup
- Memory management patterns
- Debugging memory issues

### Exercise 03: References and Pointers
**Files**: `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`, `Weapon.hpp`, `Weapon.cpp`, `main.cpp`

Demonstrates the differences between references and pointers in C++.

**Key Concepts**:
- References vs pointers
- Reference initialization
- Pointer assignment
- Const references
- Reference lifetime

**Class Structure**:
```cpp
class Weapon {
private:
    std::string type_;

public:
    Weapon(std::string type);
    const std::string& getType();
    void setType(std::string type);
};

class HumanA {
private:
    std::string name_;
    Weapon& weapon_;  // Reference member

public:
    HumanA(std::string name, Weapon& weapon);
    void attack();
};

class HumanB {
private:
    std::string name_;
    Weapon* weapon_;  // Pointer member

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};
```

**Learning Focus**:
- Reference initialization requirements
- Pointer assignment flexibility
- When to use references vs pointers
- Const correctness with references

### Exercise 04: File Operations
**Files**: `Replace.hpp`, `Replace.cpp`, `main.cpp`

File I/O operations and string manipulation with proper memory management.

**Key Concepts**:
- File input/output operations
- String replacement algorithms
- Memory management in file operations
- Error handling

**Class Structure**:
```cpp
class Replace {
private:
    std::string filename_;
    std::string s1_;
    std::string s2_;

public:
    Replace(std::string filename, std::string s1, std::string s2);
    void replace();
};
```

**Learning Focus**:
- File stream operations
- String manipulation
- Error handling
- Resource management

### Exercise 05: Harl Filter
**Files**: `Harl.hpp`, `Harl.cpp`, `main.cpp`

Advanced string processing and conditional logic with proper memory management.

**Key Concepts**:
- String comparison and processing
- Conditional logic
- Function pointers
- Memory-efficient string operations

**Class Structure**:
```cpp
class Harl {
private:
    void debug();
    void info();
    void warning();
    void error();

public:
    void complain(std::string level);
};
```

**Learning Focus**:
- String processing techniques
- Conditional execution
- Code organization
- Memory-efficient algorithms

### Exercise 06: Harl Filter (Switch)
**Files**: `Harl.hpp`, `Harl.cpp`, `main.cpp`

Alternative implementation using switch statements for better performance.

**Key Concepts**:
- Switch statement optimization
- Hash-based string matching
- Performance considerations
- Code optimization techniques

**Learning Focus**:
- Switch statement usage
- Performance optimization
- Hash functions
- Alternative implementation strategies

## 🛠️ Technical Skills Developed

### Memory Management
- **Dynamic Allocation**: `new` and `delete` operators
- **Array Management**: `new[]` and `delete[]` operators
- **Stack vs Heap**: Understanding memory allocation strategies
- **RAII**: Resource management principles

### References and Pointers
- **References**: Initialization, usage, and limitations
- **Pointers**: Assignment, dereferencing, and null handling
- **Const Correctness**: Proper use of const with references
- **Parameter Passing**: Value, reference, and pointer passing

### Advanced C++ Features
- **Function Pointers**: Dynamic function calls
- **String Processing**: Efficient string manipulation
- **File I/O**: Stream operations and error handling
- **Error Handling**: Proper error management techniques

## 🚀 How to Use This Module

### Prerequisites
- Completion of C++ Module 00
- Understanding of basic C++ syntax
- Familiarity with classes and objects

### Compilation
Each exercise has its own Makefile:
```bash
cd cpp_module_01/ex00
make
./zombie

cd ../ex01
make
./zombieHorde

cd ../ex03
make
./human

cd ../ex04
make
./replace

cd ../ex05
make
./harl
```

### Testing
- **Exercise 00**: Test zombie creation and destruction
- **Exercise 01**: Test array allocation and cleanup
- **Exercise 03**: Test reference vs pointer behavior
- **Exercise 04**: Test file replacement functionality
- **Exercise 05/06**: Test different complaint levels

## 📖 Key Takeaways

1. **Memory Management**: Always pair `new` with `delete` and `new[]` with `delete[]`
2. **References**: Must be initialized and cannot be reassigned
3. **Pointers**: Can be reassigned and can be null
4. **RAII**: Acquire resources in constructors, release in destructors
5. **Stack vs Heap**: Use stack for automatic cleanup, heap for dynamic lifetime

## ⚠️ Common Pitfalls

- **Memory Leaks**: Forgetting to delete dynamically allocated memory
- **Double Delete**: Attempting to delete the same memory twice
- **Dangling Pointers**: Using pointers after memory has been freed
- **Reference Reassignment**: Attempting to reassign references
- **Array Mismatch**: Using `delete` instead of `delete[]` for arrays

## 🔗 Related Concepts

- **Smart Pointers**: Modern C++ memory management (C++11+)
- **RAII**: Resource management principle
- **Move Semantics**: Efficient resource transfer (C++11+)
- **Exception Safety**: Memory management in exception scenarios

## 📚 Further Reading

- [C++ Memory Management](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- [References vs Pointers](https://isocpp.org/wiki/faq/references)
- [RAII Principle](https://en.cppreference.com/w/cpp/language/raii)
- [Memory Management Best Practices](https://isocpp.org/wiki/faq/freestore-mgmt)

---

*This module provides essential knowledge for proper memory management in C++, which is crucial for writing robust and efficient C++ programs.*
