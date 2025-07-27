#ifndef CONTACT_HPP
#define CONTACT_HPP
# include <string>

class Contact
{
private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string	phoneNumber_;
	std::string darkestSecret_;

public:
	Contact();
	~Contact();

	//	prototypes getters
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();

	//	prototypes setters
	void	setFirstName(std::string newName);
	void	setLastName(std::string newLastName);
	void	setNickName(std::string newNickName);
	void	setPhoneNumber(std::string newPhoneNumber);
	void	setDarkestSecret(std::string newDarkestSecret);

};

#endif
