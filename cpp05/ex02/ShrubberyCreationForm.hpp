#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
#include <fstream>
# include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		
		// std::ofstream _shrubberyFile;
		void _printingFiles(std::ofstream& _shrubberyFile) const;
		void _printingFolders(struct dirent* file, std::ofstream& _shrubberyFile) const;
		void _printactualTree(std::ofstream& _shrubberyFile) const;

	public :
		//orthodox
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		void execute(Bureaucrat const & executor) const;
};

#endif
