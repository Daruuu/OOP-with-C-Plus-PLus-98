#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define CYAN	"\033[36m"


class Replace
{
private:
	std::string	inputFilename_;
	std::string	target_;
	std::string	replacement_;

	void	replaceOcurrences(std::string& str , const std::string& sOne, const std::string& sTwo);

public:
	Replace();

	Replace(const std::string& file, const std::string& target, const std::string& replacement);
	~Replace();

	void	replaceInFile();

};

#endif //REPLACE_HPP
