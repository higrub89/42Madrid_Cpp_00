#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact();
		~Contact();

		// Método para establecer la información del contacto
		void    setInfo(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret);
		
		// Métodos para obtener la información (Getters) necesarios para la búsqueda/visualización
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		
		// Método auxiliar para mostrar toda la info de un contacto
		void    displayFullInfo() const;
};

#endif
