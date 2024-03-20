#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{

}
void HumanA::attack(void)
{
	std::cout << _name;
	std::cout << " attacks with ";
	std::cout << _weapon.getType() << std::endl;
}
