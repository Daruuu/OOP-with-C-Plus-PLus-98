#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target_("default_target")
{
	std::cout << BLUE << "[RobotomyRequestForm] default constructor called." << RESET
		<< std::endl;
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
	std::cout << RED << "{RobotomyRequestForm} default destructor called." << RESET
		<< std::endl;
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

	std::srand((time(NULL )));

	int	randomNum = std::rand();

	if (randomNum % 2 == 0)
		std::cout << BLUE << target_ << " has been robot" << RESET << std::endl;
	else
		std::cout << target_ << " robotomization failed." << std::endl;
}
