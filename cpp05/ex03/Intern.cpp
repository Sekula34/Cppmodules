#include "Intern.hpp"

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

}
