NAME = RPN

SOURCES =	main.cpp\
			RPN.cpp


HEADERS = RPN.hpp\


CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g -pedantic

OBJS := $(SOURCES:%.cpp=%.o)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) -o $(NAME) $(OBJS)

.PHONY: all clean fclean re

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME);

re: fclean all

test1 : $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

test2 : $(NAME)
	./$(NAME) "7 7 * 7 -"

test3 : $(NAME)
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"

test4 : $(NAME)
	./$(NAME)  "(1 + 1)"
	
test5 : $(NAME)
	./$(NAME)  "1 0 /"
