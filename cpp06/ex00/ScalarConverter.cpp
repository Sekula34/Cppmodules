#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

char ScalarConverter::_cValue;
int ScalarConverter::_iValue;

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

//count number of '.' in string
int ScalarConverter::_getNumberOfDecimalDot(std::string parameter)
{
	int dotCounter (0);

	for(size_t i = 0; i < parameter.size(); i++)
	{
		if(parameter[i] == '.')
			dotCounter++;
	}
	return (dotCounter);
}

//return position of first digit in  string
//throw exception if there is none
size_t ScalarConverter::_getPosOfFirstDigit(std::string parameter)
{
	for(size_t i = 0; i < parameter.size(); i++)
	{
		if(std::isdigit(parameter[i]) == true)
		{
			return (i);
		}
	}
	throw std::runtime_error("Parameter is not number");
}

//check if number part of string is everyhing digit and only one dot
//additional check is performed on last charcter to check if end with f
//if it is valid return true
//if it is not return false 
//only one dot is valid.
bool ScalarConverter::_validNumberChecker(std::string parameter)
{
	size_t posFirstDigit = _getPosOfFirstDigit(parameter);
	std::string onlyNumberpart = parameter.substr(posFirstDigit);

	for(size_t i = 0; i < onlyNumberpart.size(); i++)
	{
		if(std::isdigit(onlyNumberpart[i]) == false && onlyNumberpart[i] != '.')
		{
			if(i + 1 == onlyNumberpart.size() && onlyNumberpart[i] == 'f')
			{
				break;
			}
			return false;
		}
	}
	if(_getNumberOfDecimalDot(onlyNumberpart) > 1)
		return false;
	return true;
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

//throw runtime error if parameter is empty
//return true and set _ivalue if parameter is int
//return false if parameter have . or if ss failed.
bool ScalarConverter::_isParameterInt(std::string parameter)
{
	if(parameter.empty() == true)
		throw std::runtime_error("Parameter is empty");
	if(_getNumberOfDecimalDot(parameter) != 0)
		return false;
	std::stringstream ss(parameter);
	ss >> _iValue;
	if(ss.fail() == true)
		return false;
	return true; 
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
	if(_isParameterInt(parameter) == true)
	{
		std::cout << "Ivalue is [" << _iValue << "]" << std::endl;
	}
	else
	{
		std::cout << "Parameter is not int" << std::endl;
	}
	if(_validNumberChecker(parameter) == true)
	{
		std::cout << "Parameter is number" << std::endl;
	}
	else 
	{
		std::cout << "Parameter is not number" << std::endl;
	}

}
