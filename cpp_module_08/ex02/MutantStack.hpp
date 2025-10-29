#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <list>
#include <stack>

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <list>

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

#endif

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
