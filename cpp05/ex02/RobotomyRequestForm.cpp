#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("DefaultRobotomyRequestForm", 72, 45)
{

}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source)
: AForm(source.getName(), source.getGradeToSign(), source.getGradeToExecute())
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	(void) source;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm(target, 72, 45)
{
	if(target.empty() == true)
		throw std::runtime_error("From target name is empty");
}


// • RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.
void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
 
	if(getIsSgined() == false)
		throw AForm::FormNotSignedException();
	requiredGradeCheck(executor.getGrade(), getGradeToExecute());
	std::srand(std::time(NULL));
	int variable = rand();
	if(variable % 2 == 1)
	{
		std::cout << getName() << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed" << std::endl;
	}
	
}
