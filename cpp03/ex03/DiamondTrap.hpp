#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string _name;

	public :
		DiamondTrap();
		DiamondTrap(const DiamondTrap& source);
		DiamondTrap& operator=(const DiamondTrap& source);
		~DiamondTrap();

		DiamondTrap(std::string name);
		void attack(std::string enemy);
		void whoAmI();
};

#endif
