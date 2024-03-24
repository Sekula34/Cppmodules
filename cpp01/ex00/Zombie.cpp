#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie:: Zombie(std::string name)
{
	if(name.empty() == true)
		name = "Default_name";
	Zombie::name = name;
	std::cout << "Called Zobie " << name << " constructor" << std::endl;
}

Zombie:: ~Zombie()
{
	std::cout << name << " called destructor" << std::endl;
}
