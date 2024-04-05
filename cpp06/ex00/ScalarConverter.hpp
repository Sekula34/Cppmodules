#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

enum originalType {CHAR, INT, FLOAT, DOUBLE};

class ScalarConverter 
{
	private :
		//orthodox
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter& operator=(const ScalarConverter& source);
		~ScalarConverter();

		static char _cValue;
		static int _iValue;
		static float _fValue;
		static double _dValue;

		static int _getNumberOfDecimalDot(std::string parameter);
		static size_t _getPosOfFirstDigit(std::string parameter);
		static bool _validNumberChecker(std::string parameter);

		static bool _isParameterChar(std::string parameter);
		static bool _isParameterInt(std::string parameter);
		static bool _isParameterFloat(std::string paramter);
		static bool _isParamterDobule(std::string paramter);


	public:	
		static void convert(std::string parameter);
};

#endif
