#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <ctime>
#include <fstream>
#include <map>
# include <string>

class BitcoinExchange
{
	private:

		const std::string _inputFileName;
		std::ifstream _inFile;
		std::map<std::time_t, double> _dataBaseMap;

		//orthodox1
		BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		
		void _openInputFile(void);
		void _fillMap(void);

	public:
		//orthodox2
		BitcoinExchange(std::string inputFileName);
		BitcoinExchange(const BitcoinExchange& source);
		~BitcoinExchange();
};

#endif
