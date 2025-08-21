#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		inventory_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory_[i])
			inventory_[i] = other.inventory_[i]->clone();
		else
			inventory_[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete inventory_[i];
			if (other.inventory_[i])
				inventory_[i] = other.inventory_[i]->clone();
			else
				inventory_[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inventory_[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory_[i] && inventory_[i]->getType() == type)
			return inventory_[i]->clone();
	}
	return (NULL);
}
