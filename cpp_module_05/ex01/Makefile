CXX = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -O2 -MMD -fsanitize=address \
	-DRESET="\"\\033[0m\"" \
	-DRED="\"\\033[31m\"" \
	-DGREEN="\"\\033[32m\"" \
	-DYELLOW="\"\\033[33m\"" \
	-DBLUE="\"\\033[34m\"" \
	-DMAGENTA="\"\\033[35m\"" \
	-DCYAN="\"\\033[36m\"" \
	-DWHITE="\"\\033[37m\""

NAME = Form_up_maggots

SRCS = main.cpp Form.cpp Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)
DEPENDS = $(OBJS:.o=.d)

# tests
#TEST_NAME = test_runner
#TEST_SRC = tests/BureaucratTest.cpp tests/TestRunner.cpp Bureaucrat.cpp
#TEST_OBJ = $(TEST_SRC:.cpp=.o)
#TEST_FLAGS = -lcppunit -ldl

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPP_FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp	Makefile
	$(CXX) $(CPP_FLAGS) -c $< -o $@

#test: $(TEST_OBJ)
#	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -o $(TEST_NAME) $(TEST_FLAGS)
#	./$(TEST_NAME)

clean:
	rm -rf $(OBJS) $(DEPENDS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPENDS)
.PHONY: all clean fclean re