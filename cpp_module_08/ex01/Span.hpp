#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
private:
	unsigned int maxSize_;
	std::vector<int> numbers_;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span& operator=(const Span &other);
	~Span();

	void addNumber(unsigned int N);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif