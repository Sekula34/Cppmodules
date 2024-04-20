#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>

class BitcoinExchange
{
	private:

		const std::string _inputFileName;
		//orthodox1
		BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange& source);

	public:
		//orthodox2
		BitcoinExchange(std::string inputFileName);
		BitcoinExchange(const BitcoinExchange& source);
		~BitcoinExchange();
};

#endif
