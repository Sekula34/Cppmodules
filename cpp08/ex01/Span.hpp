#ifndef SPAN_HPP
# define SPAN_HPP
#include <exception>
# include <vector>

typedef std::vector<int>::iterator myIterator;

class Span
{
	private :
		unsigned int N;
		std::vector<int> myVector;

		int _findSmallestDiff();

	public:
	//orthodox
	Span(void);
	Span(const Span& source);
	Span& operator=(const Span& source);
	~Span();

	Span(unsigned int n);
	
	void addNumber(int number);
	void addManyNumbers(myIterator begin, myIterator end);
	int shortestSpan();
	int longestSpan();
	void printVector(void) const;

	class SpanOverflowException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};

	class TooSmallForSpanException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	} ;
};

#endif
