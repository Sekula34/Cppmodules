#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <cstddef>
#include <ctime>
#include <exception>
#include <fstream>
#include <map>
# include <string>

#define CSVHEADER "date,exchange_rate"
#define DATABASENAME "ignore/ExceptionTriggers/MoreCommas.csv" //change this for testing invalid database etc

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
		void _fillMap(void);
		void _openInputFile(void);


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
