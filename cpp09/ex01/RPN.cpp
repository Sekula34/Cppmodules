#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <stack>
#include <iostream>
RPN::RPN(void)
{

}

RPN::RPN(const RPN& source)
{
	(void) source;
}

RPN& RPN::operator=(const RPN& source)
{
	(void) source;
	return (*this);
}

RPN::~RPN()
{

}

//remove leading spaces
//check if every other character is space or digit/operator
//last character needs to be operator
//throw InvalidInput exception if something is wrong
void RPN::_checkFormatInput(std::string& input)
{
	_removeSpaces(input);
	for(size_t i = 0; i < input.size(); i++)
	{
		if(i % 2 == 0)
		{
			if(!std::isdigit(input[i]) && !_isValidOperator(input[i]))
				throw InvalidInputException();
		}
		else 
		{
			if(input[i] != ' ')
				throw InvalidInputException();
		}
	}
	if(_isValidOperator(input[input.size() - 1]) == false)
		throw InvalidInputException();
}

//check if char c is  + - * /
//true if it is 
//false if it is not
bool RPN::_isValidOperator(char c)
{
	const char validOperator[] ={'+', '-', '*', '/'};
	size_t size = sizeof(validOperator) / sizeof(char);
	for(size_t i = 0; i < size; i++)
	{
		if(c == validOperator[i])
			return true;
	}
	return false;
}

//remove leading and trailing spaces from input
void RPN::_removeSpaces(std::string& input)
{
	size_t i(0);
	while(std::isspace(input[i]))
	{
		input.erase(0,1);
		if(input.empty() == true)
		{
			std::cerr<<"Input is empty" << std::endl;
			throw InvalidInputException();
		}
	}
	i = input.size() -1;
	while(std::isspace(input[i]))
	{
		input.erase(i ,1);
		i--;
		if(input.empty() == true)
		{
			std::cerr<<"Input is empty" << std::endl;
			throw InvalidInputException();
		}
	}
}

long RPN::calculate(std::string ReversePolishNotation)
{
	std::stack<long> myStack;
	if(ReversePolishNotation.empty())
		throw InvalidInputException();
	return 34;
}

const char* RPN::InvalidInputException::what() const throw()
{
	return ("Exception: Invalid input");
}
