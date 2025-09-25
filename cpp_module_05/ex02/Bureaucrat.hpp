#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string kname_;
	int grade_;	//	1 to 150

public:
	Bureaucrat();
	Bureaucrat(const std::string& kname, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	// 	grade 1 is the highest and 150 the lowest,
	void incrementGrade();
	void decrementGrade();

	// Form methods
	void signForm(AForm& form) const;
	void executeForm(const AForm& form) const;

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP
