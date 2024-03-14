#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

	//orthodox
	public: 
		ScavTrap();
		ScavTrap(const ScavTrap& source);
		ScavTrap& operator=(const ScavTrap& source);
		~ScavTrap();

		ScavTrap(std::string name);
		void guardGate();
};

#endif
