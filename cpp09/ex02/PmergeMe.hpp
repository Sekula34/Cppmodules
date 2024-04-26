#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <cstddef>
# include <vector>

class PmergeMe
{
	private :
		static unsigned int _comparisonCounter;

		void _binaryInsertion(int valueToInsert, std::vector<int>& vec);
		unsigned int _getJacobsthalNumber(int n);
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		std::vector<int> _getBInsertSequence(int numberOfPairs, bool lastBAlone);
		void _insertRestOfSequence(std::vector<int>& bSequence, size_t finalSizeOfVector);

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
