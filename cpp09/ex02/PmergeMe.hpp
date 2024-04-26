#ifndef PMERGEME_HPP
# define PMERGEME_HPP


class PmergeMe
{
	private :
			unsigned int _comparisonCounter;
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		unsigned int getComparisonCounter(void) const;




};

#endif
