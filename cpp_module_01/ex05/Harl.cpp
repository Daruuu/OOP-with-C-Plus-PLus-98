#include "Harl.hpp"

#include <iostream>

void Harl::debug_()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger."
		" I really do!"
	<< std::endl;
}

void Harl::info_()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
				 "You didn't put enough bacon in my burger!"
				 "If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning_()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I’ve been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void Harl::error_()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

Harl::Harl() { }

Harl::~Harl() { }

void Harl::complain(std::string level)
{
	//	this is a pointer array to member functions
	void	(Harl::*arrayOfActions[])()
	{
		&Harl::debug_,
		&Harl::info_,
		&Harl::warning_,
		&Harl::error_
	};

	for (int i = 0; i < 4; ++i)
	{
		(this->*arrayOfActions[i]) ();
		return;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
