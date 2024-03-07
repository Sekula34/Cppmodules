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
	enum levels{DEBUG = 1, INFO, WARNING, ERROR};
	void (Harl::*funcPtr)(void) = NULL;
	std::istringstream iss(level);
	int intLevel;
	iss >> intLevel;
	if (iss.fail())
	{
		std::cerr << "Conversion failed." << std::endl;
		return ;
	}
	switch (intLevel)
	{
		case DEBUG:
		{
			funcPtr = &Harl::debug;
			break;
		}
		case INFO:
		{
			funcPtr = &Harl::info;
			break;
		}
		case WARNING:
		{
			funcPtr = &Harl::warning;
			break;
		}
		case ERROR:
		{
			funcPtr = &Harl::error;
			break;
		}
		default:
		{
			std::cerr <<"ERROR THIS IS KAREN LEVEL. Harl support only DEBUG, INFO, WARNING, ERROR" << std::endl;
			return ;
		}
	}
	(this->*funcPtr)();
}
