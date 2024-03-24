#include "MateriaSource.hpp"
#include <iostream>


//return the index of first empty slot 0 to 3 if if find one
//return -1 if there is no empty slot
int MateriaSource::_findEmptySlot(void) const 
{
	for(int i = 0; i < 4; i++)
	{
		if(_materias[i] == NULL)
			return i;
	}
	return (-1);
}


//find the first index of materia string 
//return index if materia TYPE is found
//return -1 if it cant foound it //aka it does not exitst //not learned yet
int MateriaSource::_findMateriaIndex(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if(_materias[i] == NULL)
			continue;
		else if(_materias[i]->getType() == type)
			return (i);
	}
	return (-1);
}

MateriaSource::MateriaSource(void)
{
	std::cout << "Called MateriaSource constructor" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource& source)
{
	(void)source;
	std::cout << "Called MateriaSource copy constructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource& source)
{
	(void) source;
	std::cout << "Called MateriaSource = operator" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Called MateriaSource destructor " << std::endl;
	for(int i = 0; i < 4; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}
}


// • learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique
void MateriaSource::learnMateria(AMateria* source)
{
	int index;
	index = _findEmptySlot();
	if(index == -1)
	{
		std::cerr << "There is no empty slot to learn new materia" << std::endl;
		delete source;
		source = NULL;
		return ;
	}
	_materias[index] = source;
	std::cout << "Materia " << source->getType() <<" learned" << std::endl;
}

// • createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown
AMateria* MateriaSource::createMateria(std::string const & type)
{
	if(type.empty() == true)
		return (0);
	int index = _findMateriaIndex(type);
	if (index == -1)
		return (0);
	return (_materias[index]->clone());
}
