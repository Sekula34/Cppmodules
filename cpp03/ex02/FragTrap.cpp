#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Called FragTrap default constructor "<< std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Called FragTrap "<< _name << " constructor" <<std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap " <<_name << " destructor" << std::endl;
}

