#include "Harl.hpp"

void printMenu(void)
{
	std::cout << "Enter the level of complain: "<< std::endl;
	std::cout << "\t 1 -Debug" << std::endl;
	std::cout << "\t 2 -Info" << std::endl;
	std::cout << "\t 3 -Warning" << std::endl;
	std::cout << "\t 4 -Error" << std::endl;
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
