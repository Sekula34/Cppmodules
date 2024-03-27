NAME = intern

SOURCES =	main.cpp\
			Bureaucrat.cpp\
			Intern.cpp\
			AForm.cpp \
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			ShrubberyCreationForm.cpp


HEADERS =	Bureaucrat.hpp\
			Intern.hpp\
			AForm.hpp\
			PresidentialPardonForm.hpp\
			RobotomyRequestForm.hpp\
			ShrubberyCreationForm.hpp

		


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
