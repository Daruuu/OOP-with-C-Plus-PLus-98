# 🧩 CPP06 - ex02: Identify Real Type

---

## PARTE TEÓRICA

### Objetivo general
El objetivo de este ejercicio es **aprender a identificar el tipo real de un objeto polimórfico en tiempo de ejecución** sin usar `typeid` ni `std::typeinfo`.  
Para ello se utiliza el operador `dynamic_cast`, que forma parte del sistema de **RTTI (Run-Time Type Information)** de C++.

---

### 🔹 1. Polimorfismo y herencia

Cuando una clase tiene al menos una función virtual (por ejemplo, un destructor virtual), se activa el **mecanismo RTTI**, 
<br>que permite conocer en tiempo de ejecución el tipo real del objeto al que apunta un puntero o referencia de tipo base.

Ejemplo:
```cpp
class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
```

Con esto, si tenemos:

```cpp
Base* ptr = new A();
```

El compilador sabe en tiempo de ejecución que `ptr` apunta realmente a un objeto de tipo `A`.

---

### 🔹 2. `dynamic_cast`

`dynamic_cast` se utiliza para convertir punteros o referencias dentro de una jerarquía de herencia polimórfica.

#### Para punteros:

```cpp
A* a = dynamic_cast<A*>(ptr);
```

* Si `ptr` **apunta realmente** a un objeto `A`, `a` será un puntero válido.
* Si no, `a` será `nullptr`.

#### Para referencias:

```cpp
try {
    A& a = dynamic_cast<A&>(ref);
    std::cout << "Es un A";
} catch (std::bad_cast& e) {
    std::cout << "No es un A";
}
```

* Si el cast falla, lanza una **excepción `std::bad_cast`**.

---

### 🔹 3. Destructor virtual

El **destructor virtual** en la clase base es esencial para que `dynamic_cast` funcione correctamente y para evitar fugas de memoria al eliminar objetos derivados.

```cpp
class Base {
public:
    virtual ~Base() {} // Activa el RTTI y garantiza destrucción correcta
};
```

---

### 🔹 4. RTTI (Run-Time Type Information)

El RTTI permite que el programa:

* Sepa en tiempo de ejecución el tipo dinámico del objeto.
* Permita conversiones seguras dentro de jerarquías polimórficas.
* Sea más flexible y menos propenso a errores de tipo.

---

## ⚙️ PARTE PRÁCTICA

### 🧩 Descripción del ejercicio

Debes implementar un sistema que:

1. Genere aleatoriamente objetos de tipo `A`, `B` o `C` (todas derivadas de `Base`).
2. Identifique en tiempo de ejecución cuál es el tipo real del objeto (A, B o C).
3. Lo haga tanto desde un **puntero** como desde una **referencia** a `Base`.

---

### 📂 Estructura del proyecto

```
ex02/
├── Base.hpp
├── A.hpp
├── B.hpp
├── C.hpp
├── functions.cpp     // Implementa generate() e identify()
├── main.cpp          // Programa de prueba
└── Makefile
```

---

### 🧱 Clases

```cpp
// Base.hpp
class Base {
public:
    virtual ~Base(); // Destructor virtual obligatorio
};
```

```cpp
// A.hpp, B.hpp, C.hpp
class A : public Base {};
class B : public Base {};
class C : public Base {};
```

---

### ⚙️ Funciones principales

#### `Base* generate(void);`

Crea aleatoriamente una instancia de `A`, `B` o `C`.

```cpp
Base* generate() {
    int random = std::rand() % 3;
    if (random == 0) return new A();
    if (random == 1) return new B();
    return new C();
}
```

#### `void identify(Base* p);`

Identifica el tipo real usando un **puntero**:

```cpp
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A";
    else if (dynamic_cast<B*>(p)) std::cout << "B";
    else if (dynamic_cast<C*>(p)) std::cout << "C";
    else std::cout << "Unknown";
}
```

#### `void identify(Base& p);`

Identifica el tipo real usando una **referencia**:

```cpp
void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A"; return; } catch(...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B"; return; } catch(...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C"; return; } catch(...) {}
    std::cout << "Unknown";
}
```

---

### 🧪 Casos de prueba (`main.cpp`)

#### 1️⃣ Random tests

Prueba con objetos generados aleatoriamente:

```cpp
randomCases(5);
```

#### 2️⃣ Manual tests

Prueba objetos creados manualmente:

```cpp
manualTestWithThreeBaseObjects();
```

#### 3️⃣ Edge cases

Comprueba el comportamiento con punteros nulos:

```cpp
edgeCase();
```

---

### 🧾 Ejemplo de salida

```
===== RANDOM TESTS =====
=== Test 1 ===
Pointer version: A
Reference version: A

=== Test 2 ===
Pointer version: C
Reference version: C

===== MANUAL TESTS =====
[TEST A]
Pointer version: A
Reference version: A

[TEST B]
Pointer version: B
Reference version: B

[TEST C]
Pointer version: C
Reference version: C

===== EDGE CASES =====
Null pointer test: Unknown
```

---

## 🧩 Conclusiones

### ✅ Qué se aprende

* Cómo usar `dynamic_cast` de forma segura.
* Cómo funciona el RTTI en C++.
* Diferencias entre conversión con punteros y referencias.
* Importancia del destructor virtual en jerarquías polimórficas.

### 🚫 Qué no se puede usar

* No se permite incluir `<typeinfo>`.
* No se puede usar `typeid`.

---

## 🧰 Compilación y ejecución

```bash
make
./identify
```

Para limpiar:

```bash
make clean
make fclean
```

---

✍️ *Autor: DaruuuSC*
💻 *CPP Module 06 - ex02 — Identify Real Type*

```

---

¿Quieres que te agregue un **diagrama visual UML** (en ASCII o Markdown) mostrando la jerarquía `Base → A/B/C` dentro de la parte teórica?  
Ayuda mucho para entender la herencia al repasar.
```
