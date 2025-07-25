#ifndef PHONEBOOK_H
#define PHONEBOOK_H
# include <iostream>
# include <string>

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact arrayContacts[8];
	size_t indexContact_;
	size_t maxContact_;

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(size_t maxContact_);

	//	getters

	//	setters

	//	methods
};


#endif //PHONEBOOK_H
