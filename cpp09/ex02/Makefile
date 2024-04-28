NAME = PmergeMe

SOURCES =	main.cpp\
			PmergeMe.cpp


HEADERS = PmergeMe.hpp\


CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g -pedantic

OBJS := $(SOURCES:%.cpp=%.o)

ARGS := $(shell shuf -i 1-100000 -n 1000 | tr "\n" " ")

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
	./$(NAME)

test2 : $(NAME) 
	./$(NAME) 3 5 9 7 4

test3 : $(NAME) 
	./$(NAME) `shuf -i 1-100000 -n 100 | tr "\n" " "`

test4 : $(NAME)
	echo $(ARGS)
	./$(NAME) $(ARGS)

test5 : $(NAME)
	./$(NAME) 3661 19772 32109 47479 58078
