#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>
#include <iostream>
#include <iomanip> 


//function that check if grades are correct
void AForm::_checkGrades() const
{
	if(_gradeToSign > LOWESTGRADE)
		throw GradeTooLowException();
	if(_gradeToSign < HIGHESTGRADE)
		throw GradeTooHighException();
	if(_gradeToExecute > LOWESTGRADE)
		throw GradeTooLowException();
	if(_gradeToExecute < HIGHESTGRADE)
		throw GradeTooHighException();
}

//check if grade is High enough to to something,
// grade should be lower or equal than required one to no throw exception
void AForm::requiredGradeCheck(int grade, int requiredGrade)
{
	if(grade > requiredGrade)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(void) : _name("DefaultFormName"), _isSigned(false),
_gradeToSign(HIGHESTGRADE), _gradeToExecute(HIGHESTGRADE)
{
	_checkGrades();
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_checkGrades();
}

AForm& AForm::operator=(const AForm& source)
{
	this->_isSigned = source._isSigned;
	return (*this);
}

AForm::~AForm()
{

}

std::string AForm::getName() const 
{
	return (_name);
}

bool AForm::getIsSgined() const 
{
	return (_isSigned);
}

int AForm::getGradeToSign() const 
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const 
{
	return (_gradeToExecute);
}

// Add also a beSigned() member function to the AForm that takes a Bureaucrat as
// parameter. It changes the AForm status to signed if the bureaucrat’s grade is high enough
// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a AForm::GradeTooLowException
void AForm::beSigned(const Bureaucrat& biro)
{
	if(_isSigned == false)
	{
		requiredGradeCheck(biro.getGrade(), _gradeToSign);
		_isSigned = true;
	}
	else
	{
		std::cout << "Form is already signed" << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high FORM");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low FORM");
}


const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& forma)
{
	int width = 33; // Set the width for your alignment
	os <<  "--------------------FORM INFO--------------------" << std::endl;
	os << std::right << std::setw(width) << "Form name :" << forma.getName() << std::endl;
	os << std::right << std::setw(width) << "Form is signed :" << forma.getIsSgined() << std::endl;
	os << std::right << std::setw(width) << "Form required grade to sign :" << forma.getGradeToSign() << std::endl;
	os << std::right << std::setw(width) << "Form required grade to execute :" << forma.getGradeToExecute() << std::endl;
	os << "--------------------------------------------------";
	return (os);
}
