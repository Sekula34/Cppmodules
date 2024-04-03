#include "ScalarConverter.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& source)
{
	(void) source;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& source)
{
	(void) source;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string parameter)
{
	if(parameter.empty() == true)
		throw std::runtime_error("Parameter in convert is empty");
	std::cout << parameter << std::endl;
	const char* c; 

	c = parameter.c_str();
	std::cout << "c is " << c << std::endl;

	int value;
	std::stringstream ss(parameter);
	
	if(ss >> value)
	{
		std::cout << "Int value is " << value << std::endl;
	}
	else 
	{
		throw std::runtime_error("this is imposible");
	}

}
