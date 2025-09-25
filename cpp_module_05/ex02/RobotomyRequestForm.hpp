#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Required grades: sign 72, exec 45
class RobotomyRequestForm : public AForm
{
private:
	std::string target_;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	//	override
	void execute(const Bureaucrat& executor) const;
};

#endif