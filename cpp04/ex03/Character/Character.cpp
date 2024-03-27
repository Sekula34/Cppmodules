#include "Character.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>


//function that returns first empty spot of Character inverntory
//0 till 3 if spot is found (index);
//-1 if all spots are taken
int Character::getFirstEmptySpot() const 
{
	for(int i = 0; i < 4; i++)
	{
		if(_materials[i] == NULL)
			return (i);
	}
	return (-1);
}

Character::Character(void)
{
	// std::cout << "Called default Character constructor" << std::endl;
	// _name = "Character_name";
	for(int i = 0; i < 4; i++)
	{
		_materials[i] = NULL;
	}
}

Character::Character(Character &source)
{
	// std::cout << "Called Character copy constructor" << std::endl;
	_name = source._name;
	for(int i = 0; i < 4; i++)
	{
		if(source._materials[i] == NULL)
		{
			_materials[i] = NULL;
		}
		else
		{
			_materials[i] = source._materials[i]->clone();
		}
	}
}

Character& Character::operator=(Character &source)
{
	// std::cout << "Called Character =operator" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		delete this->_materials[i];
		this->_materials[i] = NULL;
	}
	for(int i = 0; i < 4; i++)
	{
		if(source._materials[i] == NULL)
		{
			this->_materials[i] = NULL;
		}
		else
		{
			this->_materials[i] = source._materials[i]->clone();
		}
	}
	this->_name = source._name;
	return (*this);
}

Character::~Character()
{
	// std::cout << "Called Character destructor" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		delete _materials[i];
	}
}

Character::Character(std::string name)
{
	if(name.empty() == true)
		name = "Default";
	// std::cout << "Called Character constructor with the name " << name << std::endl;
	_name = name;
	for(int i = 0; i < 4; i++)
	{
		_materials[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	int spotIndex = getFirstEmptySpot();
	if(spotIndex == -1)
	{
		std::cerr << "There is no available spot in inventory" << std::endl;
		delete m;
		return ; 
	}
	_materials[spotIndex] = m;
	std::stringstream ss;

	ss << spotIndex;
	std::cout << "Materia " << m->getType() << " equiped in ";
	std::cout << "slot " << ss.str() << std::endl;
}


//do something about pointer you are losing here
void Character::unequip(int idx)
{
	if(idx < 0 || idx > 3)
	{
		std::cerr << "You are trying to unequip outside of range of your inventory" << std::endl;
		return ;
	}
	if(_materials[idx] != NULL)
	{
		std::cout << "Item " << _materials[idx]->getType() << " droped on floor" << std::endl;
	}
	_materials[idx] = NULL;
}


// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.
void Character::use(int idx, ICharacter& target)
{
	if(idx < 0 || idx > 3)
	{
		std::cerr << "You are trying to cast Materia outside your inventory slot" << std::endl;
		return;
	}
	if(_materials[idx] == NULL)
	{
		std::stringstream ss;
		ss << idx;
		std::cout << "Slot " << ss.str() << " is empty so you cant use it (No materias to use)" << std::endl;
		return;
	}
	_materials[idx]->use(target);
}

void Character::listAllMaterials() const
{
	std::cout << _name << " Inventory :" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		std::stringstream ss;
		ss << i;
		std::cout << '\t';
		std::cout << "Material at postion "<<ss.str() <<" is ";
		if(_materials[i] == NULL)
			std::cout << "<empty space>";
		else
			std:: cout << _materials[i]->getType();
		std::cout << std::endl;
	}
}

AMateria* Character::getMateriaPtr(int index) const 
{
	if(index < 0 || index > 3)
		return NULL;
	return (_materials[index]);
}
