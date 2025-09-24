#include "ShrubberyCreationForm.hpp"

#include "../ex01/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137),
												ktarget_("default_shruberry")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery creation", 145, 137), ktarget_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& other) : AForm(other), ktarget_(other.ktarget_)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		ktarget_ = other.ktarget_;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	if (!getIsSigned())
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
	}
}
