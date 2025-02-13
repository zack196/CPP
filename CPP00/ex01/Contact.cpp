/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:42:02 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/11 16:22:03 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first_n, std::string last_n, std::string nick_n
    , std::string phone, std::string dark)
{
	this->first_name = first_n;
    this->last_name = last_n;
    this->nick_name = nick_n;
    this->phone_nbr = phone;
    this->dark_secret = dark;
}

Contact::Contact(){}

Contact::~Contact(){}

void    Contact::print_contact()
{
	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nick_name << std::endl;
	std::cout << "phone number : " << phone_nbr << std::endl;
	std::cout << "darkest secret : " << dark_secret << std::endl;
}

bool    Contact::contact_empty()
{
	if (first_name.size() != 0)
		return (false);
	return (true);
}

std::string	ft_trim(std::string str)
{
	int	size;

	size = str.size();
	if (size > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	else if (size < 10)
		str.insert(0, 10 - size, ' ');
	return (str);
}

void    Contact::print_pb_contact(int index)
{	
	char	ch_index;

	ch_index = index + '0' + 1;
	std::string	s(1, ch_index);
	std::cout << ft_trim(s) << "|" << ft_trim(first_name) << "|"
		<< ft_trim(last_name) << "|" << ft_trim(nick_name) << "|" << std::endl;
}

/*setters and getters*/

std::string Contact::get_first_name()
{
	return (first_name);
}

std::string Contact::get_last_name()
{
	return (last_name);
}

std::string Contact::get_nick_name()
{
	return (nick_name);
}

std::string Contact::get_phone_nbr()
{
	return (phone_nbr);
}

std::string Contact::get_dark_secret()
{
	return (dark_secret);
}

void    Contact::set_first_name(std::string f_name)
{
	first_name = f_name;
}
void    Contact::set_last_name(std::string l_name)
{
	last_name = l_name;
}
void    Contact::set_nick_name(std::string n_name)
{
	nick_name = n_name;
}
void    Contact::set_phone_nbr(std::string phone)
{
	phone_nbr = phone;	
}
void    Contact::set_dark_secret(std::string dark)
{
	dark_secret = dark;
}
