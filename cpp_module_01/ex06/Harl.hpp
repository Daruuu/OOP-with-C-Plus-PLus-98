#ifndef HARL_HPP
#define HARL_HPP
#include <string>

// ANSI Colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

class Harl
{

private:
	void	debug_();
	void	info_();
	void	warning_();
	void	error_();

public:
	Harl();
	~Harl();

	void	complain(std::string level);
};

#endif //HARL_HPP
