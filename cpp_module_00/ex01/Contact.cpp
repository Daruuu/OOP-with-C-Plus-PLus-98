#include "Contact.h"
#include "Contact.hpp"

Contact::Contact()
{
};

Contact::~Contact()
{
};

//	getters
std::string Contact::getFirstName()
{
	return this->firstName_;
}

std::string Contact::getLast_name()
{
	return this->lastName_;
}

std::string Contact::getNickname()
{
	return this->nickname_;
}

std::string Contact::getPhone_number()
{
	return this->phoneNumber_;
}

std::string Contact::getDarkest_secret()
{
	return this->darkestSecret_;
}

//	setters
void Contact::setFirstName(std::string newName)
{
	this->firstName_ = newName;
}

void Contact::setLastName(std::string newLastName)
{
	this->lastName_ = newLastName;
}

void Contact::setNickName(std::string newNickName)
{
	this->nickname_ = newNickName;
}

void Contact::setPhoneNumber(std::string newPhoneNumber)
{
	this->phoneNumber_ = newPhoneNumber;
}

void Contact::setDarkestSecret(std::string newDarkestSecret)
{
	this->darkestSecret_ = newDarkestSecret;
}
