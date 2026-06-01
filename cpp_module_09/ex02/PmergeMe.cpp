#include "PmergeMe.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <climits>
#include <ostream>
#include <sys/time.h>

PmergeMe::PmergeMe() : timeVector_(0), timeList_(0), lastNumberOdd_(-1),
						sizeSequence_(-1)
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
		vectorInteger_ = other.vectorInteger_;
		listInteger_ = other.listInteger_;
		timeVector_ = other.timeVector_;
		timeList_ = other.timeList_;
		lastNumberOdd_ = other.lastNumberOdd_;
		sizeSequence_ = other.sizeSequence_;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

const std::vector<int>& PmergeMe::getSortedVector()
{
	return vectorInteger_;
}

const std::list<int>& PmergeMe::getSortedList()
{
	return listInteger_;
}

bool PmergeMe::parseArguments(int argc, char** argv)
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
		//	TODO: create validation when 2 numbers are equal in sequence
		vectorInteger_.push_back(static_cast<int>(value));
	}
	sizeSequence_ = vectorInteger_.size();
	return true;
}

void PmergeMe::run()
{
	listInteger_ = std::list<int>(vectorInteger_.begin(), vectorInteger_.end());

	std::cout << "Before: ";
	utils::printContainer(vectorInteger_, "");

	sortVector();
	// sortList();

	std::cout << "After:  ";
	utils::printContainer(vectorInteger_, "");

	std::cout << "Time to process a range of " << sizeSequence_
		<< " elements with std::vector : " << timeVector_ << " us\n";
	std::cout << "Time to process a range of " << sizeSequence_
		<< " elements with std::list   : " << timeList_ << " us" << std::endl;
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
	struct timeval start, end;
	gettimeofday(&start, NULL);

	fordJohnsonList(listInteger_);

	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	timeList_ = (seconds * 1000000.0) + microseconds;
}

std::vector<int> PmergeMe::getInsertionIndices(std::vector<int> jacobSequence,
												int sizePendientList)
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

std::vector<std::pair<int, int> > PmergeMe::createOrderedPairs(const std::vector<int>& sequence)
{
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		int num1 = sequence.at(i);
		int num2 = sequence.at(i + 1);

		if (num1 > num2)
		{
			pairs.push_back(std::make_pair(num1, num2));
		}
		else
		{
			pairs.push_back(std::make_pair(num2, num1));
		}
	}
	return pairs;
}

/**
 * @brief
 * ANumbers esta ordenado
 * We need to update BNumbers following pairs vector
 * Before:
 *		A : [ 9,  12,  15 ]
 *		B no-order:    [ 3,   7,   2 ]
 *		pairs:      (12,3)(9,7)(15,2)
 *
 * After:
 *		A:     [ 9,  12,  15 ]
 *		B:     [ 7,   3,   2 ]
 *		pairs: [(9,7), (12,3), (15,2)]
 */
void PmergeMe::reorderBNumbersWithPairsInfo(const std::vector<int>& ANumbers, std::vector<int>& BNumbers, const std::vector<std::pair< int, int> >& pairsOrdered) const
{
	std::vector<int> reorderedB;

	for (size_t i = 0; i < ANumbers.size(); ++i)
	{
		int currentA = ANumbers[i];
		for (size_t j = 0; j < pairsOrdered.size(); ++j)
		{
			if (currentA == pairsOrdered[j].first)
			{
				reorderedB.push_back(pairsOrdered[j].second);
				break;
			}
		}
	}
	BNumbers = reorderedB;
}

/**
 * @brief
 * @param sequence
 * Estructurar la recursión en fordJohnsonVector:
 * Crear parejas,
 * separar en mayores ANumbers y menores en BNumbers,
 * ordenar recursivamente los mayores,
 * y usar tu secuencia de inserción para reintegrar los menores mediante búsqueda binaria.
 * Crear pairs y rellenar ANumbers / BNumbers
 * ordena solo la cadena de a (mayores).
 * reordenar pairs y BNumbers para que sigan alineados con ANumbers ordenado.
 * Insertar BNumbers[0] al inicio de ANumbers
 * Bucle Jacobsthal usando BNumbers[idx-1] y pairs[idx-1].first.
 */
void PmergeMe::fordJohnsonVector(std::vector<int>& sequence)
{
	std::vector<int> ANumbers;
	std::vector<int> BNumbers;

	if (sequence.size() <= 1)
		return;

	bool esImpar = (sequence.size() % 2 != 0);
	if (esImpar)
	{
		lastNumberOdd_ = sequence.back();
		sequence.pop_back();
	}

	std::vector<std::pair<int, int> > pairs = createOrderedPairs(sequence);

	if (utils::DEBUG == 1)
	{
		utils::printSequencePairs(pairs);
	}

	// Paso 3: Separar las parejas en Mayores (ANumbers) y Menores (BNumbers)
	std::vector<std::pair<int, int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		ANumbers.push_back(it->first); //num mayor
		BNumbers.push_back(it->second); //num menor
	}

	//	ordenamos numeros mayores
	fordJohnsonVector(ANumbers);
	//	TODO: reorder Anumbers con BNumbers, respecto a las posiciones de loas pares.
	//

	reorderBNumbersWithPairsInfo(ANumbers, BNumbers, pairs);

	//	Insertar el primer elemento menor de BNumbers sin comparación
	ANumbers.insert(ANumbers.begin(), BNumbers[0]);


	// Paso 6: Generar el orden de inserción de Jacobsthal para el resto de elementos
	std::vector<int> jacobSeq = createJacobsthalSequence(BNumbers.size());
	if (utils::DEBUG == 1)
	{
		utils::printContainer(jacobSeq, "ORDER of JACOB SEQUENCE to insert.");
	}

	std::vector<int> insertionOrder = getInsertionIndices(
		jacobSeq, BNumbers.size());

	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int idx = insertionOrder[i];
		int valueToInsert = BNumbers[idx - 1];
		int targetNumLarger = pairs[idx - 1].first;

		// Buscamos la posición actual de su pareja mayor en la cadena principal ordenada
		std::vector<int>::iterator limit = std::find(
			ANumbers.begin(), ANumbers.end(), targetNumLarger);

		// Hacemos una búsqueda binaria acotada hasta 'limit' para minimizar comparaciones

		std::vector<int>::iterator insertPos = std::upper_bound(
			ANumbers.begin(), limit, valueToInsert);

		// Insertamos el elemento en la cadena principal ordenada
		ANumbers.insert(insertPos, valueToInsert);
	}
	if (esImpar)
	{
		std::vector<int>::iterator insertPosition = std::upper_bound(ANumbers.begin(), ANumbers.end(), static_cast<int>(lastNumberOdd_));

		ANumbers.insert(insertPosition, static_cast<int>(lastNumberOdd_));
	}
	sequence = ANumbers;
}

/**
 * @brief Ford-Johnson algorithm implemented for std::list.
 * Mirrors fordJohnsonVector but uses list iterators instead of
 * index-based access, since std::list has no random access.
 */
void PmergeMe::fordJohnsonList(std::list<int>& sequence)
{
	if (sequence.size() <= 1)
		return;

	bool hasOdd = (sequence.size() % 2 != 0);
	int oddElement = -1;
	if (hasOdd)
	{
		oddElement = sequence.back();
		sequence.pop_back();
	}

	// Build pairs by walking the list two elements at a time
	std::vector<std::pair<int, int> > pairs;
	for (std::list<int>::iterator it = sequence.begin(); it != sequence.end();)
	{
		int num1 = *it;
		++it;
		int num2 = *it;
		++it;
		if (num1 > num2)
			pairs.push_back(std::make_pair(num1, num2));
		else
			pairs.push_back(std::make_pair(num2, num1));
	}

	std::list<int> ANumbers;
	std::list<int> BNumbers;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		ANumbers.push_back(pairs[i].first);
		BNumbers.push_back(pairs[i].second);
	}

	// Recursively sort the larger elements
	fordJohnsonList(ANumbers);

	// b0 <= a0 (minimum of ANumbers) → insert at the front without comparison
	ANumbers.insert(ANumbers.begin(), BNumbers.front());

	// Generate Jacobsthal insertion order for the remaining B elements
	std::vector<int> jacobSeq = createJacobsthalSequence(
		static_cast<int>(BNumbers.size()));
	std::vector<int> insertionOrder = getInsertionIndices(
		jacobSeq, static_cast<int>(BNumbers.size()));

	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int idx = insertionOrder[i];

		// Access BNumbers[idx - 1] via advance (no random access on list)
		std::list<int>::iterator bIt = BNumbers.begin();
		std::advance(bIt, idx - 1);
		int valueToInsert = *bIt;

		int targetNumLarger = pairs[idx - 1].first;

		// Find the position of the paired larger element to use as upper bound
		std::list<int>::iterator limit =
			std::find(ANumbers.begin(), ANumbers.end(), targetNumLarger);

		// Binary search up to 'limit' (upper_bound works with bidirectional iterators)
		std::list<int>::iterator insertPos =
			std::upper_bound(ANumbers.begin(), limit, valueToInsert);

		ANumbers.insert(insertPos, valueToInsert);
	}

	if (hasOdd)
	{
		std::list<int>::iterator insertPosition =
			std::upper_bound(ANumbers.begin(), ANumbers.end(), oddElement);
		ANumbers.insert(insertPosition, oddElement);
	}

	sequence = ANumbers;
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
