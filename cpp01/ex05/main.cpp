#include "Harl.hpp"
#include <iostream>

void printMenu(void)
{
	std::cout << "Enter the level of complain: "<< std::endl;
	std::cout << "\tDEBUG" << std::endl;
	std::cout << "\tINFO" << std::endl;
	std::cout << "\tWARNING" << std::endl;
	std::cout << "\tERROR" << std::endl;
}

int main()
{
	std::string lvlComplain;
	Harl karen;
	
	printMenu();
	while(getline(std::cin, lvlComplain))
	{
		karen.complain(lvlComplain);
		printMenu();
	}
	return (0);
}
