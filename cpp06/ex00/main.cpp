#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>

int main()
{
	try 
	{
		ScalarConverter::convert("34.9");
		std::cout << "Hej from main" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr<<e.what() << std::endl;
		return 1;
	}
	return 0;

}
