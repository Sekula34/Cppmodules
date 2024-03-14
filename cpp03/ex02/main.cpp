#include "FragTrap.hpp"


int main()
{
	std::string name = "jez";
	FragTrap plameniJazavac(name);
	FragTrap kopija = plameniJazavac;
	FragTrap joskopija(plameniJazavac);

	return (0);
}
