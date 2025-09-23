CXX = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -O2 -MMD -fsanitize=address

NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPP_FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp	Makefile
	$(CXX) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPENDS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPENDS)
.PHONY: all clean fclean re