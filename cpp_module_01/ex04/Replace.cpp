#include "Replace.hpp"

Replace::Replace() { }

Replace::Replace(const std::string& file, const std::string& target,
	const std::string& replacement)
	: inputFilename_(file), target_(target), replacement_(replacement)
{ }

Replace::~Replace() { }

void	Replace::replaceOcurrences(std::string& str,
	const std::string& sOne, const std::string& sTwo)
{
	if (sOne.empty())
		return;
	size_t	startPos = 0;

	while ((startPos = str.find(sOne, startPos)) != std::string::npos)
	{
		str.erase(startPos, sOne.length());
		str.insert(startPos, sTwo);
		startPos += sTwo.length();
	}
}

void	Replace::replaceInFile()
{
	if (inputFilename_.empty())
	{
		std::cerr << "Error: [FILE] cannot be empty." << std::endl;
		return;
	}

	std::ifstream inputFile(this->inputFilename_.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Cannot open input file: " << this->inputFilename_ << std::endl;
		return;
	}

	std::stringstream buffer;

	buffer << inputFile.rdbuf();
	std::string content = buffer.str();
	inputFile.close();

	replaceOcurrences(content, target_, replacement_);

	std::string outputFileName = this->inputFilename_ + ".replace";

	std::ofstream outputFile(outputFileName.c_str());
	if (!outputFile)
	{
		std::cerr << "Error: Cannot write to output file: " << outputFileName << std::endl;
		return;
	}

	outputFile << content;
	outputFile.close();
}
