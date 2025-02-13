/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:42:14 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/11 17:13:11 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_hpp
#define Contact_hpp


#include <iostream>

class Contact
{
private :
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_nbr;
    std::string dark_secret;
public :

    void    set_first_name(std::string f_name);
    void    set_last_name(std::string l_name);
    void    set_nick_name(std::string n_name);
    void    set_phone_nbr(std::string phone);
    void    set_dark_secret(std::string dark);

    std::string    get_first_name(void);
    std::string    get_last_name(void);
    std::string    get_nick_name(void);
    std::string    get_phone_nbr(void);
    std::string    get_dark_secret(void);

    Contact(std::string first, std::string last, std::string nick
        , std::string phone, std::string dark);
    Contact();
    ~Contact();
    void    print_contact();
    bool    contact_empty();
    void    print_pb_contact(int index);
};


bool	str_isclean(std::string str);

#endif