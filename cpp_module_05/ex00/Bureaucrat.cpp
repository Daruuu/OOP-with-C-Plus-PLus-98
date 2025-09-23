#include "Bureaucrat.hpp"

#include <tgmath.h>

class Bureaucrat
{
private:
	const std::string name_;
	int	grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string&	getName() const;
	int	getGrade()const ;

	//	functions to member
	void	incrementGrade();
	void	decrementGrade();

	class GradeToHightException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

};
