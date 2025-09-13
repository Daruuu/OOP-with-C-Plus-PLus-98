CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Allow overriding CppUnit installation path
CPPUNIT_DIR ?= $(HOME)/cppunit-local
CPPUNIT_INC = -I$(CPPUNIT_DIR)/include
CPPUNIT_LIB = -L$(CPPUNIT_DIR)/lib -lcppunit -ldl

# If pkg-config is available, use it (preferred)
ifneq ($(shell pkg-config --exists cppunit && echo yes),)
    CPPUNIT_INC = $(shell pkg-config --cflags cppunit)
    CPPUNIT_LIB = $(shell pkg-config --libs cppunit)
endif

# Project source files
SRCS = main.cpp Testing.cpp
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
