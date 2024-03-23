#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource()
{
	std::cout << "Called INTERFACE Materia source" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource& source)
{
	std::cout << "Called copy constructor of INTERFACE MateriaSource" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource& source)
{
	std::cout <<"Called operator = of INTERFACE MateriaSource " << std::endl;
	return (*this);
}