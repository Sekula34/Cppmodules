NAME = bank

SOURCES = tests.cpp \
	Account.cpp

HEADERS = Account.hpp

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