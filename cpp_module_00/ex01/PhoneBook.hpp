#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>

class	PhoneBook
{

private:
	Contact contacts_[8];
	size_t	currentIndex_;
	size_t	totalContacts_;

public:
	PhoneBook();
	~PhoneBook();

	//	getters
	size_t	getCurrentIndex();

	//	methods
	void	addNewContact();
	void	searchContact(size_t index);
	// Contact	getContact(size_t index);
	void	printContacts();
};

#endif