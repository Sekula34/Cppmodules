NAME = abstract

SOURCES = Animal.cpp \
	Brain.cpp \
	Cat.cpp \
	Dog.cpp \
	main.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \


HEADERS = Animal.hpp \
		Brain.hpp \
		Cat.hpp \
		Dog.hpp


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