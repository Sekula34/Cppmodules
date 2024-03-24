#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "../AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[4];

		int _findEmptySlot(void) const;
		int _findMateriaIndex(std::string const & type);

	public :
	//orthodox
		MateriaSource(void);
		MateriaSource(MateriaSource& source);
		MateriaSource& operator= (MateriaSource& source);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
