#include "Contact.hpp"

/**
 * Constructor: Inicializa la pieza en un estado neutro.
 */
Contact::Contact() {}

/**
 * Destructor: Limpieza de la pieza al ser desechada.
 */
Contact::~Contact() {}

/**
 * @brief Inyección de datos mediante referencia constante.
 * Usamos const std::string& para evitar duplicar la memoria en el stack,
 * lo cual mejora el rendimiento del sistema.
 */
void Contact::setInfo(const std::string& fName, const std::string& lName, 
                      const std::string& nName, const std::string& pNum, 
                      const std::string& dSecret) {
    this->_firstName = fName;
    this->_lastName = lName;
    this->_nickName = nName;
    this->_phoneNumber = pNum;
    this->_darkestSecret = dSecret;
}

// Getters: Acceso de solo lectura blindado con 'const'
std::string Contact::getFirstName() const { return (this->_firstName); }
std::string Contact::getLastName() const { return (this->_lastName); }
std::string Contact::getNickName() const { return (this->_nickName); }

/**
 * @brief Visualización de telemetría completa.
 * Este método solo se llama cuando el usuario selecciona un índice válido.
 * Al ser 'const', garantizamos que no se altera el estado del contacto.
 */
void Contact::displayFull() const {
    std::cout << "\n--- CONTACT DETAILS ---" << std::endl;
    std::cout << "First Name:     " << this->_firstName << std::endl;
    std::cout << "Last Name:      " << this->_lastName << std::endl;
    std::cout << "Nickname:       " << this->_nickName << std::endl;
    std::cout << "Phone Number:   " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}