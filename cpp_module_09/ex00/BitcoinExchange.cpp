#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	database_ = other.database_;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		database_ = other.database_;
	}
	return *this;
}

void BitcoinExchange::getBitcoinPrice()
{
}

void BitcoinExchange::getBitcoinDate()
{
}

void BitcoinExchange::printBitcoinPrice()
{
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	// std::ifstream inputFile = std::ifstream(filename.c_str());

}

void BitcoinExchange::loadDatabase()
{
	std::ifstream file((btc::dataBaseFile.data()));

	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open database file: " << btc::dataBaseFile << std::endl;
	}
	std::string line;

	//	get first line: date | value
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t commaPosition = line.find(',');
		if (commaPosition != std::string::npos)
		{
			//	extract line: date, value
			std::string date = line.substr(0, commaPosition);
			std::string valueStr = line.substr(commaPosition + 1);
			// value to float
			std::stringstream ss(valueStr);
			float valueFloat;
			ss >> valueFloat;
			database_[date] = valueFloat;
		}
	}
	file.close();
}

float BitcoinExchange::getExchangeRate(std::string currency)
{
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) const
{
}

void BitcoinExchange::printResult(std::string& date, float value) const
{
}
