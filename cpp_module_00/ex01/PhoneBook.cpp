#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	indexContact_ = 0;
	maxContact_ = 8;
};

PhoneBook::~PhoneBook() {};

//	getters

size_t	PhoneBook::getIndexContact()
{
	return this->indexContact_;
}

size_t	PhoneBook::getMaxContact()
{
	return this->maxContact_;
}

//	TODO: method add new contact
void	PhoneBook::addNewContact(Contact new_contact)
{
	//	create new contact
}

int	protect_getLine(std::string *data);

//	TODO: method search a contact
void	PhoneBook::searchContact(size_t index)
{
	for (int i = 0; i < ; ++i)
	{

	}
}

