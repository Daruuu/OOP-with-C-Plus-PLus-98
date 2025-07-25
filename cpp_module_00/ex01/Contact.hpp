#ifndef CONTACT_H
#define CONTACT_H
# include <iostream>
# include <string>

class Contact
{
private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string phoneNumber_;
	std::string darkestSecret_;

public:
	Contact();
	~Contact();

	//	prototypes getters
private:
	std::string Contact::getFirstName();
	std::string Contact::getLast_name();
	std::string Contact::getNickname();
	std::string Contact::getPhone_number();
	std::string Contact::getDarkest_secret();

public:
	//	prototypes setters
	void Contact::setFirstName(std::string newName);
	void Contact::setLastName(std::string newLastName);
	void Contact::setNickName(std::string newNickName);
	void Contact::setPhoneNumber(std::string newPhoneNumber);
	void Contact::setDarkestSecret(std::string newDarkestSecret);
};


#endif //CONTACT_H
