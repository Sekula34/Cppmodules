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
		throw std::runtime_error("Opening input file failed");
}

void BitcoinExchange::_fillMap(void)
{
	const std::string dataFileName("data.csv");
	std::ifstream dataFile;

	dataFile.open(dataFileName.c_str(), std::fstream::in);
	if (dataFile.fail())
	{
		std::cerr<<"Canot open/find file in current folder with name " << dataFileName << std::endl;
		throw std::runtime_error("Open failed");
	}
	std::cout <<"database opened" << std::endl;
}
BitcoinExchange::BitcoinExchange(std::string inputFileName):
_inputFileName(inputFileName)
{
	_openInputFile();
	_fillMap();
}

BitcoinExchange::~BitcoinExchange()
{
	_inFile.close();
}
