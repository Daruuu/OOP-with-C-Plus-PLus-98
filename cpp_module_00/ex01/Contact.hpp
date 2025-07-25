#ifndef CONTACT_HPP
#define CONTACT_HPP
# include <string>

class Contact
{
private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	long		phoneNumber_;
	std::string darkestSecret_;

public:
	Contact();
	~Contact();

	//	prototypes getters
	std::string Contact::getFirstName();
	std::string Contact::getLast_name();
	std::string Contact::getNickname();
	long		Contact::getPhone_number();
	std::string Contact::getDarkest_secret();

	//	prototypes setters
	void	setFirstName(std::string newName);
	void	setLastName(std::string newLastName);
	void	setNickName(std::string newNickName);
	void	setPhoneNumber(long newPhoneNumber);
	void	setDarkestSecret(std::string newDarkestSecret);

};


#endif
