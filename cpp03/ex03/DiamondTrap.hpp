#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private :
		std::string _name;

	public :
		DiamondTrap();
		DiamondTrap(const DiamondTrap& source);
		DiamondTrap& operator=(const DiamondTrap& source);
		~DiamondTrap();

		DiamondTrap(std::string name);
};

#endif
