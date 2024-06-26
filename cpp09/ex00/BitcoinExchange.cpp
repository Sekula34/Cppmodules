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
	if(_checkDateFormat(datePart) == false)
	{
		std::cerr <<"Invalid date in file "<< DATABASENAME << " in line: "<< lineNumber << std::endl; 
		throw InvalidDataBaseException();
	}
	if(_checkStringValue(valuePart) == false)
	{
		std::cerr <<"Invalid value in file " << DATABASENAME << " in line: "<< lineNumber << std::endl;
		throw InvalidDataBaseException();
	}
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
//perform additional check for date to make sure it is valid
//leap year in future and so on
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

	if(_checkDate(year, month, day) == false)
		return false;
	return true;
}

//check if year month and day are digit
//check if date is Valid in terms of is it in future and leapyear limits and so on
//return false if it is not
bool BitcoinExchange::_checkDate(std::string& year, std::string& month, std::string& day) const
{
	if(_isStringDigit(year) == false || _isStringDigit(month) == false || _isStringDigit(day) == false)
		return (false);
	int comparingYear = _stringToInt(year);
	int comparingMonth = _stringToInt(month);
	int comparingDay = _stringToInt(day);
	if(_isDateValid(comparingYear, comparingMonth, comparingDay) == false)
		return false;
	return true;
}


//check if First line in header is same as defined in INPUTHEADER
//if it is empty or different that that throw InvalidInputFileException
void BitcoinExchange::_checkInputHeader(const std::string& firstLine) const
{
	if(firstLine.empty())
	{
		std::cerr <<"Header of Input file:" <<_inputFileName <<" is empty, ";
		std::cerr <<"But it should be " << INPUTHEADER << std::endl;
		throw InvalidInputFileException();
	}
	if(firstLine != INPUTHEADER)
	{
		std::cerr << "Invalid header in "<< _inputFileName <<std::endl;
		std::cerr << "Expected header: [" << INPUTHEADER <<"]"<< std::endl;
		std::cerr << "Provided header: [" << firstLine <<"]"<< std::endl;
		throw InvalidInputFileException();
	}
}

//check if line foromat is 2011-01-09 | 1
// Error: not a positive number.
// Error: bad input => 2001-42-42
// Error: too large a number.
//store value in &value
bool BitcoinExchange::_checkInputLineFormat(const std::string& line, double& value) const
{
	std::string datePart;
	std::string valuePart;
	if(line.empty())
	{
		std::cerr << "Error: bad input => " << "[EMPTY_LINE]" << std::endl;
		return false;
	}
	size_t posOfPipe = line.find(" | ", 0);
	size_t nOfPipe = _getNumberofChar(line, '|');
	if(nOfPipe != 1 || posOfPipe == 0 || posOfPipe + 1 == line.size())
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	datePart = line.substr(0, posOfPipe);
	//std::cout << "Date part in line " << line << " is [" << datePart <<"]" <<std::endl;
	if(_checkDateFormat(datePart) == false)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	valuePart = line.substr(posOfPipe  + 3);
	//std::cout << "Value part is [" << valuePart <<"]" <<std::endl;
	if(_checkStringValue(valuePart, value) == false)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	if(value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if(value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

//check if value is empty, have more than 1 dots
//check if everyhing is digit 
//put value in double and check if it is bigger or equal 0
//if any check failed return false 
//if all ok return true
bool BitcoinExchange::_checkStringValue(std::string value) const 
{
	if(value.empty())
		return (false);
	size_t numOfDots = _getNumberofChar(value, '.');
	if(numOfDots > 1)
		return (false);
	if(numOfDots == 0 && _isStringDigit(value) == false)
		return (false);
	if(numOfDots == 1)
	{
		std::string wholeNumber = value.substr(0,value.find('.'));
		if(wholeNumber.empty())
			return false;
		std::string decimalPart = value.substr(wholeNumber.size() + 1);
		if(decimalPart.empty())
			return false;
		if(_isStringDigit(wholeNumber) == false || _isStringDigit(decimalPart) == false)
			return (false);
	}
	double dValue = _stringToDouble(value);
	if(dValue < 0)
		return false;
	return true;
}

//check if value is empty, have more than 1 dots
//check if everyhing is digit 
//put value in double do not check if dValue is less than 0 in this case
//if any check failed return false 
//if all ok return true
//store value in dValue
bool BitcoinExchange::_checkStringValue(std::string value, double& dValue) const 
{
	if(value.empty())
		return (false);
	size_t numOfDots = _getNumberofChar(value, '.');
	if(numOfDots > 1)
		return (false);
	if(numOfDots == 0 && _isStringDigit(value, true) == false)
		return (false);
	if(numOfDots == 1)
	{
		std::string wholeNumber = value.substr(0,value.find('.'));
		if(wholeNumber.empty())
			return false;
		std::string decimalPart = value.substr(wholeNumber.size() + 1);
		if(decimalPart.empty())
			return false;
		if(_isStringDigit(wholeNumber) == false || _isStringDigit(decimalPart) == false)
			return (false);
	}
	dValue = _stringToDouble(value);
	return true;
}


//function that open database
//check if everyhing in database file is in valid format
//fill map 
//it anything fails in this error will be thrown  
//possible error std::runtime, InvalidDataBaseException
void BitcoinExchange::_fillMap(void)
{
	std::ifstream dataFile;
	size_t i(0);

	dataFile.open(DATABASENAME, std::fstream::in);
	if (dataFile.fail())
	{
		std::cerr<<"Canot open/find file in current folder with name " << DATABASENAME << std::endl;
		throw std::runtime_error("Open failed");
	}
	_checkCsvFile(dataFile);
	std::string line;
    dataFile.clear();
    dataFile.seekg(0, std::ios::beg);
	while(std::getline(dataFile,line))
	{
		if(i != 0)
		{
			std::string key = line.substr(0,line.find(','));
			std::string sValue = line.substr(key.size() + 1);
			double dValue = _stringToDouble(sValue);
			_dataBaseMap[key]=dValue;
		}
		i++;
	}
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
//check if every char c in word is digit
//return true if it is, fales if is not
//if negative is true ignore first minus
bool BitcoinExchange::_isStringDigit(std::string& word, bool negative) const
{
	for(size_t i = 0; i < word.size(); i++)
	{
		if(negative == true)
		{
			if(i == 0 && word[0] == '-')
				continue;
		}
		if(!std::isdigit(word[i]))
			return false;
	}
	return (true);
}

//check if year is leap and determine if day is between 1 and 30/31/28/29 depending on month and year
bool BitcoinExchange::_isDayValid(int& day, int& month, int& year) const
{
	int maxDay;
	switch (month)
	{
		case 2:
		{
			if(_isLeapYear(year) == true)
				maxDay = 29;
			else 
				maxDay = 28;
			break;
		}
		case 4:
		{
		}
		case 6:
		{
		}
		case 9:
		{
		}
		case 11:
		{
			maxDay = 30;
			break;
		}
		default:
		{
			maxDay = 31;
			break;
		}
	}
	if(day < 1 || day > maxDay)
		return false;
	return true;
}


bool BitcoinExchange::_isLeapYear(int year) const
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
        return true;
    }
	return false;
}

//check if date is valid 
//valid date have year month and day within limits and it is not in future 
//return true if date is valid
//return false if any check fail
bool BitcoinExchange::_isDateValid(int& year, int& month, int& day) const
{
	const std::time_t current = std::time(0);
	int currentYear = std::localtime(&current)->tm_year + 1900;
	int currentMonth = std::localtime(&current)->tm_mon + 1;
	int currentDay = std::localtime(&current)->tm_mday;
	if(year > currentYear)
		return (false);
	if(month < 1 || month > 12)
		return (false);
	if(_isDayValid(day, month, year) == false)
		return false;
	//check if i am in future
	if(currentYear == year)
	{
		if(month > currentMonth)
		{
			return false;
		}
		else if(month == currentMonth && day > currentDay)
		{
			return false;
		}
	}
	return true;

}

//function that tries to open input file and check first line
//throw exception if open failed or file does not begin with
//open file is store in &inFile
void BitcoinExchange::_openInputFile(std::ifstream& inFile)
{
	inFile.open(_inputFileName.c_str(), std::fstream::in);
	if(inFile.fail())
		throw std::runtime_error("Opening input file failed");
}
void BitcoinExchange::_processInputFile(void)
{
	size_t i(1);
	std::ifstream inFile;
	_openInputFile(inFile);
	 std::string oneLine;
	while(std::getline(inFile, oneLine))
	{
		if(i == 1)
		{
			_checkInputHeader(oneLine);
		}
		else 
		{
			_processInputLine(oneLine);
			//proccessLine
			//checkLine
		}
		i++;
		//std::cout << oneLine << std::endl;
	}
}

//process one Line of input
//perform all checks
//if all checks are good print 
//2011-01-03 => 3 = 0.9
void BitcoinExchange::_processInputLine(const std::string& line)
{
	std::string datePart;
	double value;
	//std::cout << "Line to process:" << line << std::endl;
	if(_checkInputLineFormat(line, value) == false)
		return;
	//std::cout << "Line to process: " << line << std::endl;
	datePart = line.substr(0, line.find(" | "));
	//_dataBaseMap[datePart] = 2;
	//std::cout << "data " << _dataBaseMap[datePart] << std::endl;
	std::map<std::string, double>::iterator it;
	it = _dataBaseMap.lower_bound(datePart);
	if(it == _dataBaseMap.begin() && it->first != datePart)
	{
		std::cerr<<"Error: No data for" << datePart << std::endl;
		return;
	}
	if(it->first != datePart)
		it--;
	std::cout << datePart <<" => " << value << " = " << (value * it->second) << std::endl;
}

//reuturn string as integer 
//throw std::runtime error if stringsteam to value failed
int BitcoinExchange::_stringToInt(std::string& word) const
{
	int value;
	std::stringstream ss(word);
	if(!(ss >> value))
		throw std::runtime_error("Stringstream failed");
	return (value);
}

double BitcoinExchange::_stringToDouble(std::string& value) const 
{
	double dValue;
	std::stringstream ss(value);
	ss >> dValue;
	if(ss.fail())
		throw std::runtime_error("stringstream to double failed");
	return dValue;
}

BitcoinExchange::BitcoinExchange(std::string inputFileName):
_inputFileName(inputFileName)
{
	std::ifstream inFile;
	_openInputFile(inFile);
	inFile.close();
	_fillMap();
	if(_dataBaseMap.size() < 1)
	{
		std::cerr<<"Database is empty" << std::endl;
		throw InvalidDataBaseException();
	}
	_processInputFile();
}

BitcoinExchange::~BitcoinExchange()
{
}


const char* BitcoinExchange::InvalidDataBaseException::what() const throw()
{
	return ("Exception: Data in DataBase is in invalid format");
}

const char* BitcoinExchange::InvalidInputFileException::what() const throw()
{
	return("Exception: Invalid Input File");
}
