#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie:: Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie:: ~Zombie()
{
	std::cout << name << " called destructor" << std::endl;
}
