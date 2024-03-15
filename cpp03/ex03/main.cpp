#include "DiamondTrap.hpp"


int main()
{
	DiamondTrap dijamant("Jelena Rozga");
	dijamant.attack("Severinu");
	for(int i = 0; i < 51 ; i++)
	{
		dijamant.attack("nekog");
	}
	dijamant.guardGate();
	dijamant.highFivesGuys();
	dijamant.whoAmI();
	return (0);
}
