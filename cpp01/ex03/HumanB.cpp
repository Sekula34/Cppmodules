#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(void)
{
	std::cout << _name;
	std::cout << " attacks with ";
	if (_weaponPtr == NULL)
		std::cout << "<no weapon>" << std::endl;
	else 
		std::cout << _weaponPtr->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weaponRef)
{
	_weaponPtr = &weaponRef;
}

HumanB::HumanB(std::string humanName)
{
	_name = humanName;
	_weaponPtr = NULL;
}
