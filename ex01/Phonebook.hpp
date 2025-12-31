/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:44:14 by rhiguita          #+#    #+#             */
/*   Updated: 2025/12/31 14:44:16 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook 
{
    private :
        Contact _contacts[8];
        int _index;
        int _count;

        std::string _truncate(std::string str) const;
        void _displaySpecificContact() const;

    public:
        PhoneBook();
        ~PhoneBook();

        void addContacts();
        void searchContacts() const;
};

#endif
