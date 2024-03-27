#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM
# include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& source);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		void execute(Bureaucrat const & executor) const;

};

#endif
