#ifndef FORM_HPP
#define FORM_HPP
#include <string>

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string kname_;
	bool is_signed_; // no add to constructor
	const int kgradeToSigned_;
	const int kgradeToExecute_;

public:
	Form();
	Form(const std::string& name, const int kgradeToSign, int kgradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	//	GETTERS
	const std::string& getName() const;
	bool getIsSigned() const;
	const int getGradeToSigned() const;
	const int getGradeToExecute() const;

	//	METHODS
	void incrementGradeForm();
	void decrementGradeForm();
	void beSigned(Bureaucrat& bureaucrat);

	//	EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif
