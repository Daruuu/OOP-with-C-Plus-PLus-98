#include "Span.hpp"

#include <algorithm>
#include <stdexcept>

Span::Span()
{
}

Span::Span(unsigned int n) : maxSize_(n)
{
}

Span::Span(const Span &other) : maxSize_(other.maxSize_), numbers_(other.numbers_)
{
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->maxSize_ = other.maxSize_;
		this->numbers_ = other.numbers_;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(unsigned int N)
{
	if (numbers_.size() >= maxSize_)
		throw std::overflow_error("Span is full");
	numbers_.push_back(N);
}

template <typename InputIterator>
void Span::addRangeOfNumbers(InputIterator begin, InputIterator end)
{
	for (InputIterator it = begin; it != end; ++it)
	{
		if (numbers_.size() >= maxSize_)
			throw std::out_of_range("Span overflow: too many elements. :(");
		numbers_.push_back(*it);
	}
}

unsigned int Span::shortestSpan() const
{
	if (numbers_.size() <= 1)
		throw std::length_error("not enough numbers.");

	std::vector<int> sorted = numbers_;
	std::sort(sorted.begin(), sorted.end());

	// long minSpan = static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]);
	int minSpan = sorted[1] - sorted[0];

	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		long diff = static_cast<long>(sorted[i + 1]) - static_cast<long>(sorted[i]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return static_cast<unsigned int>(minSpan);
}

unsigned int Span::longestSpan() const
{
	if (numbers_.size() <= 1)
		throw std::length_error("Not enough length.");

	//	complexity is O(n) , iterate through container 1 time.
	// int *maxValue = std::max_element(numbers_.begin(), numbers_.end());
	// int *minValue = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator maxIt = std::max_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator minIt = std::min_element(numbers_.begin(), numbers_.end());

	long diff = static_cast<long>(*maxIt) - static_cast<long>(*minIt);

	if (diff < 0)
		throw std::overflow_error("negative difference");
	return static_cast<unsigned int>(diff);
}

unsigned int Span::size() const
{
	return numbers_.size(); 
}

int Span::getValue(unsigned int i) const
{
    if (i >= numbers_.size())
        throw std::out_of_range("Index out of range");
    return numbers_[i];
}


