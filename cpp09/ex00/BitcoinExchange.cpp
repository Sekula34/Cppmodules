#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>

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

//check if comma exist and if there is only one comma
//throw InvalidDataBaseException if there is no comma or more than one
void BitcoinExchange::_checkCsvComma(std::string& line, size_t& lineNumber) const
{
	size_t commaPos;
	size_t commaPosB;

	commaPos = line.find_first_of(',');
	commaPosB = line.find_last_of(',');
	if(commaPos == std::string::npos || commaPos != commaPosB)
	{
		std::cerr << "Multiple or no comma seperator in file: " << DATABASENAME;
		std::cerr << " in line " << lineNumber << std::endl;
		throw InvalidDataBaseException();
	}
}

void BitcoinExchange::_checkCsvData(std::string& line, size_t& lineNumber) const 
{
	_checkCsvComma(line, lineNumber);
	std::string datePart;
	std::string valuePart;
	size_t commaPos = line.find_first_of(',');
	datePart = line.substr(0,commaPos);
	valuePart = line.substr(commaPos + 1);
	std::cout <<"date part is :" << datePart << std::endl;
	std::cout <<"Value part is :" << valuePart << std::endl;
	_checkDateFormat(datePart);
}

//check if every line in .csv(database) file is valid
//file must start with header date, exchange_rate
//every other line must be correct format
//throw InvalidDatabaseFile exception if something went wrong
void BitcoinExchange::_checkCsvFile(std::ifstream& dataBase)
{
	std::string fileLine;
	size_t lineNum(1);
	while(std::getline(dataBase, fileLine))
	{
		if(lineNum == 1)
		{
			_checkCsvHeader(fileLine);
		}
		else
		{
			_checkCsvData(fileLine, lineNum);
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

//check if string Date is in format 2009-01-02 aka year, MONTH, DAte
//return true if it is 
//return false if it is not
bool BitcoinExchange::_checkDateFormat(std::string& stringDate) const
{
	std::string year;
	std::string month;
	std::string day;

	size_t numberOfMinus(0);
	if(stringDate.empty())
		return (false);
	numberOfMinus = _getNumberofChar(stringDate, '-');
	if(numberOfMinus != 2)
		return (false);
	year = stringDate.substr(0,stringDate.find('-'));
	size_t posMinus2 = stringDate.find('-',year.size() + 1);
	month = stringDate.substr(year.size() + 1, posMinus2 - (year.size() + 1));
	day = stringDate.substr(year.size() + month.size() + 2, stringDate.npos);

	std::cout << "Year is " << year <<std::endl;
	std::cout << "Month is " << month <<std::endl;
	std::cout << "Day is " << day <<std::endl;
	_checkDate(year, month, day);
	return true;
}

//check if year month and day are digit
//return false if it is not
bool BitcoinExchange::_checkDate(std::string& year, std::string& month, std::string& day) const
{
	if(_isStringDigit(year) == false || _isStringDigit(month) == false || _isStringDigit(day) == false)
		return (false);
	int comparingYear = _stringToInt(year);
	int comparingMonth = _stringToInt(month);
	int comparingDay = _stringToInt(day);

	std::cout << "Year as int is " << comparingYear << std::endl;
	std::cout << "Month as int is " << comparingMonth << std::endl;
	std::cout << "Day as int is " << comparingDay << std::endl;

	return true;
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
	_checkCsvFile(dataFile);
}

//count the number of c in word
//return 0 or number of char c
size_t BitcoinExchange::_getNumberofChar(std::string word, char c) const
{
	size_t cOccur(0);
	for(size_t i = 0; i < word.size(); i++)
	{
		if(word[i] == c)
			cOccur++;
	}
	return (cOccur);

}

//check if every char c in word is digit
//return true if it is, fales if is not
bool BitcoinExchange::_isStringDigit(std::string& word) const
{
	for(size_t i = 0; i < word.size(); i++)
	{
		if(!std::isdigit(word[i]))
			return false;
	}
	return (true);
}

bool BitcoinExchange::_isDateValid(int year, int month, int day) const
{
	const std::time_t current = std::time(0);
	int currentYear = std::localtime(&current)->tm_year + 1900;
	if(year > currentYear)
		return false;
	if(month < 1 || month > 12)
		return false;
	
}
//function that tries to open input file and check first line
//throw exception if open failed or file does not begin with
void BitcoinExchange::_openInputFile()
{
	_inFile.open(_inputFileName.c_str(), std::fstream::in);
	if(_inFile.fail())
		throw std::runtime_error("Opening input file failed");
}

int BitcoinExchange::_stringToInt(std::string& word) const
{
	int value;
	std::stringstream ss(word);
	if(!(ss >> value))
		throw std::runtime_error("Stringstream failed");
	return (value);
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
	return ("Exception: Data in DataBase is in invalid format");
}
