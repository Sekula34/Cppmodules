#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(void)
:AForm("Presidential Pardon Form", 25, 5)
{
	_target = "DefaultTargetName";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source)
:AForm("Presidential Pardon Form", source.getGradeToSign(), source.getGradeToExecute())
{
	_target = source._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
	this->_target = source._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("Presidential Pardon Form", 25, 5)
{
	_target = target;
	if(_target.empty())
		std::runtime_error("Target cannot be empty");
}


void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	(void)executor;
}
