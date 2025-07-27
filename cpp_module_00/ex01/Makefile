CXX = c++

# Flags de compilación (opcional)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# name of executable
NAME = phonebook

# sources
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# objects
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto (se ejecuta al invocar `make` sin argumentos)
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Esto indica que all, clean, fclean y re no son archivos,
# sino "etiquetas" para comandos de make.
.PHONY: all clean fclean re
