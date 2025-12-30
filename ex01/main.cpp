#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook book;
    std::string command;

    std::cout << "--- Welcome to the Phonebook ---" << std::endl;
    while (true)
    {
        std::cout << "Please Enter command: <ADD> <SEARCH> <EXIT>";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nInterruption detected. Shutting down..." << std::endl;
            break;   
        }

        if (command == "ADD")
            book.addContacts();
        else if (command == "SEARCH")
            book.searchContacts();
        else if (command == "EXIT")
            break;
        else if (!command.empty())
            std::cout << "Error: Invalid command." << std::endl;
    }
    return (0);
}