#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>
#include <iostream>


//function that check if grades are correct
void Form::_checkGrades() const
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
void Form::_requiredGradeCheck(int grade, int requiredGrade)
{
	if(grade > requiredGrade)
		throw GradeTooLowException();
}

Form::Form(void) : _name("DefaultFormName"), _isSigned(false),
_gradeToSign(HIGHESTGRADE), _gradeToExecute(HIGHESTGRADE)
{
	_checkGrades();
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_checkGrades();
}

Form& Form::operator=(const Form& source)
{
	return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const 
{
	return (_name);
}

bool Form::getIsSgined() const 
{
	return (_isSigned);
}

int Form::getGradeToSign() const 
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const 
{
	return (_gradeToExecute);
}

// Add also a beSigned() member function to the Form that takes a Bureaucrat as
// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException
void Form::beSigned(const Bureaucrat& biro)
{
	if(_isSigned == false)
	{
		_requiredGradeCheck(biro.getGrade(), _gradeToSign);
		_isSigned = true;
	}
	else
	{
		std::cout << "Form is already signed" << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Form& forma)
{
	os<<"-----FORM INFO-----"<<std::endl;
	os<<"\tForm name :" << forma.getName() << std::endl;
	os<<"\tForm is signed :" << forma.getIsSgined() << std::endl;
	os<<"\tForm required grade to sign :" << forma.getGradeToSign() << std::endl;
	os<<"\tForm required grade to execute :" << forma.getGradeToExecute() << std::endl;
	os<<"----------------------------";
	return (os);
}
