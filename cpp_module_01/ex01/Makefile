CXX = c++

# Flags de compilación (opcional)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

# name of executable
NAME = moar_brainz

# sources
SRCS = main.cpp Zombie.cpp zombieHorde.cpp 

# objects
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp  Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
