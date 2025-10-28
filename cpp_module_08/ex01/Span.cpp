#include "Span.hpp"

#include <algorithm>
#include <limits.h>
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

unsigned int Span::shortestSpan() const
{
	if (numbers_.size() <= 1)
		throw std::length_error("not enough numbers.");

	std::vector<int> sorted = numbers_;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];

	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
	}
	return (minSpan);
}

/*
unsigned int Span::longestSpan() const
{
	if (numbers_.size() <= 1)
		throw std::length_error("Not enough errors.");

	//	complexity is O(n) , iterate through container 1 time.
	std::vector<int>::const_iterator maxValue = std::max_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator minValue = std::min_element(numbers_.begin(), numbers_.end());

	return static_cast<unsigned int>(*maxValue - *minValue);
}
*/
//	posible error with negative
unsigned int Span::longestSpan() const
{
	if (numbers_.size() <= 1)
		throw std::length_error("Not enough errors.");

	//	complexity is O(n) , iterate through container 1 time.
	// int *maxValue = std::max_element(numbers_.begin(), numbers_.end());
	// int *minValue = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator maxIt = std::max_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator minIt = std::min_element(numbers_.begin(), numbers_.end());

	int diff = *maxIt - *minIt;
	if (diff < 0)
		throw std::overflow_error("negative difference");
	return static_cast<unsigned int>(diff);
}
