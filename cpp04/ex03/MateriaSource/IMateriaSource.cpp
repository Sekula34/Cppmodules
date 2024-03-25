#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	// std::cout << "Called INTERFACE Materia source" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource& source)
{
	(void) source;
	// std::cout << "Called copy constructor of INTERFACE MateriaSource" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource& source)
{
	(void) source;
	// std::cout <<"Called operator = of INTERFACE MateriaSource " << std::endl;
	return (*this);
}
