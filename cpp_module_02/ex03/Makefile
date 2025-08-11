CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O2 #-fsanitize=address

# name of executable
NAME = BSP 

# sources
SRCS = main.cpp Fixed.cpp Point.cpp

# objects
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp  Makefile Fixed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
