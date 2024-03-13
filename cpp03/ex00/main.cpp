#include "ClapTrap.hpp"

int main()
{
	ClapTrap digimon("Baba roga");
	for(int i = 0; i < 20; i++)
	{
		digimon.attack("Sibirski plavac");
		digimon.beRepaired(100);
		digimon.takeDamage(200);
	}
	return (0);
}
