#ifndef FORM_HPP
# define FORM_HPP
# include <exception>
# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class Form 
{
	private :
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

		void _checkGrades() const;
		void _requiredGradeCheck(int grade, int requiredGrade);

	public :

		//orthodox
		Form();
		Form(const Form& source);
		Form& operator=(const Form& source);
		~Form();

		Form(std::string name, int gradeToSign, int gradeToExecute);

		//getters for all attributes
		std::string getName() const;
		bool getIsSgined() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		//subjectfunctions
		void beSigned(const Bureaucrat& biro);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& forma);

#endif
