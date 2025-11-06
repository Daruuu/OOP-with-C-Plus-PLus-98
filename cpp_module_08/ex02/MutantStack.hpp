#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	typedef std::deque<T> tDeque;		//	estamos definiendo un alias de un contenedor de tipo DEQUE
	typedef typename tDeque::iterator iterator;	//estamos definiendo un alias de tipo iterator

	// 'iterator' será un alias (sinónimo) del tipo 'std::deque<T>::iterator'.
	// Sirve para acceder fácilmente al tipo de iterador del contenedor subyacente ('tDeque').
	// Gracias a esto podemos escribir simplemente 'iterator' en lugar de 'std::deque<T>::iterator'.

	MutantStack(){}

	MutantStack(const MutantStack& other) : std::stack<T>(other){}

	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}

	~MutantStack() {}

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

#endif
