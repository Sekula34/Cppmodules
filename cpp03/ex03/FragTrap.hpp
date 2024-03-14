#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private :
	
	protected:
		
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
