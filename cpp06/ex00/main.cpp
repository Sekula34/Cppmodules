#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>


void test0(std::string parameter)
{
	ScalarConverter::convert(parameter);
}

int main()
{
	try 
	{
		test0("\n");
		std::cout << "Hej from main" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr<<e.what() << std::endl;
		return 1;
	}
	return 0;

}
