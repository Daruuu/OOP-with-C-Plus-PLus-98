#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <ostream>
#include <sys/time.h>

PmergeMe::PmergeMe() : lastNumberOdd_(-1), sizeSequence_(-1)
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::processSequence(int argc, char** argv)
{
	for (int i = 0; i < argc; ++i)
	{
		char* endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || argv[i] == endptr)
		{
			std::cerr << utils::ErrorInvalidChar << argv[i] << "'\n";
			return false;
		}
		if (value <= 0)
		{
			std::cerr << utils::ErrorNegativeNumber << argv[i] << ")\n";
			return false;
		}
		if (value > INT_MAX)
		{
			std::cerr << utils::ErrorOverflowNumber << argv[i] << "'\n";
			return false;
		}
		vectorInteger_.push_back(static_cast<int>(value));
		listInteger_.push_back(static_cast<int>(value));
	}
	sizeSequence_ = vectorInteger_.size();
	std::cout << "size vector: " << sizeSequence_ << std::endl;
	utils::printContainer(vectorInteger_);

	sortVector();

	return true;
}

/**
 * @brief
 * get the vector fiil with sequence of numbers.
 * check if size of vector is even or odd
 * if odd save the last number in variable
 * get a pair of number in sequence.
 *
 */
void PmergeMe::sortVector()
{
	if (vectorInteger_.size() % 2 != 0)
	{
		lastNumberOdd_ = vectorInteger_.back();
		vectorInteger_.pop_back();
	}

	struct timeval start, end;
	gettimeofday(&start, NULL);
	//	implement algorithm here
	fordJohnsonVector(vectorInteger_);

	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	timeVector_ = (seconds * 1000000.0) + microseconds;
}

void PmergeMe::sortList()
{
}

std::vector<int> PmergeMe::getInsertionIndices(std::vector<int> jacobSequence, int sizePendientList)
{
	std::vector<int> insertionOrder;
	if (sizePendientList <= 0)
		return insertionOrder;
	int lastJacobNumber = 1;
	for (size_t i = 3; i < jacobSequence.size(); ++i)
	{
		int j = jacobSequence[i];

		//	calculamos el tope superior del grupo
		int limit = std::min(j, sizePendientList);
		//	retrocedemos desde el limite hasta el ultimo jacobsthal procesado
		for (int k = limit; k > lastJacobNumber; --k)
		{
			insertionOrder.push_back(k);
		}
		//	update last processed number
		lastJacobNumber = j;
		if (lastJacobNumber >= sizePendientList)
			break;
	}

	return insertionOrder;
}

/**
 * @brief
 * @param sequence
 * Estructurar la recursión en fordJohnsonVector:
 * Crear parejas,
 * separar en mayores ANumbers y menores en BNumbers,
 * ordenar recursivamente los mayores,
 * y usar tu secuencia de inserción para reintegrar los menores mediante búsqueda binaria.
 */
void PmergeMe::fordJohnsonVector(std::vector<int>& sequence)
{
	std::vector<int> ANumbers;
	std::vector<int> BNumbers;

	if (sequence.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < sequence.size(); i+=2)
	{
		int	num1 = sequence.at(i);
		int	num2 = sequence.at(i + 1);

		if (num1 > num2)
		{
			pairs.push_back(std::make_pair(num1, num2));
		}
		else
		{
			pairs.push_back(std::make_pair(num2, num1));
		}
	}
	utils::printVectorPairs(pairs);

	typename std::vector<std::pair<int, int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		ANumbers.push_back(it->first);	//num mayor
		BNumbers.push_back(it->second);	//num menor
	}

	//	ordena numeros mayores
	fordJohnsonVector(ANumbers);
	//	Insertar el primer elemento menor de BNumbers sin comparación
	ANumbers.insert(ANumbers.begin(), BNumbers[0]);

	//	insersion de jacobsthal y busqueda binaria
	std::vector<int> jacobSeq = createJacobsthalSequence(BNumbers.size());
	std::vector<int> insertionOrder = getInsertionIndices(jacobSeq, BNumbers.size());


}


/**
 * @brief
 * Fórmula de Jacobsthal: $J_n = J_{n-1} + 2J_{n-2}$
 * (donde $J_0 = 0$ y $J_1 = 1$).
 */
std::vector<int> PmergeMe::createJacobsthalSequence(int sizePendientList)
{
	std::vector<int> jacobSequence;

	if (sizePendientList <= 0)
		return jacobSequence;

	int a = 0;
	int b = 1;
	jacobSequence.push_back(a);
	jacobSequence.push_back(b);

	while (b < sizePendientList)
	{
		int nextNumber = b + 2 * a;
		jacobSequence.push_back(nextNumber);
		a = b;
		b = nextNumber;
	}
	return jacobSequence;
}
