#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>
# include <exception>

class Zombie
{
	private:
		std::string name;
	public :
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
