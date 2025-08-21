CXX = c++

CXXFLAGS = -Wall -Wextra -Wshadow -Werror -std=c++98 -O2 -g -fsanitize=address -MMD

# name of executable
NAME = Interface_and_recap

# sources
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp  Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPENDS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPENDS)
.PHONY: all clean fclean re
