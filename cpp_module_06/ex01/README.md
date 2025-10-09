# C++ Module 06 - ex01: Serialization

---

## PARTE 1 - CONCEPTOS CLAVE

Este ejercicio introduce el concepto de **serialización de punteros** en C++:<br>
convertir un **puntero (`Data*`)** en un **entero (`uintptr_t`)** <br>
y luego **reconstruirlo** sin perder la referencia al objeto original.

No se trata de una serialización real (no se guardan los datos del objeto), <br>
sino de un **ejercicio conceptual** diseñado para entender:

* Cómo funcionan los **punteros y direcciones de memoria**.
* Cómo realizar conversiones **seguras y portables** entre tipos.
* Cómo diseñar una **clase no instanciable** con **métodos estáticos**.

---

### 1. `uintptr_t`

Es un tipo entero sin signo capaz de almacenar una dirección de memoria sin pérdida de información.
Definido en `<cstdint>` (o `<stdint.h>`), garantiza compatibilidad entre arquitecturas de 32 y 64 bits.

Ejemplo:

```cpp
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
Data* back = reinterpret_cast<Data*>(raw);
```

---

### 2. `reinterpret_cast`

Permite reinterpretar los bits de un valor como otro tipo **sin modificar su contenido**.
Es el cast más bajo nivel de C++ y debe usarse con precaución.

✅ Se usa cuando:

* Convertimos punteros a enteros (y viceversa).
* Queremos acceder directamente a la representación binaria de una dirección.

No transforma datos, solo **reinterpreta su significado** para el compilador.

---

### 🧱 3. Métodos estáticos

Los métodos estáticos pertenecen a la clase, no a una instancia.
Se invocan sin crear objetos y son ideales para utilidades sin estado:

```cpp
uintptr_t raw = Serializer::serialize(ptr);
```

Son el equivalente orientado a objetos de un **namespace funcional**.

---

### 🚫 4. Clases no instanciables

Para evitar que la clase `Serializer` sea instanciada:

* Se declaran los constructores, destructores y operadores de copia **como privados**.
* No se implementan públicamente.

Esto la convierte en un **contenedor estático puro**, utilizado solo como herramienta.

---

### 🧮 5. Comparación de punteros

Tras serializar y deserializar, el puntero debe seguir apuntando al mismo objeto:

```cpp
deserialize(serialize(ptr)) == ptr; // true ✅
```

Esto prueba que no hubo pérdida ni alteración de la dirección de memoria.

---

### 💬 Qué se aprende

| Concepto                      | Aprendizaje clave                                              |
| ----------------------------- | -------------------------------------------------------------- |
| Punteros y memoria            | Qué representa una dirección y cómo manipularla.               |
| Tipos enteros portables       | Uso de `uintptr_t` para almacenar direcciones de forma segura. |
| Casting avanzado              | Cuándo y cómo usar `reinterpret_cast`.                         |
| Diseño orientado a utilidades | Cómo crear clases estáticas sin instanciación.                 |
| Buenas prácticas              | Separar `.hpp` y `.cpp` y limitar el ámbito de uso.            |

---

### 🚀 Aplicaciones reales

* **Depuración y análisis de memoria**
* **Sistemas de bajo nivel (drivers, SO, networking)**
* **Serialización binaria real**
* **Comunicación entre procesos o hilos**

---

## 💡 Conclusión conceptual

Este ejercicio no busca serializar datos, sino **comprender la representación de memoria y el control de punteros en C++**.
Es un paso esencial antes de abordar:

* Serialización binaria o de red,
* Gestión avanzada de punteros,
* Y programación de sistemas de bajo nivel.

---

## 💻 PARTE 2 — EL PROBLEMA A RESOLVER

---

### 🧩 Descripción del ejercicio

Implementar una clase `Serializer` **no instanciable**, con dos métodos estáticos:

```cpp
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
```

* `serialize()` convierte un puntero en un entero del tipo `uintptr_t`.
* `deserialize()` convierte ese entero de vuelta al puntero original.

El programa debe demostrar que el puntero deserializado apunta al mismo objeto que el original.

---

### 🧱 Estructura del proyecto

```
ex01/
├── Data.hpp
├── Serializer.hpp
├── Serializer.cpp
├── main.cpp
└── Makefile
```

---

### **Data.hpp**

Define una clase simple con miembros básicos:

```cpp
class Data {
	std::string name;
	int value;
};
```

---

### **Serializer.hpp**

Define la clase `Serializer`, diseñada para no poder instanciarse:

```cpp
class Serializer {
private:
	Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
```

---

### **Serializer.cpp**

Implementa las funciones de conversión mediante `reinterpret_cast`:

```cpp
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
```

---

### **main.cpp**

Comprueba que el puntero deserializado apunta al mismo objeto original:

```cpp
Data data = {"example", 42};

uintptr_t raw = Serializer::serialize(&data);
Data* restored = Serializer::deserialize(raw);

std::cout << "Equal pointers: " << (restored == &data ? "true" : "false") << std::endl;
```

---

### ⚙️ Compilación y ejecución

```bash
make
./serializer
```

#### 🔍 Ejemplo de salida

```
=== CASE 1: Basic serialization/deserialization ===
Original ptr: 0x600000e1c010
Deserialized ptr: 0x600000e1c010
Equal pointers: true
Name: base case, Value: 100
```

---

### 🧪 Casos de prueba sugeridos

| Nº  | Caso                   | Descripción                             | Resultado esperado             |
| --- | ---------------------- | --------------------------------------- | ------------------------------ |
| 1️⃣ | Objeto básico (heap)   | Serializa un objeto dinámico.           | Punteros iguales               |
| 2️⃣ | Dos objetos distintos  | Serializa ambos y compara direcciones.  | Direcciones diferentes         |
| 3️⃣ | Puntero `NULL`         | Serializa un puntero nulo.              | Devuelve `NULL`                |
| 4️⃣ | Objeto en stack        | Serializa una variable local.           | Dirección válida mientras viva |
| 5️⃣ | Mutación del objeto    | Cambia datos vía puntero deserializado. | Cambios reflejados             |
| 6️⃣ | Serialización múltiple | Serializa y deserializa varias veces.   | Sin pérdida ni alteración      |

---

¿Quieres que te prepare esta versión en formato **README.md con sintaxis Markdown optimizada (títulos, tablas y colores con emojis)** lista para subir a GitHub o Notion?
Puedo hacerlo en un solo bloque listo para copiar y pegar.
