#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

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
		throw std::runtime_error("Target cannot be empty");
}


// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(getIsSgined() == false)
		throw AForm::FormNotSignedException();
	requiredGradeCheck(executor.getGrade(), getGradeToExecute());
	std::cout << "Informing that " << _target << " has been pardoned by Zaphod Beeblerbrox";
	std::cout << std::endl;
}
