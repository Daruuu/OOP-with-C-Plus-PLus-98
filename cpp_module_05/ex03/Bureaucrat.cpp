#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : kname_("empty"), grade_(24)
{
	std::cout << BLUE << "Bureaucrat default constructor called." << RESET
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : kname_(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : kname_(other.kname_),
												grade_(other.grade_)
{
	std::cout << CYAN << "Bureaucrat copy constructor called." << RESET
		<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade_ = other.grade_;
	}
	std::cout << CYAN << "Bureaucrat copy assignment operator called" << RESET
		<< std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "[Bureaucrat] destructor called for " << RESET << kname_
		<< std::endl;
}

//	=============== GETTERS ===============
const std::string& Bureaucrat::getName() const
{
	return (this->kname_);
}

int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

//	=============== METHODS ===============

void Bureaucrat::incrementGrade()
{
	if (grade_ <= 1)
		throw GradeTooHighException();
	grade_--;
}

void Bureaucrat::decrementGrade()
{
	if (grade_ >= 150)
		throw GradeTooLowException();
	grade_++;
}

//	=============== FORMS METHODS ===============

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << kname_ << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << kname_ << " could not sign " << form.getName() <<
			" because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << kname_ << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << kname_ << " could not execute" << form.getName() <<
			" because: " << e.what() << std::endl;
	}
}

//	=============== EXCEPTIONS ===============

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. :(");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. :|");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << CYAN << "Bureaucrat: " << obj.getName()
		<< "\ngrade: " << obj.getGrade()
		<< RESET << std::endl;
	return out;
}
