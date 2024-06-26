#include "Zombie.hpp"
#include <sstream>
#include <iostream>

//test for proving newZombie works
void test0()
{
	Zombie *hipi;

	hipi = newZombie("Hipi The Zombie");
	hipi->announce();
	delete (hipi);
}
//test for proving random chump works
void test1()
{
	randomChump("Totaly random Zombie name");
}

int main()
{
	test0();
	test1();
	Zombie *hipyZ;
	hipyZ = newZombie("hipiz");
	hipyZ->announce();
	randomChump("Foo");

	std::cout << "Creating 10 zombies on stack that would immediatly die" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::ostringstream oss;
		oss << i;

		std::string name = "Zombie" + oss.str();
		randomChump(name);
	}
	std::cout << std::endl;
	std::cout << "Creating 10 zombies on heap and they will die when i say so" << std::endl;
	Zombie *Zombiearray[10];
	for(int i = 0; i < 10; i++)
	{
		std::ostringstream oss;
		oss << i;
		std::string name = "HeapyZ" + oss.str();
		Zombiearray[i] = newZombie(name);
		Zombiearray[i]->announce();

	}
	delete hipyZ;
	for (int i = 0; i < 10; i++)
	{
		delete Zombiearray[i];
	}
	return (0);
}
