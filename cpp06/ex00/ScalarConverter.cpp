#include "ScalarConverter.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

char ScalarConverter::_cValue;

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

//throw runtime error if parameter is empty
//return false if parameter size is not 1
//set _cValue and return true if it is true
bool ScalarConverter::_isParameterChar(std::string parameter)
{
	if(parameter.empty() == true)
		throw std::runtime_error("Paramteter is empty in _isParameterChar function");
	if(parameter.size() != 1)
		return (false);
	_cValue = parameter[0];
	return (true);
}

void ScalarConverter::convert(std::string parameter)
{
	if(parameter.empty() == true)
		throw std::runtime_error("Parameter in convert is empty");
	if(_isParameterChar(parameter) == true)
	{
		std::cout << "Parameter is char " <<_cValue << std::endl;
	}
	else
	{
		std::cout << "Parameter is not char [" << _cValue <<"]" <<std::endl;
	}

}
