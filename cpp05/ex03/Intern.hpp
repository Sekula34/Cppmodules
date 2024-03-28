#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

enum Form {SHRUB, ROBOT, PRESIDENTIAL};

class Intern 
{

	private :
		std::string _toLowerString(std::string&  input) const;
		int _getFormId(std::string formName) const;
		void _sayIamdone(AForm *form) const;
		AForm* _createShrub(std::string target);
		AForm* _createRobot(std::string target);
		AForm* _createPresidential(std::string target);

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
