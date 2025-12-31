/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:42:11 by rhiguita          #+#    #+#             */
/*   Updated: 2025/12/31 14:42:14 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setInfo(const std::string& fName, const std::string& lName, 
                      const std::string& nName, const std::string& pNum, 
                      const std::string& dSecret) {
    this->_firstName = fName;
    this->_lastName = lName;
    this->_nickName = nName;
    this->_phoneNumber = pNum;
    this->_darkestSecret = dSecret;
}

std::string Contact::getFirstName() const { return (this->_firstName); }
std::string Contact::getLastName() const { return (this->_lastName); }
std::string Contact::getNickName() const { return (this->_nickName); }

void Contact::displayFull() const {
    std::cout << "\n--- CONTACT DETAILS ---" << std::endl;
    std::cout << "First Name:     " << this->_firstName << std::endl;
    std::cout << "Last Name:      " << this->_lastName << std::endl;
    std::cout << "Nickname:       " << this->_nickName << std::endl;
    std::cout << "Phone Number:   " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
