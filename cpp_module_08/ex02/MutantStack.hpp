#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <stack>
#include <list>
#include <stdexcept>

template <typename T>
class MutantStack {
private:
	std::list<T> container_; // Usamos std::list como contenedor subyacente

public:
	// Tipos de iteradores
	typedef typename std::list<T>::iterator iterator;
	typedef typename std::list<T>::const_iterator const_iterator;

	// Constructores y destructor
	MutantStack() {}
	~MutantStack() {}

	// Métodos de std::stack
	void push(const T& value) { container_.push_back(value); }
	void pop() {
		if (empty())
			throw std::underflow_error("Stack is empty");
		container_.pop_back();
	}
	T& top() {
		if (empty()) throw std::underflow_error("Stack is empty");
		return container_.back();
	}
	const T& top() const {
		if (empty()) throw std::underflow_error("Stack is empty");
		return container_.back();
	}
	bool empty() const { return container_.empty(); }
	std::size_t size() const { return container_.size(); }

	// Iteradores
	iterator begin() { return container_.begin(); }
	iterator end() { return container_.end(); }
	const_iterator begin() const { return container_.begin(); }
	const_iterator end() const { return container_.end(); }
};


/*
template <typename T>
class MutantStack : public std::stack<T, std::list<T>> {
public:
	typedef typename std::list<T>::iterator iterator;
	typedef typename std::list<T>::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	using std::stack<T, std::list<T>>::push;
	using std::stack<T, std::list<T>>::pop;
	using std::stack<T, std::list<T>>::top;
	using std::stack<T, std::list<T>>::size;
	using std::stack<T, std::list<T>>::empty;
};
*/

/*
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	// const_iterator begin() const { return this->c.begin(); }
	// const_iterator end() const { return this->c.end(); }
};

*/
/*
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>()
	{
	}

	MutantStack(const MutantStack& other) : std::stack<T>(other)
	{
	}

	MutantStack& operator=(const MutantStack& other)
	{
		if (this != other)
		{
			std::stack<T>::operator=(other);
		}
		return (this);
	}

	~MutantStack(){};
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }

	iterator end()
	{
		return this->c.end();
	}
};
*/

#endif
