#include "RPN.hpp"
#include <cctype>
#include <climits>
#include <cstddef>
#include <stack>
#include <iostream>
#include <stdexcept>

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

void RPN::_operatorFunction(char op, std::stack<long>& myStack)
{
	long result(0);
	if(myStack.size() < 2)
		throw InvalidInputException();
	long secondNumber = myStack.top();
	myStack.pop();
	long firstNumber = myStack.top();
	myStack.pop();
	switch (op)
	{
		case '+' :
		{
			result = firstNumber + secondNumber;
			break;
		}
		case '-' :
		{
			result = firstNumber - secondNumber;
			break;
		}
		case '*' :
		{
			result = firstNumber * secondNumber;
			break;
		}
		case '/' :
		{
			if(secondNumber == 0)
				throw std::runtime_error("Division by zero is not defined");
			result = firstNumber / secondNumber;
			break;
		}
		default:
			throw std::runtime_error("Invalid operator");
	}
	if(result > (long)INT_MAX || result < (long)INT_MIN)
	{
		throw std::runtime_error("Integer overflow");
	}
	myStack.push(result);
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
	long endRes;
	std::stack<long> myStack;
	if(ReversePolishNotation.empty())
		throw InvalidInputException();
	_checkFormatInput(ReversePolishNotation);
	for(size_t i = 0; i < ReversePolishNotation.size(); i++)
	{
		if(std::isdigit(ReversePolishNotation[i]))
		{
			myStack.push(ReversePolishNotation[i] - '0');
		}
		else if(_isValidOperator(ReversePolishNotation[i]))
		{
			_operatorFunction(ReversePolishNotation[i], myStack);
		}
	}
	if(myStack.size() != 1)
		throw InvalidInputException();
	endRes = myStack.top();
	return (endRes);
}

const char* RPN::InvalidInputException::what() const throw()
{
	return ("Exception: Invalid input");
}
