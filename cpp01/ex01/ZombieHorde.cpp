#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zomb_ptr;

	try
	{
		zomb_ptr = new Zombie[N];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
	for(int i = 0; i < N; i++)
	{
		zomb_ptr[i].set_name(name);
	}
	return (zomb_ptr);
}
