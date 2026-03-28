#include <unistd.h>
#include <iostream>
#include <sstream>

/**
 * returns 0 on success, -1 on msg_errors
 * F_OK: check for existence
 * R_OK: check for read permission
 */
bool fileExists(const std::string& path)
{
	return (access(path.c_str(), F_OK | R_OK) == 0);
}

//	VALIDATIONS
bool validateFileExtension(const std::string& path) const
{
	if (path.size() < 5 || path.substr(config_file_path_.size() - 5) !=
		config::paths::extension_file)
	{
		return false;
	}
	// protect edge case: the character is like ".conf" cant be '/' (evita
	// ficheros como "/.conf")
	char charBeforeDot = config_file_path_[config_file_path_.size() - 5];
	if (charBeforeDot == '/')
	{
		return false;
	}
	return true;
}

bool ConfigParser::validateFilePermissions() const
{
	std::ifstream ifs(config_file_path_.c_str());
	if (!ifs.is_open()) return false;
	ifs.close();
	return true;
}

int main(int ac, char** av)
{
	if (ac == 2 && fileExists(av[1]))
	{
		std::cout << "Valid  arg 01\n";
	}
	else
	{
		std::cout << "Error invalid argv: " << av[0] << " <.csv>" << std::endl;
	}


	return (0);
}
