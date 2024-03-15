#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected: 
		unsigned int _scavAttack;
		unsigned int _scavEnergy;
	//orthodox
	public: 
		ScavTrap();
		ScavTrap(const ScavTrap& source);
		ScavTrap& operator=(const ScavTrap& source);
		~ScavTrap();

		ScavTrap(std::string name);
		void guardGate();
		void attack(const std::string& target);
};

#endif
