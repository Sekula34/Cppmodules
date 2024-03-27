#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
#include <fstream>
# include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::ofstream _shrubberyFile;

	public :
		//orthodox
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		void execute(Bureaucrat const & executor);
};

#endif
