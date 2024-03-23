#include "Ice.hpp"
#include <iostream>
#include <new>
#include "../AMateria.hpp"

Ice::Ice(void)
{
	std::cout << "Called ice default constructor" << std::endl;
	m_type = "ice";
}

Ice::Ice(Ice& source)
{
	std::cout << "Ice copy constructor"<< std::endl;
	m_type = source.m_type;
}

Ice& Ice::operator=(Ice& source)
{
	std::cout << "Ice = assignment" << std::endl;
	m_type = source.m_type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::clone() const 
{
	AMateria* iceClone;
	try 
	{
		iceClone = new Ice;
	}
	catch (std::bad_alloc&) 
	{
		std::cerr << "Memory allocation failed" << std::endl;
	}
	return (iceClone);
}

void Ice::use(ICharacter &traget)
{
	std::cout << "* shoots an ice bolt at "<< traget.getName() << " *"<< std::endl;
}
