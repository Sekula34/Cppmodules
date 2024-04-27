#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <cstddef>
# include <vector>

class PmergeMe
{
	private :
		static unsigned int _comparisonCounter;
		std::vector<int> sortedVec;

		void				_binaryInsertion(int valueToInsert, std::vector<int>& vec);
		std::vector<int>	_getBInsertSequence(int numberOfPairs, bool lastBAlone);
		unsigned int		_getJacobsthalNumber(int n);
		void				_insertRestOfSequence(std::vector<int>& bSequence, size_t finalSizeOfVector);
	public :
	//orthodox
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

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
