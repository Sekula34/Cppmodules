#include "Harl.hpp"
#include <iostream>
int main(int argc, char **argv)
{
	Harl karen;
	if(argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	std::string complainLevel;
	complainLevel = argv[1];
	karen.complain(complainLevel);
	return (0);
}
