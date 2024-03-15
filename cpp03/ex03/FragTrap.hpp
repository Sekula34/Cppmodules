#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected: 
		unsigned int _frag_attack;
		unsigned int _frag_energy;
	public :
		//orthodox
		FragTrap();
		FragTrap(const FragTrap& source);
		FragTrap& operator=(const FragTrap& source);
		~FragTrap();

		FragTrap(std::string name);
		void highFivesGuys(void);
};

#endif
