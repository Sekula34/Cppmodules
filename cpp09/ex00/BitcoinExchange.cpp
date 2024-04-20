#include "BitcoinExchange.hpp"
#include <string>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string inputFileName) :
_inputFileName(inputFileName)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source):
_inputFileName(source._inputFileName)
{
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	(void) source;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}
