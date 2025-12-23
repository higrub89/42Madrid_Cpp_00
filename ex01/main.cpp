#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook book;
	std::string command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		// std::getline es mejor que std::cin >> command para manejar EOF (Ctrl+D) correctamente
		if (!std::getline(std::cin, command))
			break; // Salir si se detecta EOF (Ctrl+D)

		if (command == "ADD")
		{
			book.addContact();
		}
		else if (command == "SEARCH")
		{
			book.searchContacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
		{
			if (!command.empty())
				std::cout << "Unknown command. Try ADD, SEARCH or EXIT." << std::endl;
		}
	}
	return 0;
}
