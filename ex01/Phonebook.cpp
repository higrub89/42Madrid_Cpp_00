#include "Phonebook.hpp"

//constructor: Sistemas a cero
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