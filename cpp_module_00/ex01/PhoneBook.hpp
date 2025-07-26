#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts_[8];
	size_t indexContact_;

public:
	PhoneBook();
	~PhoneBook();
	size_t maxContact_;

	//	getters
	size_t	PhoneBook::getIndexContact();
	size_t	PhoneBook::getMaxContact();

	// setters
	// void	PhoneBook::setIndexContact(size_t index_contact);
	// void	PhoneBook::setMaxContact(size_t maxContact);

	//	methods
	void	addNewContact(Contact contact);
	void	searchContact(size_t index);
};

#endif
