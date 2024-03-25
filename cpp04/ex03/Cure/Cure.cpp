#include "Cure.hpp"
#include <iostream>
#include <new>

Cure::Cure(void)
{
	// std::cout << "Called Cure default constructor" << std::endl;
	m_type = "cure";
}

Cure::Cure(Cure& source)
{
	// std::cout << "Called Cure copy construcotr" << std::endl;
	m_type = source.m_type;
}

Cure& Cure::operator=(Cure& source)
{
	// std::cout << "Called Cure = operato" << std::endl;
	this->m_type = source.m_type;
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Called Cure destructor" << std::endl;
}

AMateria* Cure::clone() const 
{
	AMateria* curePtr;
	try 
	{
		curePtr = new Cure;
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "Memory allocation failed" << std::endl;
	}
	return (curePtr);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "s wounds *" << std::endl;
}
