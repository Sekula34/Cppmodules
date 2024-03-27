#ifndef AFORM_HPP
# define AFORM_HPP
# include <exception>
# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm 
{
	private :
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

		void _checkGrades() const;

	public :

		//orthodox
		AForm();
		AForm(const AForm& source);
		AForm& operator=(const AForm& source);
		virtual ~AForm();

		AForm(std::string name, int gradeToSign, int gradeToExecute);

		virtual void execute(Bureaucrat const & executor) const = 0;

		void requiredGradeCheck(int grade, int requiredGrade) const;
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

		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& forma);

#endif
