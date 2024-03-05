#include"Zombie.hpp"

int main()
{
	Zombie *ptr;

	ptr = zombieHorde(10, "Prikaze");
	for(int i = 0; i < 10; i++)
	{
		ptr[i].announce();
	}
	delete [] ptr;

	ptr = zombieHorde(15, "ZiZIZOmbac");
	for(int i = 0; i < 15; i++)
		ptr[i].announce();
	delete [] ptr;
	return (0);
}

