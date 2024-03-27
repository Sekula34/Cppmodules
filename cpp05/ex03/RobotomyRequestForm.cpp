#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request Form", 72, 45)
{
	_target = "<Default Robotomy Target>";
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source)
: AForm("Robotomy Request Form", source.getGradeToSign(), source.getGradeToExecute())
{
	_target = source._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	this->_target = source._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy Request Form", 72, 45)
{
	_target = target;
	if(target.empty() == true)
		throw std::runtime_error("Form target name is empty");
}


// • RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
 
	if(getIsSgined() == false)
		throw AForm::FormNotSignedException();
	requiredGradeCheck(executor.getGrade(), getGradeToExecute());
	std::srand(std::time(NULL));
	int variable = rand();
	if(variable % 2 == 1)
	{
		std::cout << _target << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed" << std::endl;
	}
	
}
