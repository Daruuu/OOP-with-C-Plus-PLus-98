# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
DEBUG_FLAGS = -g -O0 -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

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
DEBUG_OBJS = $(SRCS:.cpp=_debug.o)

# Test executable names
NAME = my_tests
DEBUG_NAME = my_tests_debug

# Default target
all: $(NAME)

# Release build
$(NAME): $(OBJS)
	@echo "Building release version..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) $(OBJS) -o $(NAME) $(CPPUNIT_INC) $(CPPUNIT_LIB)
	@echo "Build complete: $(NAME)"

# Debug build
debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJS)
	@echo "Building debug version..."
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(DEBUG_OBJS) -o $(DEBUG_NAME) $(CPPUNIT_INC) $(CPPUNIT_LIB)
	@echo "Debug build complete: $(DEBUG_NAME)"

# Object file compilation
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) $(CPPUNIT_INC) -c $< -o $@

%_debug.o: %.cpp
	@echo "Compiling $< (debug)..."
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(CPPUNIT_INC) -c $< -o $@

# Run tests
run: $(NAME)
	@echo "Running tests..."
	@./$(NAME)

# Run debug tests
run-debug: $(DEBUG_NAME)
	@echo "Running debug tests..."
	@./$(DEBUG_NAME)

# Check if CppUnit is properly installed
check-cppunit:
	@echo "Checking CppUnit installation..."
	@if pkg-config --exists cppunit; then \
		echo "✓ CppUnit found via pkg-config"; \
		pkg-config --cflags cppunit; \
		pkg-config --libs cppunit; \
	elif [ -d "$(CPPUNIT_DIR)" ]; then \
		echo "✓ CppUnit found in $(CPPUNIT_DIR)"; \
	else \
		echo "✗ CppUnit not found! Please install CppUnit or set CPPUNIT_DIR"; \
		exit 1; \
	fi

# Clean targets
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS) $(DEBUG_OBJS)

fclean: clean
	@echo "Cleaning executables..."
	rm -f $(NAME) $(DEBUG_NAME)

# Rebuild
re: fclean all

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build release version (default)"
	@echo "  debug        - Build debug version"
	@echo "  run          - Build and run release tests"
	@echo "  run-debug    - Build and run debug tests"
	@echo "  check-cppunit- Check CppUnit installation"
	@echo "  clean        - Remove object files"
	@echo "  fclean       - Remove all generated files"
	@echo "  re           - Rebuild from scratch"
	@echo "  help         - Show this help"

.PHONY: all debug run run-debug check-cppunit clean fclean re help
