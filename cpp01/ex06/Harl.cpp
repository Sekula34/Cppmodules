#include "Harl.hpp"
#include <iostream>

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
	int intLevel = 5;
	if(level.empty() == true)
		return ;
	const std::string validOption[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtrArray[4])(void);
	funcPtrArray[0] = &Harl::debug;
	funcPtrArray[1] = &Harl::info;
	funcPtrArray[2] = &Harl::warning;
	funcPtrArray[3] = &Harl::error;
	for(int i = 0; i < 4; i++)
	{
		if(level == validOption[i])
		{
			intLevel = i;
		}
	}
	switch (intLevel)
	{
		case 0:
		{
			std::cout <<"[ DEBUG ]" <<std::endl;
			(this->*(funcPtrArray[0]))();
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout <<"[ INFO ]" <<std::endl;
			(this->*(funcPtrArray[1]))();
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout <<"[ WARNING ]" <<std::endl;
			(this->*(funcPtrArray[2]))();
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout <<"[ ERROR ]" <<std::endl;
			(this->*(funcPtrArray[3]))();
			std::cout << std::endl;
			break;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
	}
	return ;
}
