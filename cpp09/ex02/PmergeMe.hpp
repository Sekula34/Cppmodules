#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>

class PmergeMe
{
	private :
		static unsigned int _comparisonCounter;

		void _binaryInsertion(int valueToInsert, std::vector<int>& vec);
		std::vector<int> _getBInsertSequence(int numberOfPairs, bool lastBAlone);
		unsigned int _getJacobsthalNumber(int n);
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		unsigned int getComparisonCounter(void) const;


		struct Compare
		{
        bool operator()(int a, int b) {
            _comparisonCounter++;
            return a < b;
        }
    };


};

#endif
