#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("default_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Called default ClapTrap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) : _name(source._name), _hitPoints(source._hitPoints), _energyPoints(source._energyPoints), _attackDamage(source._attackDamage)
{
	std::cout << "Called copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << "called = operator" << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if(name.empty() == true)
	{
		std::cerr << "name is empty" << std::endl;
		throw ;
	}
	std::cout << "called constructor with name " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(_energyPoints < 1)
	{
		std::cerr << "ClapTrap " << _name << " do not have enough energy points to make attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout <<", causing " << _attackDamage <<" points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout <<"ClapTrap "<<_name << " takes " << amount <<" of damage" << std::endl;
	if(amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energyPoints < 1)
	{
		std::cerr << "ClapTrap " << _name << " do not have enough energy points to repair" << std::endl;
		return ;
	}
	std::cout << "ClapTrap "<< _name << " repaires for " << amount << " of HP!" << std::endl;
	_energyPoints --;
}
