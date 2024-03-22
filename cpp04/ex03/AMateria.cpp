#include "AMateria.hpp"
#include <string>
#include <iostream>

AMateria::AMateria(void) : m_type("DefaultType")
{
	std::cout << "AMateria Default constructor" << std::endl;
}

AMateria::AMateria(const AMateria& source)
{
	std::cout << "AMateria copy constructor" << std::endl;
	m_type = source.m_type;
}

AMateria& AMateria::operator=(const AMateria& source)
{
	std::cout << "AMateria = operator" << std::endl;
	this->m_type = source.m_type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "Called AMateria constructor with type as argument" << std::endl;
	m_type = type;
}

std::string const& AMateria::getType() const
{
	return (m_type);
}
