#ifndef SPAN_HPP
# define SPAN_HPP
#include <exception>
# include <vector>


class Span
{
	private :
		unsigned int N;
		std::vector<int> myVector;

	public:
	//orthodox
	Span(void);
	Span(const Span& source);
	Span& operator=(const Span& source);
	~Span();

	Span(unsigned int n);
	
	void addNumber(int number);
	void shortestSpan();
	void longestSpan();

	void printVector(void) const;

	class SpanOverflowException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
};

#endif
