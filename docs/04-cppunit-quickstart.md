## 🧪 Getting Started with CppUnit in C++98

Below is a **minimal Makefile** and example test setup to get started with **CppUnit** installed locally (`~/cppunit-local`).

### 📄 `Makefile`

``` makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Path to your local CppUnit installation
CPPUNIT_DIR = $(HOME)/cppunit-local
CPPUNIT_INC = -I$(CPPUNIT_DIR)/include
CPPUNIT_LIB = -L$(CPPUNIT_DIR)/lib -lcppunit -ldl

# Project source files
SRCS = main.cpp MyTest.cpp
OBJS = $(SRCS:.cpp=.o)

# Test executable name
NAME = my_tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(CPPUNIT_INC) $(CPPUNIT_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPUNIT_INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

---

### 📄 `main.cpp` (Test Runner)

```cpp
#include <cppunit/ui/text/TestRunner.h>
#include "MyTest.hpp"

int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(MyTest::suite());
    return runner.run() ? 0 : 1;
}
```

---

### 📄 `MyTest.hpp`

```cpp
#include <cppunit/extensions/HelperMacros.h>

class MyTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(MyTest);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAddition();
};
```

---

### 📄 `MyTest.cpp`

```cpp
#include "MyTest.hpp"
#include <cassert>

void MyTest::testAddition() {
    int result = 2 + 2;
    CPPUNIT_ASSERT(result == 4);
}
```

---

👉 Run the following to build and execute your tests:

``` bash
make
./my_tests
```

You should see the **CppUnit test runner** output ✅.

---
