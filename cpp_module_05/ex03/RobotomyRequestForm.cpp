#include "RobotomyRequestForm.hpp"
#include <cstdlib>

#include "../../cpp_module_02/ex03/Fixed.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target_("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robot request form", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target_(other.target_)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target_ = other.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
	{
		throw FormNotSignedException();
	}
	//	check bureaucrat grade
	if (executor.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::cout << YELLOW << "* Drilling noises: Drrrrrrr... *" << RESET << std::endl;

	srand(static_cast<unsigned int>(time(0)));

	if (std::rand() % 2)
		std::cout << target_ << " has been robot" << std::endl;
	else
		std::cout << target_ << " robotomization failed." << std::endl;
}
