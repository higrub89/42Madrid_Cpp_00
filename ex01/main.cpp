/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:42:52 by rhiguita          #+#    #+#             */
/*   Updated: 2025/12/31 14:42:54 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        std::cout << "Please Enter command: <ADD> <SEARCH> <EXIT>" << std::endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nInterruption detected. Shutting down..." << std::endl;
            break;   
        }

        if (command == "ADD" || command == "add")
            book.addContacts();
        else if (command == "SEARCH" || command == "search")
            book.searchContacts();
        else if (command == "EXIT" || command == "exit")
            break;
        else if (!command.empty())
            std::cout << "Error: Invalid command." << std::endl;
    }
    return (0);
}
