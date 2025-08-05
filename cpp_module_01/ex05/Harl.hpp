#ifndef HARL_HPP
#define HARL_HPP
#include <string>

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
