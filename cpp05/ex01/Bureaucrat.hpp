#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <string>
# define HIGHESTGRADE 1
# define LOWESTGRADE 150

class Form;

class Bureaucrat 
{
	private :
		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(std::string name, int grade);
		//orthodox
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat& operator=(const Bureaucrat& source);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void increaseGrade(void);
		void increaseGrade(int increment);
		void decreaseGrade(void);
		void decreaseGrade(int decrement);

		void signForm(Form &formToSign);

		class GradeTooHightException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& birokrat);

#endif
