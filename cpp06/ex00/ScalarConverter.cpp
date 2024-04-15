#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

char ScalarConverter::_cValue;
int ScalarConverter::_iValue;
float ScalarConverter:: _fValue;
double ScalarConverter:: _dValue;

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

//removing leading spaces from parameter and return in clean
//throw error if cleanString is empty or parameter is empty
std::string ScalarConverter::_removeLeadingspaces(std::string parameter)
{
	std::string cleanString (parameter);

	while(true)
	{
		if(cleanString[0] == ' ')
		{
			cleanString.erase(0,1);
		}
		else 
		{
			break;
		}
	}
	if(cleanString.empty() == true)
		throw std::runtime_error("after removing spaces there is nothing");
	return (cleanString);
}

//remove spaces from end
//throw error if string is empty before or after cleaning
std::string ScalarConverter::_removeTrailingSpaces(std::string parameter)
{
	std::string cleanString (parameter);
	
	while(true)
	{
		if(cleanString[cleanString.size() - 1] == ' ')
		{
			cleanString.erase(cleanString.size() - 1, 1);
		}
		else  
		{
			break;
		}
	}
	if(cleanString.empty() == true)
		throw std::runtime_error("after removing spaces at the end there is nothing");
	return (cleanString);
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
		if(std::isdigit(parameter[i]))
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
				if(onlyNumberpart[i-1] == '.')
					return false;
				break;
			}
			return false;
		}
	}
	if(onlyNumberpart[onlyNumberpart.size() - 1] == '.')
		return false;
	if(_getNumberOfDecimalDot(onlyNumberpart) > 1)
		return false;
	return true;
}

bool ScalarConverter::_specialCasesFloat(std::string parameter)
{

	if(parameter == "-inff")
	{
		_fValue = -std::numeric_limits<float>::infinity();
		return true;
	}
	else if (parameter == "+inff")
	{
		_fValue = std::numeric_limits<float>::infinity();
		return true;
	}
	return false;
}

bool ScalarConverter::_specialCasesDouble(std::string parameter)
{
	if(parameter == "-inf")
	{
		_dValue = -std::numeric_limits<double>::infinity();
		return true;
	}
	else if(parameter == "+inf")
	{
		_dValue = std::numeric_limits<double>::infinity();
		return true;
	}
	else if(parameter == "nan")
	{
		_dValue = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	return false;
}

//throw runtime error if parameter is empty
//return false if parameter size is not 1
//set _cValue and return true if it is true
bool ScalarConverter::_isParameterChar(std::string parameter)
{
	if(parameter.empty() == true)
		throw std::runtime_error("Paramteter is empty in _isParameterChar function");
	if(parameter.size() != 1 || std::isdigit(parameter[0]))
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
	if(_getNumberOfDecimalDot(parameter) != 0 || parameter[parameter.size() - 1] == 'f')
		return false;
	std::stringstream ss(parameter);
	ss >> _iValue;
	if(ss.fail() == true)
		return false;
	return true; 
}

//check if parameter is float
//to be float it needs to end with 'f'
//prerequisite is to not be empty, and to be number 
//true if it is float , false if it is not
bool ScalarConverter::_isParameterFloat(std::string parameter)
{
	if(_validNumberChecker(parameter) != true)
		return false;
	if(parameter[parameter.size() - 1] != 'f')
	{
		return false;
	}
	std::stringstream ss (parameter);
	ss >> std::setprecision(7)>> _fValue;
	if(ss.fail() == true)
		throw std::runtime_error("Stringstream failed");
	return true;
}

//check if parameter is double
//to be double it should not end with 'f'
//prerequisite is to not be empty, and to be number 
//true if it is double , false if it is not
bool ScalarConverter::_isParameterDouble(std::string parameter)
{
	if(_validNumberChecker(parameter) != true)
		return false;
	if(parameter[parameter.size() - 1] == 'f')
	{
		return false;
	}
	std::stringstream ss (parameter);
	ss >>std::setprecision(15) >>  _dValue;
	if(ss.fail() == true)
		throw std::runtime_error("Stringstream failed");
	return true;
}

//check if parameter is CHAR INT FLOAT OR DOUBLE
//throw runtime error if it is not valid number or if it is none of the options
originalType ScalarConverter::_getStringOriginalType(std::string parameter)
{
	if(_isParameterChar(parameter) == true)
		return CHAR;
	parameter = _removeLeadingspaces(parameter);
	parameter = _removeTrailingSpaces(parameter);
	if(_specialCasesDouble(parameter) == true)
		return DOUBLE;
	if(_specialCasesFloat(parameter) == true)
		return FLOAT;
	if(_validNumberChecker(parameter) == false)
		throw std::runtime_error("Parameter(string) is not char and it is not valid number either");
	if(_isParameterInt(parameter) == true)
		return INT;
	if(_isParameterFloat(parameter) == true)
		return FLOAT;
	if(_isParameterDouble(parameter) == true)
		return DOUBLE;
	throw std::runtime_error("Parameter is not char nor int nor float, nor double");
}

void ScalarConverter::_convertFromType(char c)
{
	_iValue = static_cast<int>(c);
	_fValue = static_cast<float>(c);
	_dValue = static_cast<double>(c);
}

void ScalarConverter::_convertFromType(int i)
{
	_cValue = static_cast<char>(i);
	_fValue = static_cast<float>(i);
	_dValue = static_cast<double>(i);
}

void ScalarConverter::_convertFromType(float f)
{
	_cValue = static_cast<char>(f);
	_iValue = static_cast<int>(f);
	_dValue = static_cast<double>(f);
}

void ScalarConverter::_convertFromType(double d)
{
	_cValue = static_cast<char>(d);
	_iValue = static_cast<int>(d);
	_fValue = static_cast<float>(d);
}


void ScalarConverter::_printChar(void)
{
	std::cout <<"char: ";
	if(std::isinf(_dValue) || std::isinf(_fValue) || std::isnan(_dValue))
	{
		std::cout <<"impossible" << std::endl;
		return ;
	}
	if(std::isprint(_cValue))
	{
		std::cout << "'"<< _cValue <<"'" <<std::endl;
		return;
	}
	else  
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
}

void ScalarConverter::_printInt(void)
{
	std::cout <<"int: ";
	if(std::isinf(_dValue) || std::isinf(_fValue) || std::isnan(_dValue))
	{
		std::cout <<"impossible" << std::endl;
		return ;
	}
	std::cout << _iValue  << std::endl;
}

void ScalarConverter::_printAllTypes(void)
{
	_printChar();
	_printInt();
	std::cout << "float: " << std::fixed << std::setprecision(1)<<_fValue << "f"<< std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)<< _dValue << std::endl;
}

void ScalarConverter::convert(std::string parameter)
{
	if(parameter.empty() == true)
		throw std::runtime_error("Parameter in convert is empty");
	originalType stringType;

	stringType = _getStringOriginalType(parameter);
	switch (stringType)
	{
		case CHAR :
		{
			_convertFromType(_cValue);
			break;
		}
		case INT :
		{
			_convertFromType(_iValue);
			break;
		}
		case FLOAT :
		{
			_convertFromType(_fValue);
			break ;
		}
		case DOUBLE :
		{
			_convertFromType(_dValue);
			break;
		}
		default:
		{
			throw std::runtime_error("No type matched");
		}
	}
	_printAllTypes();
}
