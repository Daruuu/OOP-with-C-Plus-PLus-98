

La línea:

```cpp
using namespace std;
```

Significa que **le estás diciendo al compilador que vas a usar nombres
del espacio de nombres `std` sin tener que escribir `std::` cada vez**.

---

### ¿Qué es `std`?

En C++, todo lo que está definido en la **biblioteca estándar** (como `cout`, `cin`, `vector`, `string`, etc.) vive dentro del *namespace* `std`. Así, por defecto, para usarlos necesitas escribirlos con su calificador:

```cpp
std::cout << "Hola mundo" << std::endl;
```

---

### ¿Qué hace `using namespace std;`?

Con esa línea le estás diciendo al compilador:

> "Durante el resto de este archivo, cuando se use un nombre sin calificador, búscalo también en el namespace `std`".

Entonces puedes escribir:

```cpp
cout << "Hola mundo" << endl;
```

en lugar de:

```cpp
std::cout << "Hola mundo" << std::endl;
```

---

### ¿Qué dice el *C++ Primer* sobre esto?

En la sección **3.1 (Namespace using Declarations)**, el libro recomienda **usar `std::` explícitamente en archivos reales de código**, y **evitar `using namespace std;` en archivos de cabecera (`.h`) o en proyectos grandes**, porque:

1. **Puede causar conflictos de nombres** si diferentes bibliotecas usan el mismo nombre (por ejemplo, `vector` en `std` y otra en otra lib).
2. **Reduce la claridad del código** (no sabes si `sort` es de `std` o de otro lugar).

Para programas pequeños o ejemplos (como los del libro), usar `using namespace std;` está bien, pero **en producción o proyectos serios se prefiere el uso explícito de `std::`**.

---

### En resumen:

| Con `using namespace std;` | Sin `using namespace std;` |
| -------------------------- | -------------------------- |
| `cout << "Hola";`          | `std::cout << "Hola";`     |
| `vector<int> v;`           | `std::vector<int> v;`      |

---

