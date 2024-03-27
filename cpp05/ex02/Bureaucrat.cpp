#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default_name"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if(grade < 1)
	{
		throw Bureaucrat::GradeTooHightException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) : _name(source._name)
{
	_grade = source._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source)
{
	this->_grade = source._grade;
	return (*this);
}

Bureaucrat:: ~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const 
{
	return (_grade);
}

void Bureaucrat::increaseGrade(void)
{
	_grade--;
	if (_grade < 1)
	{
		throw Bureaucrat::GradeTooHightException();
	}
}

void Bureaucrat::increaseGrade(int increment)
{
	_grade -= increment;
	if(_grade < 1)
	{
		throw Bureaucrat::GradeTooHightException();
	}
}

void Bureaucrat::decreaseGrade()
{
	_grade++;
	if(_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::decreaseGrade(int decrement)
{
	_grade += decrement;
	if(_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

// Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
// it will print something like:
// <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>.
void Bureaucrat::signForm(AForm &formToSign)
{
	if(formToSign.getIsSgined() == true)
		return;
	if(this->_grade > formToSign.getGradeToSign())
	{
		std::cout << this->_name << " couldn't sign ";
		std::cout << formToSign.getName() << "because of too low level" << std::endl;
		return ;
	}
	formToSign.beSigned(*this);
	std::cout << this->_name << " signed " << formToSign.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHightException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low");
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& birokrat)
{
	os << birokrat.getName() <<", bureaucrat grade " << birokrat.getGrade() <<".";
	return (os);
}
