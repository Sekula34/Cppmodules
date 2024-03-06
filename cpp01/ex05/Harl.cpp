#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;

}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
	std::cout << "years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funcPtr)(void) = NULL;
	std::istringstream iss(level);
	int intLevel;
	iss >> intLevel;
	if(iss.fail() == true)
	{
		std::cerr << "Conversion from string to int failed "<< std::endl;
		return ;
	}
	switch (intLevel)
	{
		case 1:
		{
			funcPtr = &Harl::debug;
			break;
		}
		case 2:
		{
			funcPtr = &Harl::info;
			break;
		}
		case 3:
		{
			funcPtr = &Harl::warning;
			break;
		}
		case 4:
		{
			funcPtr = &Harl::error;
			break;
		}
		default:
		{
			std::cerr <<"ERROR THIS IS KAREN LEVEL. Harl support only 1, 2, 3 and 4" << std::endl;
			return ;
		}
	}
	(this->*funcPtr)();
}
