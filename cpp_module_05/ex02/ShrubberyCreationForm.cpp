#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137),
												ktarget_("default_shruberry")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery creation", 145, 137), ktarget_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& other) : AForm(other), ktarget_(other.ktarget_)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::string filename = ktarget_ + "_shrubbery";

	std::ofstream outFile(filename.c_str());

	if (outFile.is_open())
	{
		outFile << GREEN << "       &&& &&  & &&\n";
		outFile << "   && &\\/&\\|& ()|/ @, &&\n";
		outFile << "   &\\/(/&/&||/& /_/)_&/_&\n";
		outFile << " &() &\\/&|()|/&\\/ '%\" & ()\n";
		outFile << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		outFile << "&&   && & &| &| /& & % ()& /&&\n";
		outFile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
		outFile << "     &&     \\|||\n";
		outFile << "             |||\n";
		outFile << "             |||\n";
		outFile << "             |||\n";
		outFile << "       , -=-~  .-^- _\n";
		outFile.close();

		std::cout << "Shrubbery has been planted in " << ktarget_ << "_shrubbery" << std::endl;
	}
	else
	{
		std::cerr << "Error: cant create file!" << std::endl;
	}
}
