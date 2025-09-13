# 🧪 Primeros Pasos con CppUnit en C++98

Esta guía te ayudará a comenzar con el testing unitario usando CppUnit en proyectos C++98.

## 📋 Tabla de Contenidos

1. [Instalación](#instalación)
2. [Configuración del Proyecto](#configuración-del-proyecto)
3. [Estructura Básica](#estructura-básica)
4. [Ejemplos Prácticos](#ejemplos-prácticos)
5. [Makefile Avanzado](#makefile-avanzado)
6. [Mejores Prácticas](#mejores-prácticas)
7. [Comandos Útiles](#comandos-útiles)

---

## 🔧 Instalación

### Opción 1: Instalación Local (Recomendada para C++98)

```bash
# Descargar CppUnit
wget https://sourceforge.net/projects/cppunit/files/cppunit/1.15.1/cppunit-1.15.1.tar.gz
tar -xzf cppunit-1.15.1.tar.gz
cd cppunit-1.15.1

# Configurar para C++98
./configure --prefix=$HOME/cppunit-local CXXFLAGS="-std=c++98"

# Compilar e instalar
make
make install
```

### Opción 2: Usando pkg-config (si está disponible)

```bash
# Ubuntu/Debian
sudo apt-get install libcppunit-dev

# CentOS/RHEL
sudo yum install cppunit-devel
```

---

## ⚙️ Configuración del Proyecto

### Estructura de Directorios

```
tu_proyecto/
├── Makefile
├── main.cpp
├── Testing.hpp
├── Testing.cpp
└── README_CppUnit_Cpp98.md
```

### Verificar Instalación

```bash
make check-cppunit
```

---

## 🏗️ Estructura Básica

### 1. Archivo de Cabecera (`Testing.hpp`)

```cpp
#ifndef TESTING_HPP
#define TESTING_HPP

#include <cppunit/extensions/HelperMacros.h>

class MyTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(MyTest);
    CPPUNIT_TEST(testBasicAddition);
    CPPUNIT_TEST(testStringOperations);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();        // Se ejecuta antes de cada test
    void tearDown();     // Se ejecuta después de cada test
    
    // Métodos de test
    void testBasicAddition();
    void testStringOperations();
};

#endif // TESTING_HPP
```

### 2. Implementación (`Testing.cpp`)

```cpp
#include "Testing.hpp"

void MyTest::setUp() {
    // Inicialización común para todos los tests
}

void MyTest::tearDown() {
    // Limpieza después de cada test
}

void MyTest::testBasicAddition() {
    int result = 2 + 2;
    CPPUNIT_ASSERT(result == 4);
    CPPUNIT_ASSERT_EQUAL(4, result);
}

void MyTest::testStringOperations() {
    std::string str = "Hello";
    CPPUNIT_ASSERT(str.length() == 5);
    CPPUNIT_ASSERT_EQUAL(std::string("Hello"), str);
}
```

### 3. Punto de Entrada (`main.cpp`)

```cpp
#include <cppunit/ui/text/TestRunner.h>
#include "Testing.hpp"

int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(MyTest::suite());
    
    bool success = runner.run();
    return success ? 0 : 1;
}
```

---

## 💡 Ejemplos Prácticos

### Ejemplo 1: Testing de Clases Simples

```cpp
// Calculator.hpp
class Calculator {
public:
    int add(int a, int b);
    int multiply(int a, int b);
    bool isEven(int number);
};

// CalculatorTest.hpp
class CalculatorTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testIsEven);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    
    void testAdd();
    void testMultiply();
    void testIsEven();

private:
    Calculator* calculator;
};

// CalculatorTest.cpp
void CalculatorTest::setUp() {
    calculator = new Calculator();
}

void CalculatorTest::tearDown() {
    delete calculator;
}

void CalculatorTest::testAdd() {
    CPPUNIT_ASSERT_EQUAL(5, calculator->add(2, 3));
    CPPUNIT_ASSERT_EQUAL(0, calculator->add(-5, 5));
}

void CalculatorTest::testMultiply() {
    CPPUNIT_ASSERT_EQUAL(6, calculator->multiply(2, 3));
    CPPUNIT_ASSERT_EQUAL(0, calculator->multiply(0, 100));
}

void CalculatorTest::testIsEven() {
    CPPUNIT_ASSERT(calculator->isEven(4));
    CPPUNIT_ASSERT(!calculator->isEven(3));
}
```

### Ejemplo 2: Testing de Manejo de Errores

```cpp
void MyTest::testExceptionHandling() {
    // Verificar que se lance una excepción
    CPPUNIT_ASSERT_THROW(throw std::runtime_error("test"), std::runtime_error);
    
    // Verificar que NO se lance una excepción
    CPPUNIT_ASSERT_NO_THROW(int x = 5);
}
```

### Ejemplo 3: Testing de Arrays y Contenedores

```cpp
void MyTest::testArrayOperations() {
    int arr[] = {1, 2, 3, 4, 5};
    
    CPPUNIT_ASSERT_EQUAL(5, sizeof(arr) / sizeof(arr[0]));
    CPPUNIT_ASSERT_EQUAL(1, arr[0]);
    CPPUNIT_ASSERT_EQUAL(5, arr[4]);
}
```

---

## 🔨 Makefile Avanzado

Tu Makefile mejorado incluye las siguientes características:

### Targets Disponibles

```bash
make              # Build release (por defecto)
make debug        # Build con símbolos de debug
make run          # Compila y ejecuta tests
make run-debug    # Compila debug y ejecuta tests
make check-cppunit # Verifica instalación de CppUnit
make clean        # Limpia archivos objeto
make fclean       # Limpia todo
make re           # Rebuild completo
make help         # Muestra ayuda
```

### Características del Makefile

- **Builds separados**: Release y Debug
- **Detección automática**: CppUnit via pkg-config o instalación local
- **Flags C++98**: `-std=c++98 -pedantic`
- **Información visual**: Mensajes durante compilación
- **Verificación de dependencias**: Check automático de CppUnit

---

## 🎯 Mejores Prácticas

### 1. Organización de Tests

```cpp
// Agrupa tests relacionados
CPPUNIT_TEST_SUITE(MyTest);
CPPUNIT_TEST(testValidInput);
CPPUNIT_TEST(testInvalidInput);
CPPUNIT_TEST(testEdgeCases);
CPPUNIT_TEST_SUITE_END();
```

### 2. Nombres Descriptivos

```cpp
// ❌ Malo
void test1();

// ✅ Bueno
void testAdditionWithPositiveNumbers();
void testDivisionByZeroThrowsException();
```

### 3. Un Test, Una Responsabilidad

```cpp
// ❌ Malo - múltiples verificaciones en un test
void testCalculator() {
    CPPUNIT_ASSERT_EQUAL(5, calc.add(2, 3));
    CPPUNIT_ASSERT_EQUAL(6, calc.multiply(2, 3));
    CPPUNIT_ASSERT(calc.isEven(4));
}

// ✅ Bueno - tests separados
void testAddition() { /* solo suma */ }
void testMultiplication() { /* solo multiplicación */ }
void testIsEven() { /* solo verificación par/impar */ }
```

### 4. setUp() y tearDown()

```cpp
void MyTest::setUp() {
    // Inicializar recursos comunes
    data = new int[100];
    initializeTestData();
}

void MyTest::tearDown() {
    // Limpiar recursos
    delete[] data;
    data = NULL;
}
```

### 5. Manejo de Memoria en C++98

```cpp
// Siempre usar new/delete en pares
void MyTest::testMemoryManagement() {
    int* ptr = new int(42);
    CPPUNIT_ASSERT_EQUAL(42, *ptr);
    delete ptr;  // ¡Importante!
}
```

---

## 🚀 Comandos Útiles

### Desarrollo Diario

```bash
# Compilar y ejecutar tests
make run

# Compilar en modo debug para debugging
make debug
make run-debug

# Verificar que todo esté bien
make check-cppunit
```

### Debugging

```bash
# Compilar con símbolos de debug
make debug

# Ejecutar con gdb
gdb ./my_tests_debug
(gdb) run
```

### Limpieza

```bash
# Limpiar archivos temporales
make clean

# Limpiar todo y recompilar
make re
```

---

## 🔍 Assertions Disponibles

### Assertions Básicas

```cpp
CPPUNIT_ASSERT(condition);                    // Verifica que condition sea true
CPPUNIT_ASSERT_MESSAGE(message, condition);  // Con mensaje personalizado
```

### Assertions de Igualdad

```cpp
CPPUNIT_ASSERT_EQUAL(expected, actual);       // Para tipos básicos
CPPUNIT_ASSERT_EQUAL_MESSAGE(msg, exp, act);  // Con mensaje
```

### Assertions de Excepciones

```cpp
CPPUNIT_ASSERT_THROW(statement, ExceptionType);     // Debe lanzar excepción
CPPUNIT_ASSERT_NO_THROW(statement);                  // No debe lanzar excepción
CPPUNIT_ASSERT_THROW_MESSAGE(msg, stmt, exc);       // Con mensaje
```

### Assertions de Aproximación (para floats)

```cpp
CPPUNIT_ASSERT_DOUBLES_EQUAL(expected, actual, delta);
```

---

## 🐛 Troubleshooting

### Problema: "cppunit: command not found"

**Solución**: Verificar instalación
```bash
make check-cppunit
```

### Problema: Errores de compilación C++98

**Solución**: Verificar flags del compilador
```bash
# En el Makefile debe estar:
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
```

### Problema: Tests no se ejecutan

**Solución**: Verificar que el suite esté registrado
```cpp
// En main.cpp
runner.addTest(MyTest::suite());
```

---

## 📚 Recursos Adicionales

- [Documentación Oficial CppUnit](http://cppunit.sourceforge.net/)
- [CppUnit API Reference](http://cppunit.sourceforge.net/doc/cvs/)
- [C++98 Standard](https://en.cppreference.com/w/cpp/98)

---

## 🎉 ¡Felicidades!

Ya tienes todo lo necesario para comenzar con testing unitario en C++98 usando CppUnit. 

**Próximos pasos sugeridos:**
1. Ejecuta `make run` para ver tu primer test funcionando
2. Experimenta con diferentes tipos de assertions
3. Crea tests para tus propias clases
4. Explora el modo debug con `make debug`

¡Happy Testing! 🧪✨
