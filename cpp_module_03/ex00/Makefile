CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O2 -fsanitize=address -MMD

# name of executable
NAME = Aaaaand...OPEN 

# sources
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
DEPENDS = $(OBJS:.o=.d)
-include $(DEPENDS)

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

.PHONY: all clean fclean re