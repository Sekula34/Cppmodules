#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <cstddef>
#include <list>
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
		void _printList(std::list<int>& list);
		void _printVec(std::vector<int> vec);
		void _printOnePair(pair onePair);
		void _printPairList(std::vector<pair> pairList);

		void 				_binaryInsertion(int valueToInsert, std::vector<int>& vec, std::vector<int>::iterator posOfA);
		void 				_binaryInsertion(int valueToInsert, std::list<int>::iterator posOfA);
		std::vector<int>	_fillUnsortedAs(std::vector<pair> unsortedPairs);
		std::vector<int>	_getBInsertSequence(int numberOfPairs, bool lastBAlone);
		int					_getBmemberOfPair(int aValue, std::vector<pair> unsortedPairs);
		unsigned int		_getJacobsthalNumber(int n);
		std::vector<pair>	_getUnsortedPairs(std::vector<int> unsortedVec);
		void 				_insertBs(std::vector<pair>unsortedPairs);
		void 				_insertBs(std::vector<pair>unsortedPairs, bool list);
		void 				_insertRestOfSequence(std::vector<int>& bSequence, size_t finalSizeOfVector);
		pair 				_makeOnePair(int value1, int value2);
		pair 				_makeOnePair(int valueB);
	
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		std::vector<int>	sortedVec;
		std::list<int>		sortedList;

		void			mergeInsertSort(std::vector<int> unsortedVec);
		void			mergeInsertSort(std::vector<int> unsortedVec, bool list);
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
