#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	(void) source;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source):
_inputFileName(source._inputFileName)
{

}
//function that tries to open input file and check first line
//throw exception if open failed or file does not begin with
void BitcoinExchange::_openInputFile()
{
	_inFile.open(_inputFileName.c_str(), std::fstream::in);
	if(_inFile.fail())
		throw std::runtime_error("Opening file failed");
	std::cout << "File opened succesfully" << std::endl;
}
BitcoinExchange::BitcoinExchange(std::string inputFileName):
_inputFileName(inputFileName)
{
	_openInputFile();
}

BitcoinExchange::~BitcoinExchange()
{

}
