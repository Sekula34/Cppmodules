#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>

class PmergeMe
{
	private :
		static unsigned int _comparisonCounter;
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		unsigned int getComparisonCounter(void) const;
		void _binaryInsertion(int valueToInsert, std::vector<int>& vec);


		struct Compare
		{
        bool operator()(int a, int b) {
            _comparisonCounter++;
            return a < b;
        }
    };


};

#endif
