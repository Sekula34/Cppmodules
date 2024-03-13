#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap 
{
	private :
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public :
		//orthodox
		ClapTrap();
		ClapTrap(const ClapTrap& source);
		ClapTrap& operator=(const ClapTrap& source);
		~ClapTrap();

		ClapTrap(std::string name);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
