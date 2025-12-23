#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void    Contact::setInfo(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret)
{
	this->_firstName = fName;
	this->_lastName = lName;
	this->_nickname = nName;
	this->_phoneNumber = pNumber;
	this->_darkestSecret = dSecret;
}

std::string Contact::getFirstName() const { return this->_firstName; }
std::string Contact::getLastName() const { return this->_lastName; }
std::string Contact::getNickname() const { return this->_nickname; }

void    Contact::displayFullInfo() const
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
