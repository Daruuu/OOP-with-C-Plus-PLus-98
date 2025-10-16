#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *elements_;
	unsigned int size_;

public:
	Array(): elements_(NULL), size_(0){};

	Array(unsigned int n) : elements_(new T[n]), size_(n) {}

	Array (const Array &other) : elements_(new T[other.size_]), size_(other.size_)
	{
		for (unsigned int i = 0; i < size_; i++)
			elements_[i] = other.elements_[i];
	};

	Array& operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] elements_;
			size_ = other.size_;
			elements_ = new T[size_];
			for (unsigned int i = 0; i < size_; ++i)
				elements_[i] = other.elements_[i];
		}
		return *this;
	};

	T& operator[](unsigned int index)
	{
		if (index >= size_)
			throw std::out_of_range("Index out of bounds");
		return elements_[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index >= size_)
			throw std::out_of_range("Index out of bounds");
		return elements_[index];
	}

	~Array()
	{
		delete[] elements_;
	};

	unsigned int size() const
	{
		return size_;
	}
};

#endif