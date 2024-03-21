#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include "AMateria.hpp"
# include <string>

class IMateriaSource 
{
	public:
		//orthodox
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource& source);
		IMateriaSource& operator=(const IMateriaSource& source);
		virtual ~IMateriaSource() {};

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif