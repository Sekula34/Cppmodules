#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private :
		std::string _name;
		Weapon *_weaponPtr;
	public :
		HumanB(std::string humanName);
		void attack();
		void setWeapon(Weapon &weaponRef);
};
#endif
