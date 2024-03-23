#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include "../AMateria.hpp"

class IMateriaSource
{
	public:
		//orthodox
		IMateriaSource();
		IMateriaSource(IMateriaSource& source);
		IMateriaSource& operator=(IMateriaSource& source);

		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif