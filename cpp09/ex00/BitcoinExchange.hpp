#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <fstream>
# include <string>

class BitcoinExchange
{
	private:

		const std::string _inputFileName;
		std::ifstream _inFile;

		//orthodox1
		BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		
		void _openInputFile(void);

	public:
		//orthodox2
		BitcoinExchange(std::string inputFileName);
		BitcoinExchange(const BitcoinExchange& source);
		~BitcoinExchange();
};

#endif
