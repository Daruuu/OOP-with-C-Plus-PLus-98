#include "AForm.hpp"

AForm::AForm() : kname_("default"), is_signed_(false), kgradeToSigned_(0),
				kgradeToExecute_(0)
{
	std::cout << BLUE << "Form default constructor called." << RESET
		<< std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign, int gradeToExecute) :
	kname_(name), kgradeToSigned_(gradeToSign), kgradeToExecute_(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : kname_(other.kname_),
								is_signed_(other.is_signed_),
								kgradeToSigned_(other.kgradeToSigned_),
								kgradeToExecute_(other.kgradeToExecute_)
{
	std::cout << CYAN << "Form copy constructor called." << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	//	check only no constant atributs
	if (this != &other)
	{
		this->is_signed_ = other.is_signed_;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "[Form] destructor called for " << RESET << kname_
		<< std::endl;
}

//	=============== GETTERS ===============

const std::string& AForm::getName() const
{
	return this->kname_;
}

bool AForm::getIsSigned() const
{
	return this->is_signed_;
}

int AForm::getGradeToSigned() const
{
	return this->kgradeToSigned_;
}

int AForm::getGradeToExecute() const
{
	return this->kgradeToExecute_;
}

//	=============== METHODS ===============

void AForm::beSigned(const Bureaucrat& b1)
{
	if (b1.getGrade() > kgradeToSigned_)
		throw GradeTooLowException();
	is_signed_ = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high in Form";
	// return exception::what();
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low in Form";
	// return exception::what();
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << YELLOW << "Form: " << obj.getName()
		<< "\nis Signed: " << (obj.getIsSigned() ? "signed" : "not signed")
		<< "\nGrade to sign: " << obj.getGradeToSigned()
		<< "\nGrade to execute: " << obj.getGradeToExecute()
		<< RESET << std::endl;
	return (out);
}
