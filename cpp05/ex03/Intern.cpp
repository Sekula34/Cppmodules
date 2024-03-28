#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>
#include <string>
#include <iostream>

Intern::Intern()
{

}

Intern::Intern(const Intern& source)
{
	(void) source;
}

Intern& Intern::operator=(const Intern& source)
{
	(void) source;
	return (*this);
}

Intern::~Intern()
{

}


//get form Id
//return 0 to N if form is foudn
// defined in enum _form
//throw noSuchForm exception if not
int Intern::_getFormId(std::string formName) const 
{
	const std::string allForms[] = {"shrubbery creation","robotomy request",
	"presidential pardon"};

	int arraysize = sizeof(allForms) / sizeof(std::string);

	for(int i = 0; i < arraysize; i++)
	{
		if(allForms[i] == formName)
			return (i);
	}
	throw NoSuchFormException();
}

void Intern::_sayIamdone(AForm *form) const
{
	std::cout <<"Intern creates " << form->getName() << std::endl;
}

ShrubberyCreationForm* Intern::_createShrub(std::string target) const 
{
	ShrubberyCreationForm *shrubptr;

	try 
	{
		shrubptr = new ShrubberyCreationForm(target);
	}
	catch(std::exception &e)
	{
		std::cout <<e.what() <<std::endl;
		throw e;
	}
	_sayIamdone(shrubptr);
	return (shrubptr);
}

RobotomyRequestForm* Intern::_createRobot(std::string target) const 
{
	RobotomyRequestForm *robPtr;

	try 
	{
		robPtr = new RobotomyRequestForm(target);
	}
	catch(std::exception &e)
	{
		std::cout <<e.what() <<std::endl;
		throw e;
	}
	_sayIamdone(robPtr);
	return (robPtr);
}

// However, the intern has one important capacity: the makeForm() function. 
//It takestwo strings. 
//The first one is the name of a form and the second one is the target of the
// form. It return a pointer to a Form object 
//(whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.
// It will print something like:
// Intern creates <form>
// If the form name passed as parameter doesn’t exist,
// print an explicit error message.
// 11
// C++ - Module 05 Repetition and Exceptions
// You must avoid unreadable and ugly solutions 
//like using a if/elseif/else forest. This
// kind of things won’t be accepted during the evaluation process. 
//You’re not in Piscine
// (pool) anymore. As usual, you have to test that everything works as expected
AForm* Intern::makeForm(std::string nameOfForm, std::string targetForm)
{
	try
	{
		Form decison = static_cast<Form>(_getFormId(nameOfForm));
		switch (decison) 
		{
			case SHRUB:
			{
				return (_createShrub(targetForm));
			}
			case ROBOT:
			{
				return (_createRobot(targetForm));
			}
			case PRESIDENTIAL: //create presidential
			{
				return (new PresidentialPardonForm(targetForm));
			}
		
		}
	}
	catch (NoSuchFormException &e)
	{
		std::cerr<<e.what() << std::endl;
		std::cerr <<"Sorry boss there is no such form as "<< nameOfForm << std::endl;
	}
	// catch(std::exception &e)
	// {
	// 	e.what();
	// 	throw e;
	// }
	return NULL;
}


const char* Intern::NoSuchFormException::what() const throw()
{
	return ("Exception:There is no such Form");
}
