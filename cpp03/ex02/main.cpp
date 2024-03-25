#include "FragTrap.hpp"


int main()
{
	std::string name = "jez";
	FragTrap plameniJazavac(name);

	plameniJazavac.highFivesGuys();
	for(int i = 0; i < 50; i++)
	{
		plameniJazavac.attack("pokemona");
		plameniJazavac.beRepaired(1);
		plameniJazavac.takeDamage(100);
	}
	plameniJazavac.beRepaired(3);
	plameniJazavac.highFivesGuys();
	return (0);
}
