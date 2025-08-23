
## C++ Project Setup: Dependencies and Build Tools

Dependency management in C++ involves handling external libraries, packages, and dependencies required by a project.  
It includes downloading, installing, and linking libraries in order to build and run C++ programs efficiently and reproducibly.

---

### 🔹 Package Managers
Package managers simplify the installation and management of third-party libraries. They allow you to integrate external code without manually handling downloads and build steps.

- **vcpkg**  
  A cross-platform package manager developed by Microsoft.  
  Useful for quickly installing popular libraries (Boost, fmt, OpenCV, etc.) and integrating them with Visual Studio, CMake, or other build systems.  

  ```bash
  # Example: installing fmt with vcpkg
  ./vcpkg install fmt
    ```

* **Conan**
  A decentralized package manager for C and C++.
  Provides dependency versioning, cross-compilation support, and integration with multiple build systems.

  ```bash
  # Example: creating a conanfile.txt
  [requires]
  fmt/10.1.1

  [generators]
  cmake
    ```

---

### 🔹 Build Systems

Build systems automate the compilation process, making it easier to manage multiple source files, dependencies, and build configurations.

* **Makefile**

  * Traditional Unix tool.
  * Explicitly defines compilation rules and dependencies.
  * Widely used in 42 School projects.

  ```makefile
  CXX = c++
  CXXFLAGS = -Wall -Wextra -Werror -std=c++98

  SRCS = main.cpp Foo.cpp
  OBJS = $(SRCS:.cpp=.o)

  NAME = my_program

  all: $(NAME)

  $(NAME): $(OBJS)
  	$(CXX) $(CXXFLAGS) -o $@ $^

  clean:
  	rm -f $(OBJS)

  fclean: clean
  	rm -f $(NAME)

  re: fclean all
  ```

* **CMake**

  * A cross-platform build system generator.
  * Supports modular projects, external libraries, and is commonly used in professional environments.

  ```cmake
  cmake_minimum_required(VERSION 3.16)
  project(MyProject VERSION 1.0 LANGUAGES CXX)

  set(CMAKE_CXX_STANDARD 98)

  add_executable(my_program main.cpp Foo.cpp)
  ```

---

### 🔹 Working with Libraries

In C++, libraries can be linked in two main ways:

* **Static Libraries (`.a` / `.lib`)**

  * Code is copied directly into the executable.
  * Larger executables, but no need to ship external files.

  ```bash
  ar rcs libmath.a math.o
  g++ main.cpp -L. -lmath -o app
  ```

* **Dynamic Libraries (`.so` / `.dll` / `.dylib`)**

  * Linked at runtime, keeping executables smaller.
  * Requires the library to be present on the system.

  ```bash
  g++ main.cpp -L. -lmath_shared -o app
  export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
  ```

---

### 🔹 Best Practices

* Keep a clear **project structure**: `src/`, `include/`, `lib/`, `tests/`.
* Always provide a **Makefile** or **CMakeLists.txt** so others can build your project easily.
* Document **dependencies** in a `README.md` or `conanfile.txt`.
* Prefer **package managers** (Conan, vcpkg) over manual installation.
* For collaborative projects, ensure consistent compiler flags (e.g., `-Wall -Wextra -Werror -std=c++98`).

---
