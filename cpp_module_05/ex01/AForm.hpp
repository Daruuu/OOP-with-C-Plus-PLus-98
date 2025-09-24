#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string kname_;
	bool is_signed_; // no add to constructor
	const int kgradeToSigned_;
	const int kgradeToExecute_;

public:
	AForm();
	AForm(const std::string& name, const int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	~AForm();

	//	GETTERS
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSigned() const;
	int getGradeToExecute() const;

	//	METHODS
	void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
