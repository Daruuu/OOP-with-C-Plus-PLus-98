#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	indexContact_ = 0;
	maxContact_ = 0;
};

PhoneBook::~PhoneBook() {};

PhoneBook::PhoneBook(size_t maxContact_)
{
	this->maxContact_ = maxContact_;
}

//	getters

// Contact	PhoneBook::getContact();

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
	size_t	i = 0;
	for (int i = 0; i < ; ++i)
	{

	}
}

