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

		static std::string _removeLeadingspaces(std::string parameter);
		static std::string _removeTrailingSpaces(std::string parameter);

		static int _getNumberOfDecimalDot(std::string parameter);
		static size_t _getPosOfFirstDigit(std::string parameter);
		static bool _validNumberChecker(std::string parameter);

		static bool _isParameterChar(std::string parameter);
		static bool _isParameterInt(std::string parameter);
		static bool _isParameterFloat(std::string paramter);
		static bool _isParameterDouble(std::string paramter);

		static originalType _getStringOriginalType(std::string parameter);
		static void _convertFromType(char c);
		static void _convertFromType(int i);
		static void _convertFromType(float f);
		static void _convertFromType(double d);

		static void _printAllTypes(void);



	public:	
		static void convert(std::string parameter);
};

#endif
