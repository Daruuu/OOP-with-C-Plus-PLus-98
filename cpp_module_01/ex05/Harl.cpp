#include "Harl.hpp"

// ANSI Colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

#include <iostream>

void Harl::debug_()
{
	std::cout << GREEN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "	I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger."
		" I really do!"
	<< std::endl;
}

void Harl::info_()
{
	std::cout << CYAN << "[ INFO ]" << RESET << std::endl;
	std::cout << "	I cannot believe adding extra bacon costs more money."
				 "You didn't put enough bacon in my burger!"
				 "If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning_()
{
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << "	I think I deserve to have some extra bacon for free. "
	"I’ve been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void Harl::error_()
{
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "	This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

Harl::Harl() { }

Harl::~Harl() { }

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	//	this is a pointer array to member functions
	void	(Harl::*actions[4]) ();

	actions[0] = &Harl::debug_;
	actions[1] = &Harl::info_;
	actions[2] = &Harl::warning_;
	actions[3] = &Harl::error_;

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*actions[i]) ();
			break;
		}
	}
	// std::cout << "[ End of complain function.]" << std::endl;
}
