#include "BitcoinExchange.hpp"
#include <cstddef>
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
//check if every line in .csv(database) file is valid
//file must start with header date, exchange_rate
//every other line must be correct format
//throw InvalidDatabaseFile exception if something went wrong
void BitcoinExchange::_checkCsvFile(std::ifstream& dataBase)
{
	std::string fileLine;
	std::cout << "StartReading file" << std::endl;
	size_t lineNum(1);
	while(std::getline(dataBase, fileLine))
	{
		if(lineNum == 1)
		{
			_checkCsvHeader(fileLine);
		}
		else
		{
			//check data seperated by coma
		}
		lineNum ++;
	}
	std::cout << "I read everything" << std::endl;
}
//throw error if first line is empty or not equal to requested headear
void BitcoinExchange::_checkCsvHeader(std::string& firstLine) const
{
	if(firstLine.empty())
	{
		std::cerr <<"Database Header is empty" << std::endl;
		throw InvalidDataBaseException();
	}
	if(firstLine != CSVHEADER)
	{
		std::cerr << "Invalid header in .csv file"<<std::endl;
		std::cerr << "Expected header: [" << CSVHEADER <<"]"<< std::endl;
		std::cerr << "Provided header: [" << firstLine <<"]"<< std::endl;
		throw InvalidDataBaseException();
	}
}

void BitcoinExchange::_fillMap(void)
{
	std::ifstream dataFile;

	dataFile.open(DATABASENAME, std::fstream::in);
	if (dataFile.fail())
	{
		std::cerr<<"Canot open/find file in current folder with name " << DATABASENAME << std::endl;
		throw std::runtime_error("Open failed");
	}
	std::cout <<"database opened" << std::endl;
	_checkCsvFile(dataFile);
}
//function that tries to open input file and check first line
//throw exception if open failed or file does not begin with
void BitcoinExchange::_openInputFile()
{
	_inFile.open(_inputFileName.c_str(), std::fstream::in);
	if(_inFile.fail())
		throw std::runtime_error("Opening input file failed");
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


const char* BitcoinExchange::InvalidDataBaseException::what() const throw()
{
	return ("Data in DataBase is in invalid format");
}
