#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	currentIndex_ = 0;
	totalContacts_ = 8;
};

PhoneBook::~PhoneBook() {};

//	getters

// size_t	getTotalContacts()
// {
// 	return totalContacts_;
// }

size_t	PhoneBook::getCurrentIndex()
{
	return this->currentIndex_;
}


void	PhoneBook::addNewContact()
{
	Contact		newContact;
	std::string	input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	newContact.setNickName(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	newContact.setDarkestSecret(input);

	this->contacts_[this->currentIndex_ % 8] = newContact;
	this->currentIndex_++;

	std::cout << "✅ Contact added!" << std::endl;
}

int	protectGetLine(std::string *data);

void	PhoneBook::searchContact(size_t index)
{
	if (index > 0 && index < 8)
	{
		int	i = 0;
		while (contacts_[i])
		{
			i++;
		}
	}

}

// Helper para truncar y formatear
static std::string truncateField(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	printContacts()
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nick name" << std::endl;

	size_t count = this->currentIndex_ < 8 ? this->currentIndex_ : 8;

	for (size_t i = 0; i < count; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncateField(contacts_[i].getFirstName()) << "|"
				  << std::setw(10) << truncateField(contacts_[i].getLast_name()) << "|"
				  << std::setw(10) << truncateField(contacts_[i].getNickname()) << std::endl;
	}

}

void	PhoneBook::searchContact(size_t index)
{
	size_t count = this->currentIndex_ < 8 ? this->currentIndex_ : 8;

	if (index >= count)
	{
		std::cout << "❌ Invalid index." << std::endl;
		return;
	}

	Contact c = contacts_[index];
	std::cout << "First name:     " << c.getFirstName() << std::endl;
	std::cout << "Last name:      " << c.getLast_name() << std::endl;
	std::cout << "Nickname:       " << c.getNickname() << std::endl;
	std::cout << "Phone number:   " << c.getPhone_number() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkest_secret() << std::endl;
}

int	validateAtributes(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkSecret)
{
	return (firstName.length() != 0 || lastName.length() != 0 || nickName.length() != 0 || \
			phoneNumber.length() != 0 || darkSecret.length() != 0);
}

