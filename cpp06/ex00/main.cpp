#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>


void test0(std::string parameter)
{
	std::cout << "Parameter is " << parameter << std::endl;
	ScalarConverter::convert(parameter);
}

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr << "One argument required" << std::endl;
		return 1;
	}
	try 
	{

		ScalarConverter::convert(argv[1]);
		std::cout << "Hej from main" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr<<e.what() << std::endl;
		return 1;
	}
	return 0;

}
