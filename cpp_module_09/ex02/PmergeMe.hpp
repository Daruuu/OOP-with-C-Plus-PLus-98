#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Utils.hpp"
#include <list>
#include <string>
#include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	// Getters - used by tests to inspect sorted results
	const std::vector<int>& getSortedVector();
	const std::list<int>& getSortedList();

	bool parseArguments(int argc, char** argv);
	void run();

private:
	std::vector<int> vectorInteger_;
	std::list<int> listInteger_;
	double timeVector_;
	double timeList_;
	unsigned int lastNumberOdd_;
	unsigned int sizeSequence_;

	void sortVector();
	void sortList();

	std::vector<int> getInsertionIndices(std::vector<int> jacobSequence,
										int sizePendientList);
	std::vector<std::pair<int, int> > createOrderedPairs(
		const std::vector<int>& sequence);
	void fordJohnsonVector(std::vector<int>& sequence);
	void fordJohnsonList(std::list<int>& sequence);

	std::vector<int> createJacobsthalSequence(int sizePendientList);
};

#endif // PMERGEME_HPP
