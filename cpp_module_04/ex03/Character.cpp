#include "Character.hpp"

Character::Character() : ICharacter()
{
	this->name_ = "Character default";
	// this->inventory_[0] = ;

}

Character::Character(const Character& other)
{
}

Character& Character::operator=(const Character& other)
{
}

Character::~Character()
{
}
