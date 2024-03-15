#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Called FragTrap default constructor "<< std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_frag_attack = _attackDamage;
	_frag_energy = _energyPoints;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Called FragTrap "<< _name << " constructor" <<std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_frag_attack = _attackDamage;
	_frag_energy = _energyPoints;
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap " <<_name << " destructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& source)
{
	std::cout << "Called FragTrap copy constructor" << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	_frag_attack = _attackDamage;
	_frag_energy = _energyPoints;
}

FragTrap& FragTrap::operator=(const FragTrap& source)
{
	std::cout <<"Called FragTrap = operator" << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	_frag_attack = _attackDamage;
	_frag_energy = _energyPoints;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " <<_name << " requested positive high five" << std::endl;
}
