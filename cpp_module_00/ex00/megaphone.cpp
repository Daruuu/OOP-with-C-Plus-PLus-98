#include <iostream>
#include <cctype>

int	main(int argc, char* argv[])
{
	std::string	empty_args_message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		std::cout << empty_args_message;
	else
	{
		for (int i = 1; i < argc; ++i) {
			std::string current_word = argv[i];

			for (size_t j = 0; j < current_word.length(); ++j)
			{
				std::cout << (char) std::toupper(current_word[j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
