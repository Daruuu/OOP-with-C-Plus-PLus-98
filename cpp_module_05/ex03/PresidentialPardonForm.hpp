#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

// Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm
{
private:
	std::string target_;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(PresidentialPardonForm& other);
	~PresidentialPardonForm();

	//	override
	void execute(const Bureaucrat& executor) const;
};

#endif
