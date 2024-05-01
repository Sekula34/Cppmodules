#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <cstddef>
# include <vector>
#include <deque>

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
		void _printQue(std::deque<int>& que);
		void _printVec(std::vector<int> vec);
		void _printOnePair(pair onePair);
		void _printPairList(std::vector<pair> pairList);

		void 				_binaryInsertion(int valueToInsert, std::vector<int>& vec, std::vector<int>::iterator posOfA);
		std::vector<int>	_fillUnsortedAs(std::vector<pair> unsortedPairs);
		std::vector<int>	_getBInsertSequence(int numberOfPairs, bool lastBAlone);
		int					_getBmemberOfPair(int aValue, std::vector<pair> unsortedPairs);
		unsigned int		_getJacobsthalNumber(int n);
		std::vector<pair>	_getUnsortedPairs(std::vector<int> unsortedVec);
		void 				_insertBs(std::vector<pair>unsortedPairs);
		void 				_insertRestOfSequence(std::vector<int>& bSequence, size_t finalSizeOfVector);
		pair 				_makeOnePair(int value1, int value2);
		pair 				_makeOnePair(int valueB);


		std::deque<pair> _getUnsortedPairsQue(std::deque<int> unsortedQue);
		void 				_binaryInsertionQue(int valueToInsert, std::deque<int>& que, std::deque<int>::iterator posOfA);
		std::deque<int>	_fillUnsortedAsQue(std::deque<pair> unsortedPairs);
		void 				_insertBsQue(std::deque<pair> unsortedPairs);
		std::deque<int>	_getBInsertSequenceQue(int numberOfPairs, bool lastBAlone);
		void 			_insertRestOfSequenceQue(std::deque<int>& bSequence, size_t finalSizeOfVector);
		int					_getBmemberOfPairQue(int aValue, std::deque<pair> unsortedPairs);
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		std::vector<int>	sortedVec;
		std::deque<int>		sortedQue;

		void			mergeInsertSort(std::vector<int> unsortedVec);
		void 			mergeInsertQue(std::deque<int> unsortedQue);

		unsigned int	getComparisonCounter(void) const;
		void			printSortedVec(void);


		struct Compare
		{
			bool operator()(int a, int b) {
				_comparisonCounter++;
				return a < b;
			}
    	};
};

#endif
