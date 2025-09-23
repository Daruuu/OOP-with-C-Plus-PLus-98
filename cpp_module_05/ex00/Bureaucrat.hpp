#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;	//	1 to 150

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	//	functions to member
	void incrementGrade();
	void decrementGrade();
	// 	grade 1 is the highest and 150 the lowest,
	// incrementing a grade 3 should result in a grade 2 for the bureaucrat

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP
