/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:42:23 by rhiguita          #+#    #+#             */
/*   Updated: 2025/12/31 14:42:28 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _count(0) {
    std::cout <<  "[SYSTEM] PhoneBook initialized." << std::endl;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContacts() {
    std::string info[5];
    std::string labels[5] = {
        "First Name", "Last Name", "Nickname", "Phone Number", "Darkest secret"
    };

    std::cout << "\n--- ADDING NEW CONTACT (index : " << _index << ") ---" << std::endl;

    for (int i = 0; i < 5; i++) {
        while (info[i].empty()) {
            std::cout << labels[i] << ": ";
            if (!std::getline(std::cin, info[i]))
                return ;
            if (info[i].empty())
                std::cout << "[ERROR] Field cannot be empty." << std::endl;
        }
    }

    _contacts[_index].setInfo(info[0], info[1], info[2], info[3], info[4]);

    _index = (_index + 1) % 8;

    if (_count < 8)
        _count++;

    std::cout << "[SUCCESS] Contact stored succesfully.\n" << std::endl;
}

std::string PhoneBook::_truncate(std::string str) const 
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

void PhoneBook::searchContacts() const {
    if (_count == 0) {
        std::cout << "[INFO] PhoneBook is empty. No data to display." << std::endl;
        return;
    }

    std::cout << "|" << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < _count; i++) {
        std::cout << "|" << std::setw(10) << (i + 1); // Mostramos índice 1-8 para el usuario
        std::cout << "|" << std::setw(10) << _truncate(_contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << _truncate(_contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << _truncate(_contacts[i].getNickName()) << "|" << std::endl;
    }

    this->_displaySpecificContact();
}

void PhoneBook::_displaySpecificContact() const {
    std::string input;
    int         index;

    std::cout << "\nEnter index to display details: ";
    if (!std::getline(std::cin, input) || input.empty())
        return;

    if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
        index = input[0] - '0'; // Convertimos char a int
        if (index <= _count) {
            _contacts[index - 1].displayFull(); // El array es 0-indexado
        } else {
            std::cout << "[ERROR] Index out of range. No contact there." << std::endl;
        }
    } else {
        std::cout << "[ERROR] Invalid index format." << std::endl;
    }
}
