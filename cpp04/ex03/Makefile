NAME = interface

SOURCES = main.cpp \
	Character/Character.cpp\
	Character/ICharacter.cpp\
	Cure/Cure.cpp \
	Ice/Ice.cpp \
	MateriaSource/IMateriaSource.cpp\
	MateriaSource/MateriaSource.cpp\
	AMateria.cpp

HEADERS = Cure/Cure.hpp \
		Character/Character.hpp \
		Character/ICharacter.hpp\
		Ice/Ice.hpp \
		MateriaSource/IMateriaSource.hpp\
		MateriaSource/MateriaSource.hpp\
		AMateria.hpp \
		IMateriaSource.hpp \
		


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