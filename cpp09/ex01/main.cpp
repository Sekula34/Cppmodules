#include <exception>
#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Only one argument required" << std::endl;
		return (1);
	}
	try 
	{
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch(RPN::InvalidInputException &e)
	{
		//std::cerr << e.what() << std::endl;
		std::cerr << "Error" << std::endl;
		return (1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
