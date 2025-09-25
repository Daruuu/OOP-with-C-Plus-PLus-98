#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presi form", 25, 5), target_(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target_(other.target_)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkExecutor(executor);
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
