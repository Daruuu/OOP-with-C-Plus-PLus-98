
# 📘 Local Installation of CppUnit (without root access in Linux)

This guide explains how to install **CppUnit** locally in your home directory (e.g., `~/cppunit-local`) without requiring root privileges.

---

## 🔹 1. Download and Extract

```bash
tar -xvzf cppunit-1.12.1.tar.gz
cd cppunit-1.12.1
```

---

## 🔹 2. Configure for Local Installation

Choose a custom install path, for example `~/cppunit-local`:

```bash
./configure --prefix=$HOME/cppunit-local --disable-shared
```

* `--prefix=$HOME/cppunit-local`: install everything under your home folder.
* `--disable-shared`: build only the static library (avoids shared library issues on some systems).

---

## 🔹 3. Build and Install

```bash
make
make install
```

This will install **CppUnit** into `~/cppunit-local` instead of `/usr/local`.

---

## 🔹 4. Resulting Directory Structure

```
~/cppunit-local/
├── include/     ← headers (CppUnit.h, etc.)
└── lib/         ← libcppunit.a / libcppunit.so
```

---

## 🔹 5. Using CppUnit in Your Project

When compiling your code, tell `g++` where to find headers and libraries:

```bash
g++ -I$HOME/cppunit-local/include -L$HOME/cppunit-local/lib \
    -o my_tests my_tests.cpp -lcppunit -ldl
```

---

## 🔹 6. In Your Code

You can include normally:

```cpp
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
```

because `-I$HOME/cppunit-local/include` already points to the correct location.

---

## ✅ Benefits

* No need for **root permissions**.
* No modification of `/usr/include` or `/usr/local/lib`.
* Everything is isolated in `~/cppunit-local`.

---