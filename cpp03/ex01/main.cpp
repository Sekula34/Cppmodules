#include "ScavTrap.hpp"

int main()
{
	ScavTrap pokemon("pikachu");
	ScavTrap noone;
	for(int i = 0 ; i < 50; i++)
	{
		pokemon.attack("Babu rogu");
	}
	pokemon.attack("jednom previse");
	pokemon.guardGate();
	ScavTrap jeftinakopija(pokemon);
	jeftinakopija.guardGate();
	jeftinakopija.takeDamage(10000000);
	noone.guardGate();
	noone = jeftinakopija;
	noone.guardGate();
	return (0);

}
