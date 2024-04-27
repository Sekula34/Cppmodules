#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <cstddef>
# include <vector>

struct pair
{
	int a;
	int b;
};

class PmergeMe
{
	private :
		static unsigned int _comparisonCounter;

		//debuggers
		void _printVec(std::vector<int> vec);
		void _printOnePair(pair onePair);
		void _printPairList(std::vector<pair> pairList);

		void				_binaryInsertion(int valueToInsert, std::vector<int>& vec, std::vector<int>::iterator posOfA);
		std::vector<int>	_getBInsertSequence(int numberOfPairs, bool lastBAlone);
		unsigned int		_getJacobsthalNumber(int n);
		std::vector<pair> _getUnsortedPairs(std::vector<int> unsortedVec);
		void				_insertRestOfSequence(std::vector<int>& bSequence, size_t finalSizeOfVector);
		pair			_makeOnePair(int value1, int value2);
		pair			_makeOnePair(int valueB);
	
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		std::vector<int> sortedVec;
		void mergeInsertSort(std::vector<int> unsortedVec);


		unsigned int getComparisonCounter(void) const;
		void printSortedVec(void);

		struct Compare
		{
        bool operator()(int a, int b) {
            _comparisonCounter++;
            return a < b;
        }
    };


};

#endif
