#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Called ScavTrap default construtor" << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
