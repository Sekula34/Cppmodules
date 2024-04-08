#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>


void test0(std::string parameter)
{
	std::cout << "Parameter is " << parameter << std::endl;
	ScalarConverter::convert(parameter);
}

int main()
{
	try 
	{
		test0(" 1204.f");
		std::cout << "Hej from main" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr<<e.what() << std::endl;
		return 1;
	}
	return 0;

}
