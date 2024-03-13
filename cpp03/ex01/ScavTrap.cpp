#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Called ScavTrap default construtor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
ScavTrap::ScavTrap(std::string scavName) : ClapTrap(scavName)
{
	std::cout << "Called ScavTrap "<< scavName <<" constructor" <<std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
} 

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap "<<_name <<" is now in Gate keeper mode" << std::endl;
}
