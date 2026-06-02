CXX = c++
# GoogleTest requiere al menos C++11. Compilamos las pruebas en C++11,
# aunque el código de producción siga siendo compatible con C++98.
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -I..
LDFLAGS = -lgtest -lpthread

NAME = run_tests
SRCS = pmergeme_test.cpp ../PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.cpp ../PmergeMe.hpp ../Utils.hpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
