#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <iostream>

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

	void incrementGrade();
	void decrementGrade();
	// 	grade 1 is the highest and 150 the lowest,

	class GradeTooLowException : public std::exception
	{
	public:
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
