#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("defualtSrhuberyname", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source)
{
	(void)source;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	(void)source;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137)
{
	if(target.empty() == true)
		throw std::runtime_error("Form name cannot be empty");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if(this->getIsSgined() == false)
		throw AForm::FormNotSignedException();
	this->requiredGradeCheck(executor.getGrade(), this->getGradeToExecute());
	std::cout << "Execution can start" << std::endl;
}
