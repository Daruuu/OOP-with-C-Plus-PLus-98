# 📚 C++ Module 00 - Basic C++ Concepts

This module introduces fundamental C++ concepts including basic syntax, classes, and object-oriented programming principles.

## 🎯 Learning Objectives

- Understand C++ basic syntax and structure
- Learn about classes and objects
- Master encapsulation with private/public members
- Practice with constructors and destructors
- Understand static members and methods
- Learn about file I/O and string manipulation

## 📁 Exercises Overview

### Exercise 00: Megaphone
**Files**: `megaphone.cpp`

A simple program that converts command-line arguments to uppercase and displays them.

**Key Concepts**:
- Command-line arguments (`argc`, `argv`)
- String manipulation with `std::toupper()`
- Basic I/O with `std::cout`
- Control flow with loops

**Learning Focus**:
- Understanding `argc` and `argv` parameters
- Working with C-style strings and `std::string`
- Character manipulation functions
- Basic program structure

### Exercise 01: PhoneBook
**Files**: `Contact.hpp`, `Contact.cpp`, `PhoneBook.hpp`, `PhoneBook.cpp`, `main.cpp`

A phone book application that stores and manages contact information.

**Key Concepts**:
- Class definition and implementation
- Private and public members
- Constructors and destructors
- Getter and setter methods
- Array of objects
- User input handling

**Class Structure**:
```cpp
class Contact {
private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;
    std::string darkestSecret_;

public:
    // Constructors, destructors, getters, setters
};
```

**Learning Focus**:
- Object-oriented programming basics
- Encapsulation principles
- Class member access control
- Object arrays and management
- User interface design

### Exercise 02: Account
**Files**: `Account.hpp`, `Account.cpp`, `tests.cpp`

A banking system simulation demonstrating static members and methods.

**Key Concepts**:
- Static class members
- Static methods
- Class constructors and destructors
- Timestamp generation
- Logging and debugging

**Class Structure**:
```cpp
class Account {
private:
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;
    
    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;

public:
    // Static methods for global account management
    // Instance methods for individual account operations
};
```

**Learning Focus**:
- Static members and their initialization
- Static methods and their usage
- Class-level vs instance-level operations
- Memory management with static data
- Debugging and logging techniques

## 🛠️ Technical Skills Developed

### C++ Fundamentals
- **Basic Syntax**: Variables, functions, control structures
- **Data Types**: `int`, `std::string`, arrays
- **I/O Operations**: `std::cout`, `std::cin`, file operations
- **String Manipulation**: Character functions, string methods

### Object-Oriented Programming
- **Classes**: Definition, implementation, instantiation
- **Encapsulation**: Private/public access control
- **Constructors/Destructors**: Object lifecycle management
- **Member Functions**: Methods, getters, setters

### Advanced Concepts
- **Static Members**: Class-level data and methods
- **Memory Management**: Object creation and destruction
- **User Interface**: Command-line interaction
- **Data Structures**: Arrays of objects

## 🚀 How to Use This Module

### Prerequisites
- Basic understanding of programming concepts
- Familiarity with command-line operations
- Text editor or IDE setup

### Compilation
Each exercise has its own Makefile:
```bash
cd cpp_module_00/ex00
make
./megaphone "hello world"

cd ../ex01
make
./phonebook

cd ../ex02
make
./account
```

### Testing
- **Exercise 00**: Test with various string inputs
- **Exercise 01**: Test contact addition, search, and display
- **Exercise 02**: Run provided tests to verify account operations

## 📖 Key Takeaways

1. **Class Design**: Learn to design classes with appropriate member visibility
2. **Encapsulation**: Understand the importance of data hiding
3. **Static Members**: Master class-level data and methods
4. **User Interface**: Design intuitive command-line interfaces
5. **Memory Management**: Understand object lifecycle in C++

## 🔗 Related Concepts

- **C++98 Standard**: All code follows C++98 compatibility
- **RAII**: Resource Acquisition Is Initialization
- **Const Correctness**: Proper use of `const` keyword
- **Header Guards**: Preventing multiple inclusions

## 📚 Further Reading

- [C++98 Standard Reference](https://en.cppreference.com/w/cpp/98)
- [Object-Oriented Programming in C++](https://www.learncpp.com/)
- [C++ Class Design](https://isocpp.org/wiki/faq/classes-and-objects)

---

*This module provides the foundation for understanding C++ object-oriented programming concepts that will be expanded upon in subsequent modules.*
