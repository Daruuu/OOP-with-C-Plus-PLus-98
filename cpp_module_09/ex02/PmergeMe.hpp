#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

	bool processSequence(int argc, char** argv);

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

#endif //PMERGEME_HPP
