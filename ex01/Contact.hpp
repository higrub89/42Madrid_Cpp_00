/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:43:13 by rhiguita          #+#    #+#             */
/*   Updated: 2025/12/31 14:43:24 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact 
{
    private: 
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        ~Contact(); 

        // el contact recibe datos, no los solicita él mismo (Single Responsibility)
        void    setInfo(const std::string& fName, const std::string& lName, 
                        const std::string& nName, const std::string& pNum, 
                        const std::string& dSecret);

        // Getters marcados como const: seguridad total para el sistema
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;

        // Métodos de visualización que no alteran el estado.
        void    displayFull() const;
    
};

#endif
