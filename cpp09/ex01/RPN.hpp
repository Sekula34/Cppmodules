#ifndef RPN_HPP
# define RPN_HPP
#include <exception>
# include <string>

class RPN 
{
	private:
		//orthodox
		RPN();
		RPN(const RPN& source);
		RPN& operator=(const RPN& source);
		~RPN();

		static void _checkFormatInput(std::string& input);
		static bool _isValidOperator(char c);
		static void _removeSpaces(std::string& input);
	public :
		static long calculate(std::string ReversePolishNotation);

		class InvalidInputException : public std::exception
		{
			public :
				const char * what() const throw();
		};
};

#endif
