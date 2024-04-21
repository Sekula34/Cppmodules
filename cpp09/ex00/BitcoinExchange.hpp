#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <cstddef>
#include <ctime>
#include <exception>
#include <fstream>
#include <map>
# include <string>

#define CSVHEADER "date,exchange_rate"
#define DATABASENAME "./ignore/ExceptionTriggers/InvalidValue.csv" //change this for testing invalid database etc


class BitcoinExchange
{
	private:

		const std::string _inputFileName;
		std::ifstream _inFile;
		std::map<std::time_t, double> _dataBaseMap;

		//orthodox1
		BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		
		void _checkCsvComma(std::string& line, size_t& lineNumber) const;
		void _checkCsvData(std::string& line, size_t& lineNumber) const;
		void _checkCsvFile(std::ifstream& dataBase);
		void _checkCsvHeader(std::string& firstLine) const;
		bool _checkDateFormat(std::string& stringDate) const;
		bool _checkDate(std::string& year, std::string& month, std::string& day) const;
		bool _checkStringValue(std::string value) const;
		void _fillMap(void);
		size_t _getNumberofChar(std::string word, char c) const;
		bool _isStringDigit(std::string& word) const;
		bool _isDateValid(int& year, int& month, int& day) const;
		bool _isDayValid(int &day, int& month, int& year) const;
		bool _isLeapYear(int year) const;
		void _openInputFile(void);
		int _stringToInt(std::string& word) const;
		double _stringToDouble(std::string& value) const;


	public:
		//orthodox2
		BitcoinExchange(std::string inputFileName);
		BitcoinExchange(const BitcoinExchange& source);
		~BitcoinExchange();

		class InvalidDataBaseException : public std::exception
		{
			public :
				const char* what() const throw();
		};

};

#endif
