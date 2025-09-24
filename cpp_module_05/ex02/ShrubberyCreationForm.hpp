#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>

#include "AForm.hpp"

//	Required grades: sign 145, exec 137

class ShrubberyCreationForm : public AForm
{
private:
	const std::string ktarget_;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	//	OVERRIDE
	void execute(const Bureaucrat& executor) const;

};

#endif
