#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	currentIndex_ = 0;
	totalContacts_ = 8;
};

PhoneBook::~PhoneBook() {};

//	getters

size_t	PhoneBook::getTotalContacts()
{
	return this->totalContacts_;
}


void	PhoneBook::addNewContact()
{
	Contact		newUser;
	std::string	inputLine;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	newContact.setNickName(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	newContact.setDarkestSecret(input);

	this->contacts_[this->currentIndex_ % 8] = newContact;
	this->currentIndex_++;

	std::cout << "✅ Contact added!" << std::endl;
	
}

int	protectGetLine(std::string *data);

void	PhoneBook::searchContact(size_t index)
{

}

void	printContacts()
{
	int	i;

}

int	validateAtributes(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkSecret)
{
	return (firstName.length() != 0 || lastName.length() != 0 || nickName.length() != 0 || \
			phoneNumber.length() != 0 || darkSecret.length() != 0);
}

