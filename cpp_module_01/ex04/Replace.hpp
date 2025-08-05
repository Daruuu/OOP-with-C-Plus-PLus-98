#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Replace
{
private:
	std::string	inputFilename_;
	std::string	target_;
	std::string	replacement_;

	void	replaceAll(std::string& str , const std::string& sOne, const std::string& sTwo);

public:
	Replace();

	Replace(const std::string& file, const std::string& target, const std::string& replacement);
	~Replace();

	void	replaceInFile();

};

#endif //REPLACE_HPP
