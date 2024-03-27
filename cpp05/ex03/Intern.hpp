#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"

class Intern 
{

	private :
		
	public :
	//orthodox
		Intern(void);
		Intern(const Intern& source);
		Intern& operator=(const Intern& source);
		~Intern();

		AForm* makeForm(std::string nameOfForm, std::string targetForm);
};

#endif
