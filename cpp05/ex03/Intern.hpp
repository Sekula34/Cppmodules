#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

enum Form {SHRUB, ROBOT, PRESIDENTIAL};

class Intern 
{

	private :
		int _getFormId(std::string formName) const;
		void _sayIamdone(AForm *form) const;
		ShrubberyCreationForm* _createShrub(std::string target) const;
		RobotomyRequestForm* _createRobot(std::string target) const;
		PresidentialPardonForm* _createPresidential(std::string target) const;

	public :
	//orthodox
		Intern(void);
		Intern(const Intern& source);
		Intern& operator=(const Intern& source);
		~Intern();

		AForm* makeForm(std::string nameOfForm, std::string targetForm);
		class NoSuchFormException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

#endif
