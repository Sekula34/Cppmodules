
#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie:: Zombie()
{

}
Zombie:: Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie:: ~Zombie()
{
	std::cout << name << " called destructor" << std::endl;
}

void Zombie::set_name(std::string name)
{
	if(name.empty() == true)
		Zombie::name = "<Defaultname>";
	else
		Zombie::name = name;
}
