#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *Zombac;

	try
	{
		Zombac = new Zombie(name);
	}
	catch (std::exception& e)
	{
		std::cout << "Standard exception: " << e.what() << std::endl;
		throw;
	}
	return (Zombac);
}
