# 🧪 Complete Guide to CppUnit Testing in C++98

This comprehensive guide will help you master unit testing using CppUnit in C++98 projects, from basic setup to advanced testing patterns.

## 📋 Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Project Configuration](#project-configuration)
4. [Basic Structure](#basic-structure)
5. [Practical Examples](#practical-examples)
6. [Advanced Makefile](#advanced-makefile)
7. [Best Practices](#best-practices)
8. [Testing Patterns](#testing-patterns)
9. [Assertions Reference](#assertions-reference)
10. [Troubleshooting](#troubleshooting)
11. [Useful Commands](#useful-commands)
12. [Additional Resources](#additional-resources)

---

## 🎯 Introduction

CppUnit is a unit testing framework for C++ that provides a comprehensive set of tools for writing and running tests. This guide focuses on using CppUnit with C++98, ensuring compatibility with older C++ standards while maintaining modern testing practices.

### Why CppUnit for C++98?

- **Standards Compliance**: Works seamlessly with C++98
- **Mature Framework**: Battle-tested in production environments
- **Rich Assertions**: Comprehensive set of testing macros
- **Flexible**: Supports various test patterns and organizational structures

---

## 🔧 Installation

### Option 1: Local Installation (Recommended for C++98)

```bash
# Download CppUnit
wget https://sourceforge.net/projects/cppunit/files/cppunit/1.15.1/cppunit-1.15.1.tar.gz
tar -xzf cppunit-1.15.1.tar.gz
cd cppunit-1.15.1

# Configure for C++98
./configure --prefix=$HOME/cppunit-local CXXFLAGS="-std=c++98"

# Compile and install
make
make install

# Add to your environment
echo 'export LD_LIBRARY_PATH=$HOME/cppunit-local/lib:$LD_LIBRARY_PATH' >> ~/.bashrc
echo 'export PKG_CONFIG_PATH=$HOME/cppunit-local/lib/pkgconfig:$PKG_CONFIG_PATH' >> ~/.bashrc
source ~/.bashrc
```

### Option 2: Package Manager Installation

```bash
# Ubuntu/Debian
sudo apt-get install libcppunit-dev

# CentOS/RHEL/Fedora
sudo yum install cppunit-devel
# or
sudo dnf install cppunit-devel

# Arch Linux
sudo pacman -S cppunit

# macOS (with Homebrew)
brew install cppunit
```

### Option 3: Manual Compilation

```bash
# Clone from source
git clone https://github.com/cppunit/cppunit.git
cd cppunit

# Configure for C++98
./configure --prefix=/usr/local CXXFLAGS="-std=c++98 -Wall -Wextra"

# Compile and install
make
sudo make install
```

---

## ⚙️ Project Configuration

### Directory Structure

```
your_project/
├── Makefile
├── main.cpp
├── src/
│   ├── Calculator.cpp
│   └── Calculator.hpp
├── tests/
│   ├── Testing.hpp
│   ├── Testing.cpp
│   └── CalculatorTest.hpp
└── README.md
```

### Verify Installation

```bash
# Check if CppUnit is properly installed
pkg-config --cflags --libs cppunit

# Or verify manually
make check-cppunit
```

### Environment Variables

```bash
# Add to your ~/.bashrc or ~/.zshrc
export CPPUNIT_ROOT=$HOME/cppunit-local
export LD_LIBRARY_PATH=$CPPUNIT_ROOT/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=$CPPUNIT_ROOT/lib/pkgconfig:$PKG_CONFIG_PATH
```

---

## 🏗️ Basic Structure

### 1. Header File (`Testing.hpp`)

```cpp
#ifndef TESTING_HPP
#define TESTING_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <string>

class MyTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(MyTest);
    CPPUNIT_TEST(testBasicAddition);
    CPPUNIT_TEST(testStringOperations);
    CPPUNIT_TEST(testExceptionHandling);
    CPPUNIT_TEST_SUITE_END();

public:
    // Setup and teardown methods
    void setUp();        // Executed before each test
    void tearDown();     // Executed after each test
    
    // Test methods
    void testBasicAddition();
    void testStringOperations();
    void testExceptionHandling();

private:
    // Test data members
    std::string testString;
    int testValue;
};

#endif // TESTING_HPP
```

### 2. Implementation (`Testing.cpp`)

```cpp
#include "Testing.hpp"
#include <stdexcept>

void MyTest::setUp() {
    // Common initialization for all tests
    testString = "Hello, World!";
    testValue = 42;
}

void MyTest::tearDown() {
    // Cleanup after each test
    testString.clear();
    testValue = 0;
}

void MyTest::testBasicAddition() {
    int result = 2 + 2;
    CPPUNIT_ASSERT(result == 4);
    CPPUNIT_ASSERT_EQUAL(4, result);
    
    // Test with negative numbers
    result = -5 + 3;
    CPPUNIT_ASSERT_EQUAL(-2, result);
}

void MyTest::testStringOperations() {
    CPPUNIT_ASSERT(testString.length() == 13);
    CPPUNIT_ASSERT_EQUAL(std::string("Hello, World!"), testString);
    
    // Test string modification
    testString += " Test";
    CPPUNIT_ASSERT(testString.find("Test") != std::string::npos);
}

void MyTest::testExceptionHandling() {
    // Verify that an exception is thrown
    CPPUNIT_ASSERT_THROW(
        throw std::runtime_error("test exception"), 
        std::runtime_error
    );
    
    // Verify that no exception is thrown
    CPPUNIT_ASSERT_NO_THROW(int x = testValue);
}
```

### 3. Entry Point (`main.cpp`)

```cpp
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "Testing.hpp"

int main() {
    CppUnit::TextUi::TestRunner runner;
    
    // Add test suites
    runner.addTest(MyTest::suite());
    
    // Alternative: Add all tests from registry
    // runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    
    // Run tests
    bool success = runner.run();
    
    // Return appropriate exit code
    return success ? 0 : 1;
}
```

---

## 💡 Practical Examples

### Example 1: Testing Simple Classes

```cpp
// Calculator.hpp
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator {
public:
    Calculator();
    ~Calculator();
    
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);
    bool isEven(int number);
    bool isPrime(int number);
    
private:
    bool isValidNumber(int number);
};

#endif // CALCULATOR_HPP

// CalculatorTest.hpp
#ifndef CALCULATOR_TEST_HPP
#define CALCULATOR_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "Calculator.hpp"

class CalculatorTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSubtract);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testDivide);
    CPPUNIT_TEST(testDivideByZero);
    CPPUNIT_TEST(testIsEven);
    CPPUNIT_TEST(testIsPrime);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    
    void testAdd();
    void testSubtract();
    void testMultiply();
    void testDivide();
    void testDivideByZero();
    void testIsEven();
    void testIsPrime();

private:
    Calculator* calculator;
};

#endif // CALCULATOR_TEST_HPP

// CalculatorTest.cpp
#include "CalculatorTest.hpp"
#include <stdexcept>

void CalculatorTest::setUp() {
    calculator = new Calculator();
}

void CalculatorTest::tearDown() {
    delete calculator;
    calculator = NULL;
}

void CalculatorTest::testAdd() {
    CPPUNIT_ASSERT_EQUAL(5, calculator->add(2, 3));
    CPPUNIT_ASSERT_EQUAL(0, calculator->add(-5, 5));
    CPPUNIT_ASSERT_EQUAL(-8, calculator->add(-3, -5));
}

void CalculatorTest::testSubtract() {
    CPPUNIT_ASSERT_EQUAL(1, calculator->subtract(3, 2));
    CPPUNIT_ASSERT_EQUAL(-2, calculator->subtract(3, 5));
    CPPUNIT_ASSERT_EQUAL(0, calculator->subtract(5, 5));
}

void CalculatorTest::testMultiply() {
    CPPUNIT_ASSERT_EQUAL(6, calculator->multiply(2, 3));
    CPPUNIT_ASSERT_EQUAL(0, calculator->multiply(0, 100));
    CPPUNIT_ASSERT_EQUAL(-15, calculator->multiply(-3, 5));
}

void CalculatorTest::testDivide() {
    CPPUNIT_ASSERT_EQUAL(2, calculator->divide(6, 3));
    CPPUNIT_ASSERT_EQUAL(0, calculator->divide(0, 5));
    CPPUNIT_ASSERT_EQUAL(-2, calculator->divide(-6, 3));
}

void CalculatorTest::testDivideByZero() {
    CPPUNIT_ASSERT_THROW(
        calculator->divide(5, 0), 
        std::runtime_error
    );
}

void CalculatorTest::testIsEven() {
    CPPUNIT_ASSERT(calculator->isEven(4));
    CPPUNIT_ASSERT(!calculator->isEven(3));
    CPPUNIT_ASSERT(calculator->isEven(0));
    CPPUNIT_ASSERT(calculator->isEven(-2));
}

void CalculatorTest::testIsPrime() {
    CPPUNIT_ASSERT(calculator->isPrime(2));
    CPPUNIT_ASSERT(calculator->isPrime(3));
    CPPUNIT_ASSERT(calculator->isPrime(17));
    CPPUNIT_ASSERT(!calculator->isPrime(4));
    CPPUNIT_ASSERT(!calculator->isPrime(1));
}
```

### Example 2: Testing Container Classes

```cpp
// StringList.hpp
#ifndef STRING_LIST_HPP
#define STRING_LIST_HPP

#include <string>
#include <vector>

class StringList {
public:
    StringList();
    ~StringList();
    
    void add(const std::string& str);
    void remove(const std::string& str);
    bool contains(const std::string& str) const;
    size_t size() const;
    std::string get(size_t index) const;
    void clear();
    
private:
    std::vector<std::string> items;
};

#endif // STRING_LIST_HPP

// StringListTest.hpp
class StringListTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(StringListTest);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testRemove);
    CPPUNIT_TEST(testContains);
    CPPUNIT_TEST(testSize);
    CPPUNIT_TEST(testGet);
    CPPUNIT_TEST(testClear);
    CPPUNIT_TEST(testIndexOutOfBounds);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    
    void testAdd();
    void testRemove();
    void testContains();
    void testSize();
    void testGet();
    void testClear();
    void testIndexOutOfBounds();

private:
    StringList* stringList;
};

// StringListTest.cpp
void StringListTest::setUp() {
    stringList = new StringList();
}

void StringListTest::tearDown() {
    delete stringList;
    stringList = NULL;
}

void StringListTest::testAdd() {
    CPPUNIT_ASSERT_EQUAL(0U, stringList->size());
    
    stringList->add("first");
    CPPUNIT_ASSERT_EQUAL(1U, stringList->size());
    
    stringList->add("second");
    CPPUNIT_ASSERT_EQUAL(2U, stringList->size());
}

void StringListTest::testRemove() {
    stringList->add("item1");
    stringList->add("item2");
    
    CPPUNIT_ASSERT_EQUAL(2U, stringList->size());
    
    stringList->remove("item1");
    CPPUNIT_ASSERT_EQUAL(1U, stringList->size());
    CPPUNIT_ASSERT(!stringList->contains("item1"));
}

void StringListTest::testContains() {
    stringList->add("test");
    
    CPPUNIT_ASSERT(stringList->contains("test"));
    CPPUNIT_ASSERT(!stringList->contains("notfound"));
}

void StringListTest::testSize() {
    CPPUNIT_ASSERT_EQUAL(0U, stringList->size());
    
    for (int i = 0; i < 5; ++i) {
        stringList->add("item" + std::to_string(i));
    }
    
    CPPUNIT_ASSERT_EQUAL(5U, stringList->size());
}

void StringListTest::testGet() {
    stringList->add("first");
    stringList->add("second");
    
    CPPUNIT_ASSERT_EQUAL(std::string("first"), stringList->get(0));
    CPPUNIT_ASSERT_EQUAL(std::string("second"), stringList->get(1));
}

void StringListTest::testClear() {
    stringList->add("item1");
    stringList->add("item2");
    
    CPPUNIT_ASSERT_EQUAL(2U, stringList->size());
    
    stringList->clear();
    CPPUNIT_ASSERT_EQUAL(0U, stringList->size());
}

void StringListTest::testIndexOutOfBounds() {
    CPPUNIT_ASSERT_THROW(
        stringList->get(0), 
        std::out_of_range
    );
    
    stringList->add("item");
    CPPUNIT_ASSERT_THROW(
        stringList->get(1), 
        std::out_of_range
    );
}
```

### Example 3: Testing File Operations

```cpp
// FileManager.hpp
#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>

class FileManager {
public:
    FileManager();
    ~FileManager();
    
    bool createFile(const std::string& filename);
    bool deleteFile(const std::string& filename);
    bool fileExists(const std::string& filename);
    size_t getFileSize(const std::string& filename);
    bool writeToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
    
private:
    std::string testDirectory;
};

#endif // FILE_MANAGER_HPP

// FileManagerTest.hpp
class FileManagerTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(FileManagerTest);
    CPPUNIT_TEST(testCreateFile);
    CPPUNIT_TEST(testDeleteFile);
    CPPUNIT_TEST(testFileExists);
    CPPUNIT_TEST(testGetFileSize);
    CPPUNIT_TEST(testWriteAndRead);
    CPPUNIT_TEST(testNonExistentFile);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    
    void testCreateFile();
    void testDeleteFile();
    void testFileExists();
    void testGetFileSize();
    void testWriteAndRead();
    void testNonExistentFile();

private:
    FileManager* fileManager;
    std::string testFileName;
};

// FileManagerTest.cpp
void FileManagerTest::setUp() {
    fileManager = new FileManager();
    testFileName = "test_file.txt";
}

void FileManagerTest::tearDown() {
    // Clean up test files
    if (fileManager->fileExists(testFileName)) {
        fileManager->deleteFile(testFileName);
    }
    delete fileManager;
    fileManager = NULL;
}

void FileManagerTest::testCreateFile() {
    CPPUNIT_ASSERT(fileManager->createFile(testFileName));
    CPPUNIT_ASSERT(fileManager->fileExists(testFileName));
}

void FileManagerTest::testDeleteFile() {
    fileManager->createFile(testFileName);
    CPPUNIT_ASSERT(fileManager->fileExists(testFileName));
    
    CPPUNIT_ASSERT(fileManager->deleteFile(testFileName));
    CPPUNIT_ASSERT(!fileManager->fileExists(testFileName));
}

void FileManagerTest::testFileExists() {
    CPPUNIT_ASSERT(!fileManager->fileExists(testFileName));
    
    fileManager->createFile(testFileName);
    CPPUNIT_ASSERT(fileManager->fileExists(testFileName));
}

void FileManagerTest::testGetFileSize() {
    fileManager->createFile(testFileName);
    CPPUNIT_ASSERT_EQUAL(0U, fileManager->getFileSize(testFileName));
    
    fileManager->writeToFile(testFileName, "Hello");
    CPPUNIT_ASSERT_EQUAL(5U, fileManager->getFileSize(testFileName));
}

void FileManagerTest::testWriteAndRead() {
    std::string content = "Test content for file operations";
    
    CPPUNIT_ASSERT(fileManager->writeToFile(testFileName, content));
    CPPUNIT_ASSERT_EQUAL(content, fileManager->readFromFile(testFileName));
}

void FileManagerTest::testNonExistentFile() {
    CPPUNIT_ASSERT_THROW(
        fileManager->readFromFile("nonexistent.txt"),
        std::runtime_error
    );
    
    CPPUNIT_ASSERT_THROW(
        fileManager->getFileSize("nonexistent.txt"),
        std::runtime_error
    );
}
```

---

## 🔨 Advanced Makefile

Here's a comprehensive Makefile that supports both release and debug builds, automatic CppUnit detection, and various useful targets:

```makefile
# Makefile for C++98 CppUnit Testing Project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
MAIN_SOURCE = main.cpp

# Object files
DEBUG_OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(DEBUG_DIR)/%.o)
RELEASE_OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(RELEASE_DIR)/%.o)
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(DEBUG_DIR)/%.o)
MAIN_OBJECT = $(DEBUG_DIR)/main.o

# Executables
DEBUG_TARGET = $(DEBUG_DIR)/my_tests_debug
RELEASE_TARGET = $(RELEASE_DIR)/my_tests

# CppUnit detection
CPPUNIT_CFLAGS = $(shell pkg-config --cflags cppunit 2>/dev/null)
CPPUNIT_LIBS = $(shell pkg-config --libs cppunit 2>/dev/null)

# Fallback to local installation if pkg-config fails
ifeq ($(CPPUNIT_CFLAGS),)
    CPPUNIT_ROOT = $(HOME)/cppunit-local
    CPPUNIT_CFLAGS = -I$(CPPUNIT_ROOT)/include
    CPPUNIT_LIBS = -L$(CPPUNIT_ROOT)/lib -lcppunit
endif

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(TEST_DIR) $(CPPUNIT_CFLAGS)

# Default target
.PHONY: all
all: release

# Debug build
.PHONY: debug
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJECTS) $(TEST_OBJECTS) $(MAIN_OBJECT)
	@echo "🔨 Building debug executable..."
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(DEBUG_FLAGS) -o $@ $^ $(CPPUNIT_LIBS)
	@echo "✅ Debug build complete: $@"

# Release build
.PHONY: release
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJECTS) $(TEST_OBJECTS) $(MAIN_OBJECT)
	@echo "🔨 Building release executable..."
	@mkdir -p $(RELEASE_DIR)
	$(CXX) $(RELEASE_FLAGS) -o $@ $^ $(CPPUNIT_LIBS)
	@echo "✅ Release build complete: $@"

# Compile source objects
$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(RELEASE_DIR)
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) $(INCLUDES) -c $< -o $@

# Compile test objects
$(DEBUG_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

# Compile main object
$(MAIN_OBJECT): $(MAIN_SOURCE)
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

# Run tests
.PHONY: run
run: release
	@echo "🚀 Running tests..."
	$(RELEASE_TARGET)

.PHONY: run-debug
run-debug: debug
	@echo "🐛 Running debug tests..."
	$(DEBUG_TARGET)

# Check CppUnit installation
.PHONY: check-cppunit
check-cppunit:
	@echo "🔍 Checking CppUnit installation..."
	@if pkg-config --exists cppunit; then \
		echo "✅ CppUnit found via pkg-config"; \
		echo "   CFLAGS: $(shell pkg-config --cflags cppunit)"; \
		echo "   LIBS: $(shell pkg-config --libs cppunit)"; \
	elif [ -d "$(HOME)/cppunit-local" ]; then \
		echo "✅ CppUnit found in local installation"; \
		echo "   Path: $(HOME)/cppunit-local"; \
	else \
		echo "❌ CppUnit not found!"; \
		echo "   Please install CppUnit or run 'make install-cppunit'"; \
		exit 1; \
	fi

# Install CppUnit locally
.PHONY: install-cppunit
install-cppunit:
	@echo "📦 Installing CppUnit locally..."
	@if [ ! -f "cppunit-1.15.1.tar.gz" ]; then \
		wget https://sourceforge.net/projects/cppunit/files/cppunit/1.15.1/cppunit-1.15.1.tar.gz; \
	fi
	tar -xzf cppunit-1.15.1.tar.gz
	cd cppunit-1.15.1 && \
	./configure --prefix=$(HOME)/cppunit-local CXXFLAGS="-std=c++98" && \
	make && make install
	@echo "✅ CppUnit installation complete"

# Clean targets
.PHONY: clean
clean:
	@echo "🧹 Cleaning object files..."
	rm -rf $(BUILD_DIR)
	@echo "✅ Clean complete"

.PHONY: fclean
fclean: clean
	@echo "🧹 Full clean..."
	rm -rf $(BUILD_DIR)
	@echo "✅ Full clean complete"

.PHONY: re
re: fclean all

# Help target
.PHONY: help
help:
	@echo "📋 Available targets:"
	@echo "  all          - Build release (default)"
	@echo "  debug        - Build with debug symbols"
	@echo "  release      - Build optimized release"
	@echo "  run          - Compile and run tests"
	@echo "  run-debug    - Compile debug and run tests"
	@echo "  check-cppunit- Verify CppUnit installation"
	@echo "  install-cppunit - Install CppUnit locally"
	@echo "  clean        - Remove object files"
	@echo "  fclean       - Remove all build files"
	@echo "  re           - Full rebuild"
	@echo "  help         - Show this help"

# Dependencies
-include $(DEBUG_OBJECTS:.o=.d)
-include $(RELEASE_OBJECTS:.o=.d)
-include $(TEST_OBJECTS:.o=.d)
-include $(MAIN_OBJECT:.o=.d)
```

### Available Makefile Targets

```bash
make              # Build release (default)
make debug        # Build with debug symbols
make release      # Build optimized release
make run          # Compile and run tests
make run-debug    # Compile debug and run tests
make check-cppunit # Verify CppUnit installation
make install-cppunit # Install CppUnit locally
make clean        # Remove object files
make fclean       # Remove all build files
make re           # Full rebuild
make help         # Show help
```

### Makefile Features

- **Separate Builds**: Release and Debug configurations
- **Automatic Detection**: CppUnit via pkg-config or local installation
- **C++98 Compliance**: `-std=c++98 -pedantic` flags
- **Visual Feedback**: Informative messages during compilation
- **Dependency Checking**: Automatic CppUnit verification
- **Flexible Structure**: Easy to adapt for different projects

---

## 🎯 Best Practices

### 1. Test Organization

```cpp
// Group related tests logically
CPPUNIT_TEST_SUITE(CalculatorTest);
CPPUNIT_TEST(testAddWithPositiveNumbers);
CPPUNIT_TEST(testAddWithNegativeNumbers);
CPPUNIT_TEST(testAddWithZero);
CPPUNIT_TEST(testSubtractWithValidInput);
CPPUNIT_TEST(testSubtractWithInvalidInput);
CPPUNIT_TEST(testEdgeCases);
CPPUNIT_TEST_SUITE_END();
```

### 2. Descriptive Test Names

```cpp
// ❌ Bad - unclear purpose
void test1();
void test2();
void testCalc();

// ✅ Good - clear and descriptive
void testAdditionWithPositiveNumbers();
void testDivisionByZeroThrowsException();
void testStringListAddIncreasesSize();
void testFileManagerCreateFileReturnsTrue();
```

### 3. Single Responsibility Principle

```cpp
// ❌ Bad - multiple responsibilities in one test
void testCalculator() {
    CPPUNIT_ASSERT_EQUAL(5, calc.add(2, 3));
    CPPUNIT_ASSERT_EQUAL(6, calc.multiply(2, 3));
    CPPUNIT_ASSERT(calc.isEven(4));
    CPPUNIT_ASSERT_THROW(calc.divide(5, 0), std::runtime_error);
}

// ✅ Good - separate tests for each responsibility
void testAddition() { /* only addition logic */ }
void testMultiplication() { /* only multiplication logic */ }
void testIsEven() { /* only even/odd logic */ }
void testDivisionByZero() { /* only exception handling */ }
```

### 4. Proper setUp() and tearDown()

```cpp
void MyTest::setUp() {
    // Initialize common resources
    data = new int[100];
    initializeTestData();
    fileManager = new FileManager();
    testFileName = generateUniqueFileName();
}

void MyTest::tearDown() {
    // Clean up resources
    delete[] data;
    data = NULL;
    
    if (fileManager->fileExists(testFileName)) {
        fileManager->deleteFile(testFileName);
    }
    delete fileManager;
    fileManager = NULL;
}
```

### 5. Memory Management in C++98

```cpp
// Always use new/delete in pairs
void MyTest::testMemoryManagement() {
    int* ptr = new int(42);
    CPPUNIT_ASSERT_EQUAL(42, *ptr);
    delete ptr;  // Important!
    ptr = NULL;  // Prevent dangling pointer access
}

// For arrays
void MyTest::testArrayMemoryManagement() {
    int* arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i * i;
    }
    CPPUNIT_ASSERT_EQUAL(81, arr[9]);
    delete[] arr;  // Use delete[] for arrays
    arr = NULL;
}
```

### 6. Test Data Management

```cpp
class MyTest : public CppUnit::TestCase {
private:
    // Use meaningful names for test data
    static const int VALID_INPUT_VALUE = 42;
    static const int INVALID_INPUT_VALUE = -1;
    static const std::string TEST_FILENAME;
    static const std::string EXPECTED_OUTPUT;
    
    // Test objects
    Calculator* calculator;
    FileManager* fileManager;
    
    // Helper methods
    std::string generateUniqueFileName();
    void createTestFile(const std::string& content);
    void cleanupTestFiles();
};

// Initialize static members
const std::string MyTest::TEST_FILENAME = "test_file.txt";
const std::string MyTest::EXPECTED_OUTPUT = "Expected result";
```

### 7. Exception Testing Best Practices

```cpp
void MyTest::testExceptionHandling() {
    // Test specific exception types
    CPPUNIT_ASSERT_THROW(
        calculator->divide(5, 0), 
        std::runtime_error
    );
    
    // Test exception messages
    try {
        calculator->divide(5, 0);
        CPPUNIT_FAIL("Expected exception was not thrown");
    } catch (const std::runtime_error& e) {
        CPPUNIT_ASSERT_EQUAL(
            std::string("Division by zero"), 
            std::string(e.what())
        );
    }
    
    // Test that no exception is thrown
    CPPUNIT_ASSERT_NO_THROW(calculator->add(2, 3));
}
```

---

## 🧩 Testing Patterns

### 1. Parameterized Tests

```cpp
class ParameterizedTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(ParameterizedTest);
    CPPUNIT_TEST(testMultipleInputs);
    CPPUNIT_TEST_SUITE_END();

public:
    void testMultipleInputs() {
        struct TestCase {
            int input;
            int expected;
        };
        
        TestCase testCases[] = {
            {0, 0}, {1, 1}, {2, 4}, {3, 9}, {4, 16}, {5, 25}
        };
        
        for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
            int result = calculator->square(testCases[i].input);
            CPPUNIT_ASSERT_EQUAL(testCases[i].expected, result);
        }
    }
};
```

### 2. Mock Objects (Simple Implementation)

```cpp
// MockFileSystem.hpp
class MockFileSystem {
public:
    MockFileSystem() : fileExists(false), fileSize(0) {}
    
    bool createFile(const std::string& filename) {
        files[filename] = "";
        return true;
    }
    
    bool fileExists(const std::string& filename) const {
        return files.find(filename) != files.end();
    }
    
    std::string readFile(const std::string& filename) const {
        std::map<std::string, std::string>::const_iterator it = files.find(filename);
        return (it != files.end()) ? it->second : "";
    }
    
    void setFileExists(bool exists) { fileExists = exists; }
    void setFileSize(size_t size) { fileSize = size; }
    
private:
    std::map<std::string, std::string> files;
    bool fileExists;
    size_t fileSize;
};

// FileManagerTest with Mock
class FileManagerTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(FileManagerTest);
    CPPUNIT_TEST(testWithMockFileSystem);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {
        mockFileSystem = new MockFileSystem();
        fileManager = new FileManager(mockFileSystem);
    }
    
    void tearDown() {
        delete fileManager;
        delete mockFileSystem;
    }
    
    void testWithMockFileSystem() {
        mockFileSystem->setFileExists(true);
        CPPUNIT_ASSERT(fileManager->fileExists("test.txt"));
        
        mockFileSystem->setFileExists(false);
        CPPUNIT_ASSERT(!fileManager->fileExists("test.txt"));
    }

private:
    FileManager* fileManager;
    MockFileSystem* mockFileSystem;
};
```

### 3. Test Fixtures

```cpp
// Base test fixture for common setup
class BaseTestFixture : public CppUnit::TestCase {
protected:
    void setUp() {
        calculator = new Calculator();
        fileManager = new FileManager();
        testData = initializeTestData();
    }
    
    void tearDown() {
        delete calculator;
        delete fileManager;
        cleanupTestData();
    }
    
protected:
    Calculator* calculator;
    FileManager* fileManager;
    TestData* testData;
};

// Specific test classes inherit from fixture
class CalculatorTest : public BaseTestFixture {
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAddition() {
        CPPUNIT_ASSERT_EQUAL(5, calculator->add(2, 3));
    }
};
```

### 4. Performance Testing

```cpp
class PerformanceTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(PerformanceTest);
    CPPUNIT_TEST(testSortingPerformance);
    CPPUNIT_TEST_SUITE_END();

public:
    void testSortingPerformance() {
        const int ARRAY_SIZE = 10000;
        int* testArray = new int[ARRAY_SIZE];
        
        // Initialize with random data
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            testArray[i] = rand() % 1000;
        }
        
        // Measure sorting time
        clock_t start = clock();
        sortArray(testArray, ARRAY_SIZE);
        clock_t end = clock();
        
        double cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // Performance assertion (adjust threshold as needed)
        CPPUNIT_ASSERT(cpuTime < 1.0); // Should complete in less than 1 second
        
        // Verify correctness
        for (int i = 1; i < ARRAY_SIZE; ++i) {
            CPPUNIT_ASSERT(testArray[i-1] <= testArray[i]);
        }
        
        delete[] testArray;
    }
};
```

---

## 🔍 Assertions Reference

### Basic Assertions

```cpp
// Simple boolean assertion
CPPUNIT_ASSERT(condition);                    // Verify condition is true
CPPUNIT_ASSERT_MESSAGE(message, condition);   // With custom message

// Examples
CPPUNIT_ASSERT(x > 0);
CPPUNIT_ASSERT_MESSAGE("Value should be positive", x > 0);
```

### Equality Assertions

```cpp
// Equality for basic types
CPPUNIT_ASSERT_EQUAL(expected, actual);       // For basic types
CPPUNIT_ASSERT_EQUAL_MESSAGE(msg, exp, act);  // With message

// Examples
CPPUNIT_ASSERT_EQUAL(5, result);
CPPUNIT_ASSERT_EQUAL(std::string("Hello"), str);
CPPUNIT_ASSERT_EQUAL_MESSAGE("Addition failed", 7, calc.add(3, 4));
```

### Exception Assertions

```cpp
// Exception testing
CPPUNIT_ASSERT_THROW(statement, ExceptionType);     // Must throw exception
CPPUNIT_ASSERT_NO_THROW(statement);                 // Must not throw exception
CPPUNIT_ASSERT_THROW_MESSAGE(msg, stmt, exc);      // With message

// Examples
CPPUNIT_ASSERT_THROW(throw std::runtime_error("test"), std::runtime_error);
CPPUNIT_ASSERT_NO_THROW(int x = 5);
CPPUNIT_ASSERT_THROW_MESSAGE("Should throw on division by zero", 
                             calc.divide(5, 0), std::runtime_error);
```

### Floating Point Assertions

```cpp
// For floating point comparisons
CPPUNIT_ASSERT_DOUBLES_EQUAL(expected, actual, delta);
CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(msg, exp, act, delta);

// Examples
CPPUNIT_ASSERT_DOUBLES_EQUAL(3.14159, pi, 0.0001);
CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Square root calculation", 
                                    2.0, sqrt(4.0), 0.001);
```

### String Assertions

```cpp
// String-specific assertions
CPPUNIT_ASSERT_EQUAL(std::string("expected"), actualString);
CPPUNIT_ASSERT(actualString.find("substring") != std::string::npos);

// Examples
std::string result = processString("Hello World");
CPPUNIT_ASSERT_EQUAL(std::string("HELLO WORLD"), result);
CPPUNIT_ASSERT(result.find("WORLD") != std::string::npos);
```

### Custom Assertions

```cpp
// Create custom assertion macros
#define CPPUNIT_ASSERT_IN_RANGE(value, min, max) \
    CPPUNIT_ASSERT_MESSAGE("Value " + std::to_string(value) + " not in range [" + \
                          std::to_string(min) + ", " + std::to_string(max) + "]", \
                          (value) >= (min) && (value) <= (max))

// Usage
CPPUNIT_ASSERT_IN_RANGE(result, 0, 100);
```

---

## 🐛 Troubleshooting

### Common Installation Issues

#### Problem: "cppunit: command not found"

**Solution**: Verify installation
```bash
make check-cppunit
```

If not found, install locally:
```bash
make install-cppunit
```

#### Problem: "Package 'cppunit' not found"

**Solution**: Install development package
```bash
# Ubuntu/Debian
sudo apt-get install libcppunit-dev

# CentOS/RHEL
sudo yum install cppunit-devel
```

#### Problem: Library linking errors

**Solution**: Check library paths
```bash
# Add to ~/.bashrc
export LD_LIBRARY_PATH=$HOME/cppunit-local/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=$HOME/cppunit-local/lib/pkgconfig:$PKG_CONFIG_PATH
```

### Compilation Issues

#### Problem: C++98 compilation errors

**Solution**: Verify compiler flags
```bash
# In Makefile should be:
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
```

#### Problem: "undefined reference to CppUnit::"

**Solution**: Link CppUnit library
```bash
# Add to Makefile:
CPPUNIT_LIBS = -lcppunit
# Or with pkg-config:
CPPUNIT_LIBS = $(shell pkg-config --libs cppunit)
```

#### Problem: Header not found

**Solution**: Check include paths
```bash
# Add to Makefile:
CPPUNIT_CFLAGS = $(shell pkg-config --cflags cppunit)
INCLUDES = $(CPPUNIT_CFLAGS)
```

### Runtime Issues

#### Problem: Tests don't run

**Solution**: Verify test suite registration
```cpp
// In main.cpp
runner.addTest(MyTest::suite());
```

#### Problem: "No tests found"

**Solution**: Check test suite declaration
```cpp
// In test class header
CPPUNIT_TEST_SUITE(MyTest);
CPPUNIT_TEST(testMethod);
CPPUNIT_TEST_SUITE_END();
```

#### Problem: Segmentation fault in tests

**Solution**: Check memory management
```cpp
// Ensure proper cleanup in tearDown()
void MyTest::tearDown() {
    delete testObject;
    testObject = NULL;  // Prevent dangling pointer access
}
```

### Debugging Tips

#### Enable Debug Output

```cpp
// Add debug output to tests
void MyTest::testMethod() {
    std::cout << "Debug: Testing with value " << testValue << std::endl;
    CPPUNIT_ASSERT_EQUAL(expected, actual);
}
```

#### Use GDB for Debugging

```bash
# Compile with debug symbols
make debug

# Run with gdb
gdb ./my_tests_debug
(gdb) run
(gdb) bt  # Show backtrace on crash
```

#### Memory Leak Detection

```bash
# Use valgrind for memory leak detection
valgrind --leak-check=full ./my_tests_debug
```

---

## 🚀 Useful Commands

### Daily Development

```bash
# Quick test cycle
make run

# Debug build and run
make debug
make run-debug

# Verify everything is working
make check-cppunit

# Full rebuild
make re
```

### Testing Workflow

```bash
# 1. Write test
vim tests/MyTest.cpp

# 2. Compile and run
make run

# 3. Fix implementation
vim src/MyClass.cpp

# 4. Repeat
make run
```

### Debugging Workflow

```bash
# 1. Compile with debug symbols
make debug

# 2. Run with debugger
gdb ./my_tests_debug
(gdb) break MyTest::testMethod
(gdb) run

# 3. Analyze core dumps
gdb ./my_tests_debug core
(gdb) bt
```

### Performance Analysis

```bash
# Profile with gprof
make debug CXXFLAGS="-pg"
./my_tests_debug
gprof ./my_tests_debug gmon.out > profile.txt

# Memory profiling with valgrind
valgrind --tool=memcheck --leak-check=full ./my_tests_debug
```

### Cleanup Commands

```bash
# Remove build artifacts
make clean

# Remove everything and rebuild
make fclean
make

# Remove CppUnit installation
rm -rf ~/cppunit-local
```

---

## 📚 Additional Resources

### Official Documentation

- [CppUnit Official Documentation](http://cppunit.sourceforge.net/)
- [CppUnit API Reference](http://cppunit.sourceforge.net/doc/cvs/)
- [CppUnit Tutorial](http://cppunit.sourceforge.net/doc/cvs/cppunit_cookbook.html)

### C++98 Resources

- [C++98 Standard Reference](https://en.cppreference.com/w/cpp/98)
- [C++98 Compatibility Guide](https://gcc.gnu.org/onlinedocs/gcc-4.8.5/gcc/C_002b_002b-Extensions.html)

### Testing Best Practices

- [Unit Testing Best Practices](https://github.com/goldbergyoni/javascript-testing-best-practices)
- [Test-Driven Development](https://en.wikipedia.org/wiki/Test-driven_development)
- [C++ Testing Patterns](https://www.artima.com/weblogs/viewpost.jsp?thread=12671)

### Build Tools

- [Make Tutorial](https://makefiletutorial.com/)
- [CMake Documentation](https://cmake.org/documentation/)
- [pkg-config Guide](https://people.freedesktop.org/~dbn/pkg-config-guide.html)

### Debugging Tools

- [GDB Tutorial](https://www.gnu.org/software/gdb/documentation/)
- [Valgrind User Manual](https://valgrind.org/docs/manual/manual.html)
- [GProf Profiling](https://sourceware.org/binutils/docs/gprof/)

---

## 🎉 Congratulations!

You now have everything you need to master unit testing in C++98 using CppUnit!

### Next Steps

1. **Run your first test**: Execute `make run` to see your first test working
2. **Experiment with assertions**: Try different types of assertions in your tests
3. **Create tests for your classes**: Start testing your own code
4. **Explore debug mode**: Use `make debug` for debugging
5. **Implement test patterns**: Apply the testing patterns shown in this guide
6. **Set up CI/CD**: Integrate tests into your build pipeline

### Pro Tips

- **Start small**: Begin with simple tests and gradually add complexity
- **Test early and often**: Write tests as you develop, not after
- **Keep tests independent**: Each test should be able to run in isolation
- **Use descriptive names**: Make test names self-documenting
- **Maintain test hygiene**: Keep tests clean and well-organized

Happy Testing! 🧪✨

---

*This guide is part of the C++98 OOP project documentation. For questions or contributions, please refer to the project repository.*