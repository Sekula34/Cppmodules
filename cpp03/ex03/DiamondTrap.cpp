#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	std::cout << "Called DiamondTrap default constructor" << std::endl;
	std::cout << FragTrap::_attackDamage << std::endl;
	std::cout << ScavTrap::_attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout <<"Called DiamondTrap destructor" << std::endl;
}
