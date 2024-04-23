#include <exception>
#include <iostream>
#include "RPN.hpp"

int main()
{
	std::string input("(1 + 1)");
	try 
	{
		std::cout << RPN::calculate(input) << std::endl;
	}
	catch(RPN::InvalidInputException &e)
	{
		//std::cerr << e.what() << std::endl;
		std::cerr << "Error" << std::endl;
		return 1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	//std::cout << "Input is good [" << input << "]" << std::endl;
	return 0;
}
