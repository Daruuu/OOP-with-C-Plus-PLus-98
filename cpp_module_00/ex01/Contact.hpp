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
	std::string getLast_name();
	std::string getNickname();
	std::string	getPhone_number();
	std::string	getDarkest_secret();

	//	prototypes setters
	void	setFirstName(std::string newName);
	void	setLastName(std::string newLastName);
	void	setNickName(std::string newNickName);
	void	setPhoneNumber(std::string newPhoneNumber);
	void	setDarkestSecret(std::string newDarkestSecret);

};


#endif
