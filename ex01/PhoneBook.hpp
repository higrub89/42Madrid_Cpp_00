#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip> // Para setw

class PhoneBook
{
	private:
		Contact _contacts[8];
		int     _currentIndex;
		int     _totalContacts; // Para saber si tenemos 0, 5, u 8 contactos guardados

		// Método privado auxiliar para formatear columnas (ancho 10, truncar con '.')
		std::string _formatField(std::string str) const;

	public:
		PhoneBook();
		~PhoneBook();

		void    addContact();
		void    searchContacts() const;
};

#endif
