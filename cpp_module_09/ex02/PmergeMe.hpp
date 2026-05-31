#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Utils.hpp"
#include <list>
#include <string>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  bool processSequence(int argc, char **argv);

private:
  std::vector<int> vectorInteger_;
  std::list<int> listInteger_;
  double timeVector_;
  double timeList_;
  unsigned int lastNumberOdd_;
  unsigned int sizeSequence_;

  //	implementation to vector container
  void sortVector();
  //	implementation to list container
  void sortList();

  std::vector<int> getInsertionIndices(std::vector<int> jacobSequence,
                                       int sizePendientList);
  void fordJohnsonVector(std::vector<int> &sequence);
  void fordJohnsonList(std::list<int> &sequence);

  std::vector<int> createJacobsthalSequence(int sizePendientList);
  void binarySearch(const std::vector<std::string> &vector);
  void insertionSort(const std::vector<std::string> &vector);
};

#endif // PMERGEME_HPP
