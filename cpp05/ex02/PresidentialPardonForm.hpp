#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public :
	//orthodox
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& source);
		~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);

		void execute(Bureaucrat const & executor);

};

#endif
