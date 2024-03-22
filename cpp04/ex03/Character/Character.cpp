#include "Character.hpp"
#include <iostream>

Character::Character(void)
{
	std::cout << "Called default Character constructor" << std::endl;
	_name = "Character_name";
	for(int i = 0; i < 4; i++)
	{
		_materials[i] = NULL;
	}
}

Character::Character(Character &source)
{
	std::cout << "Called Character copy constructor" << std::endl;
	_name = source._name;
}

Character& Character::operator=(Character &source)
{
	std::cout << "Called Character =operator" << std::endl;
	this->_name = source._name;
	return (*this);
}

Character::~Character()
{
	std::cout << "Called Character destructor" << std::endl;
}

Character::Character(std::string name)
{
	if(name.empty() == true)
		name = "Default";
	std::cout << "Called Character constructor with the name " << name << std::endl;
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
	(void)m;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	(void) target;
	(void) idx;
}
