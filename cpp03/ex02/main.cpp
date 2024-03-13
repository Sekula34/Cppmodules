#include "ScavTrap.hpp"

int main()
{
	ScavTrap pokemon("pikachu");
	for(int i = 0 ; i < 50; i++)
	{
		pokemon.attack("Babu rogu");
	}
	pokemon.attack("jednom previse");
	pokemon.guardGate();
	return (0);

}
