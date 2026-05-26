#ifndef STARTING_WITH_CPP_PMERGEME_HPP
#define STARTING_WITH_CPP_PMERGEME_HPP
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

	void processSequence(char** argv);

private:
	std::vector<int> vectorInteger_;
	std::list<int> listInteger_;

	//	implementation to vector container
	void sortVector(const std::vector<std::string>& vector);
	//	implementation to list container
	void sortList(const std::list<std::string>& list);
	void fordJohnsonVector(std::vector<int>& arr);
	void fordJohnsonList(std::list<int>& arr);

	void getJacobsthalSequence();
	void binarySearch(const std::vector<std::string>& vector);
	void insertionSort(const std::vector<std::string>& vector);
};

#endif //STARTING_WITH_CPP_PMERGEME_HPP
