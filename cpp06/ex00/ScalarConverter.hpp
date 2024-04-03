#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter 
{
	private :
		//orthodox
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter& operator=(const ScalarConverter& source);
		~ScalarConverter();

	public:	
		static void convert(std::string parameter);
};

#endif
