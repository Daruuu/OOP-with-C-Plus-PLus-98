#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command;

	std::cout << "Welcome to My phonebook :)" << std::endl;

	while (true)
	{
		std::cout << "\nAvailable commands: ADD | SEARCH | EXIT" << std::endl;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "\nExiting..." << std::endl;
			break;
		}

		if (command == "ADD")
		{
			phone_book.addNewContact();
		}
		else if (command == "SEARCH")
		{
			phone_book.printContacts();
			std::cout << "Enter index of contact to view details: ";
			std::getline(std::cin, command);

			if (std::cin.eof())
			{
				std::cout << "\nExiting..." << std::endl;
				break;
			}

			if (!command.empty() && std::isdigit(command[0]))
			{
				int index = std::atoi(command.c_str());
				phone_book.searchContact(index);
			}
			else
			{
				std::cout << "❌ Index out of range." << std::endl;
			}
		}
		else if (command == "EXIT")
		{
			std::cout << "👋 Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "❌ Unknown command. Try again." << std::endl;
		}
	}
	return (0);
}

