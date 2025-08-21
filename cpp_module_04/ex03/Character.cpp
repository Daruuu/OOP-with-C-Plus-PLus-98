#include "Character.hpp"

//	methos privates

void Character::clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inventory_[i];
		inventory_[i] = NULL;
	}
}

void Character::copyInventory(const Character& other)
{
	name_ = other.name_;
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory_[i])
		{
			inventory_[i] = other.inventory_[i]->clone();	// use clone from AMateria
		}
		else
			inventory_[i] = NULL;
	}
}

Character::Character() : ICharacter(), inventory_()
{
	this->name_ = "Character_default";
}

Character::Character(std::string const& name) : name_(name)
{
	for (int i = 0; i < 4; ++i)
	{
		inventory_[i] = NULL;
	}
}

Character::Character(const Character& other)
{
	copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		clearInventory();
		name_ = other.name_;
		copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
}

//	=========== METHODS FROM INTERFACE: ICHARACTER ===========

const std::string& Character::getName() const
{
	return this->name_;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory_[idx])
		inventory_[idx]->use(target);
}
