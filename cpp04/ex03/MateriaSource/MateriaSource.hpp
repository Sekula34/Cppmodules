#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public :
	//orthodox
		MateriaSource(void);
		MateriaSource(MateriaSource& source);
		MateriaSource& operator= (MateriaSource& source);
		~MateriaSource();
};

#endif