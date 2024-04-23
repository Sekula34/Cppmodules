NAME = btc

SOURCES =	main.cpp\
			BitcoinExchange.cpp


HEADERS = BitcoinExchange.hpp\


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

test : $(NAME)
	./btc ignore/input.txt 

test2 : $(NAME)
	./btc ignore/InvalidHeader.txt

test3 : $(NAME)
	./btc ignore/InvalidPipe.txt

test4 : $(NAME)
	./btc ignore/TestingInput.txt
