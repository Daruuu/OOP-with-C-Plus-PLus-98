#ifndef STARTING_WITH_CPP_BITCOINEXCHANGE_HPP
#define STARTING_WITH_CPP_BITCOINEXCHANGE_HPP
#include <fstream>
#include <map>
#include <string>

namespace btc
{
	const std::string extensionTxt = ".txt";
	const std::string extensionCsv = ".csv";
	const std::string dataBaseFile = "data.csv";

	inline bool validateFileExtension(const std::string& path)
	{
		return (path.size() < 5 || path.substr(path.size() - 4) !=
			btc::extensionCsv
			|| path.substr(path.size() - 4) != btc::extensionTxt);
	}

	inline bool validateFilePermissions(const std::string& fileName)
	{
		std::ifstream ifs(fileName.c_str());
		if (!ifs.is_open())
			return false;
		ifs.close();
		return true;
	}
}

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void getBitcoinPrice();
	void getBitcoinDate();
	void printBitcoinPrice();
	void processInputFile(const std::string& filename);

private:
	std::map<std::string, float> database_;

	void loadDatabase();
	float getExchangeRate(std::string currency);
	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& valueStr) const;
	void printResult(std::string& date, float value) const;
};

#endif //STARTING_WITH_CPP_BITCOINEXCHANGE_HPP
