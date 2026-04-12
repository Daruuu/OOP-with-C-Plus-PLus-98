#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Bureaucrat
{
private:
	const std::string kname_;
	int grade_;	//	1 to 150

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
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
