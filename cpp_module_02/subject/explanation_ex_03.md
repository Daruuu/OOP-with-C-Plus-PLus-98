---

### Capítulo VII

**Ejercicio 03: BSP**

**Entrega**

* Directorio: `ex03/`
* Archivos a entregar: `Makefile`, `main.cpp`, `Fixed.{h, hpp}`, `Fixed.cpp`, `Point.{h, hpp}`, `Point.cpp`, `bsp.cpp`

* Funciones permitidas: `roundf` (de `<cmath>`)

Ahora que tienes una clase `Fixed` funcional, sería bueno usarla.
Implementa una función que indique si un punto está **dentro de un triángulo** o no.
Muy útil, ¿verdad?

**BSP** significa *Binary Space Partitioning*. De nada. :)

Puedes aprobar este módulo sin completar el ejercicio 03.

---

**C++ - Módulo 02**
*Polimorfismo ad-hoc, sobrecarga de operadores
y la forma canónica ortodoxa de clase*

Comencemos creando la clase **Point** en **Forma Canónica Ortodoxa** que represente un punto 2D:

* **Miembros privados:**

    * Un atributo constante `x` de tipo `Fixed`.
    * Un atributo constante `y` de tipo `Fixed`.
    * Cualquier otra cosa útil.

* **Miembros públicos:**

    * Un constructor por defecto que inicialice `x` e `y` a `0`.
    * Un constructor que reciba dos números de coma flotante constantes como parámetros y que inicialice `x` e `y` con dichos valores.
    * Un constructor de copia.
    * Una sobrecarga del operador de asignación por copia.
    * Un destructor.
    * Cualquier otra cosa útil.

---

Para concluir, implementa la siguiente función en el archivo correspondiente:

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

* **a, b, c:** Los vértices de nuestro querido triángulo.
* **point:** El punto a comprobar.
* **Devuelve:** `true` si el punto está dentro del triángulo, `false` en caso contrario.

**Nota:** Si el punto es un vértice o está sobre un lado del triángulo, deberá devolver `false`.
