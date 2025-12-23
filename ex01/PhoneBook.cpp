#include "PhoneBook.hpp"
#include <limits> // Para limpiar el input buffer

PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::_formatField(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void    PhoneBook::addContact()
{
	std::string fName, lName, nName, pNumber, dSecret;

	std::cout << "\n--- ADDING NEW CONTACT ---" << std::endl;
	
	// En C++ moderno, si quieres leer lineas con espacios, usa std::getline
	// Si solo quieres palabras, std::cin >> var
	
	std::cout << "First Name: ";
	std::getline(std::cin, fName);
	// Validacion simple: no campos vacios (opcional pero recomendada)
	while (fName.empty()) {
		std::cout << "Field cannot be empty. First Name: ";
		std::getline(std::cin, fName);
	}

	std::cout << "Last Name: ";
	std::getline(std::cin, lName);
	while (lName.empty()) {
		std::cout << "Field cannot be empty. Last Name: ";
		std::getline(std::cin, lName);
	}

	std::cout << "Nickname: ";
	std::getline(std::cin, nName);
	while (nName.empty()) {
		std::cout << "Field cannot be empty. Nickname: ";
		std::getline(std::cin, nName);
	}

	std::cout << "Phone Number: ";
	std::getline(std::cin, pNumber);
	while (pNumber.empty()) {
		std::cout << "Field cannot be empty. Phone Number: ";
		std::getline(std::cin, pNumber);
	}

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, dSecret);
	while (dSecret.empty()) {
		std::cout << "Field cannot be empty. Darkest Secret: ";
		std::getline(std::cin, dSecret);
	}

	// Guardamos en el indice actual
	this->_contacts[this->_currentIndex].setInfo(fName, lName, nName, pNumber, dSecret);
	
	// Actualizamos indices
	this->_currentIndex++;
	if (this->_currentIndex >= 8)
		this->_currentIndex = 0; // Volver al inicio (circular)
	
	if (this->_totalContacts < 8)
		this->_totalContacts++;
		
	std::cout << "--- Contact added successfully! ---\n" << std::endl;
}

void    PhoneBook::searchContacts() const
{
	if (this->_totalContacts == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < this->_totalContacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1; // Mostramos indice 1-8 en lugar de 0-7 para el usuario
		std::cout << "|" << std::setw(10) << _formatField(this->_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << _formatField(this->_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << _formatField(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;

	std::cout << "Enter index to view details (0 to cancel): ";
	int index;
	// Proteccion básica de input numérico
	if (!(std::cin >> index))
	{
		std::cout << "Invalid input." << std::endl;
		std::cin.clear(); // Limpiar flags de error
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar input
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer despues de leer el int

	if (index > 0 && index <= this->_totalContacts)
	{
		this->_contacts[index - 1].displayFullInfo();
	}
	else if (index != 0)
	{
		std::cout << "Index out of range." << std::endl;
	}
}
