#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target_("default_target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& other)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
}
