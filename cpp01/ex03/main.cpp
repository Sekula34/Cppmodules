#include "Weapon.hpp"
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	// Weapon mac("mac");
	// HumanA mojCovjek("Dragan", mac);
	// mojCovjek.attack();
	// mac.set_type("cekcom");
	// mojCovjek.attack();
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
