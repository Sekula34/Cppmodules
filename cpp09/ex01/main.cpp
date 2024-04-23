#include <iostream>
#include "RPN.hpp"

int main()
{
	std::string input(" 8 9 * 9 - 9 - 9 - 4 - 1 +-       ");
	try 
	{
		//RPN::_checkFormatInput(input);
	}
	catch(RPN::InvalidInputException &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << "Input is good [" << input << "]" << std::endl;
	return 0;
}
