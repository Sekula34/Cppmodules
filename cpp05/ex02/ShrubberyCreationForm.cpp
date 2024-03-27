#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ios>
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


// • ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it
void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if(this->getIsSgined() == false)
		throw AForm::FormNotSignedException();
	this->requiredGradeCheck(executor.getGrade(), this->getGradeToExecute());
	std::cout << "Execution can start" << std::endl;
	const std::string fileName(getName() + "_shrubbery");
	_shrubberyFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	if(_shrubberyFile.fail() == true)
		throw std::runtime_error("Openig file failed");
	_shrubberyFile << "Stavi nesto u fajl za sada" << std::endl;
}
