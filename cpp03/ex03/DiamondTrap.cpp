#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default DiamondTrap_clap_name")
{
	_name = "Default DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_scavEnergy;
	_attackDamage = FragTrap:: _frag_attack;

	std::cout << "Called DiamondTrap default constructor " << std::endl;
	std::cout << "DiamondTrap hp is " << _hitPoints << std::endl;
	std::cout << "DiamondTrap energy is "<< _energyPoints << std::endl;
	std::cout << "DiamondTrap attack damage is "<< _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_scavEnergy;
	_attackDamage = FragTrap:: _frag_attack;

	std::cout << "Called DiamondTrap default constructor " << std::endl;
	std::cout << "DiamondTrap hp is " << _hitPoints << std::endl;
	std::cout << "DiamondTrap energy is "<< _energyPoints << std::endl;
	std::cout << "DiamondTrap attack damage is "<< _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source)
{
	this->_name = source._name;
	this->_hitPoints = source._attackDamage;
	this->_energyPoints = source._energyPoints;
	this->_attackDamage = source._attackDamage;
	std::cout << "Called DiamondTrap copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& source)
{
	this->_name = source._name;
	this->_hitPoints = source._attackDamage;
	this->_energyPoints = source._energyPoints;
	this->_attackDamage = source._attackDamage;
	std::cout << "Called DiamondTrap = operator" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Called DiamondTrap "<< _name << " destructor" << std::endl;
}
void DiamondTrap::attack(std::string enemy)
{
	std::cout << "DiamondTrap " << _name << " attack like a ScavTrap " << std::endl;
	ScavTrap::attack(enemy);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamodTrap _name is :" <<_name << std::endl;
	std::cout << "My ClapTrap name is :" << ClapTrap::_name << std::endl;
}
