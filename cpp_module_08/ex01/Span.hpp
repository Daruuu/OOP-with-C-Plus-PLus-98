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
	template<typename InputIterator>
	void addRangeOfNumbers(InputIterator begin, InputIterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	unsigned int size() const;
	int	getValue(unsigned int i) const;
};

#endif
