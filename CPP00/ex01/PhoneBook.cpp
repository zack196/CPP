/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:30:50 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/11 15:49:10 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

bool	str_isclean(std::string str)
{
	std::string	res;

	for (int i = 0; str[i]; i++)
		if (!isalnum(str[i]) && str[i] != '-')
			return false;
	return true;
}

std::string	remove_white_space(std::string str)
{
	std::string	res;

	for (int i = 0; str[i]; i++)
		if (!isspace(str[i]))
			res += str[i];
	return (res);			
}

std::string	get_input(std::string field)
{
    std::string	input;

	do{
		std::cout << field;
		getline(std::cin, input);
		if (!str_isclean(input))
			std::cout << "input can't have non alphanumeric characters exept dash (-)!" << std::endl;
	} while (!str_isclean(input));
	
	if (!input.compare(""))
	{
	    std::cout << "A saved contact can't have empty fields" << std::endl;
	    return ("");
	}
	if (!field.compare("phone number : "))
	{
	    for (int i = 0; input[i]; i++)
	        if ('0' > input[i] || input[i] > '9')
	        {
	            std::cout << "phone number shoud have just numbers" << std::endl;
	            return ("");
	        }
	}
	return (input);
}

void	PhoneBook::add_contact()
{
    std::string first_name;
	static int	static_index;
    std::string last_name;
    std::string nick_name;
    std::string phone_nbr;
    std::string dark_secret;
    
	std::cout << "use only alpha numeric characters, and replace space by -  !" << std::endl;
	
	do {
		first_name = get_input("first name : ");
	} while (!first_name.length() && !std::cin.eof());
	if (std::cin.eof())
		return ;
	
	do {
		last_name = get_input("last name : ");
	} while (!last_name.length() && !std::cin.eof());
	if (std::cin.eof())
		return ;
	
	do {
		nick_name = get_input("nick name : ");
	} while (!nick_name.length() && !std::cin.eof());
	if (std::cin.eof())
		return ;

	do {
		phone_nbr = get_input("phone number : ");
	} while (!phone_nbr.length() && !std::cin.eof());
	if (std::cin.eof())
		return ;

	do {
		dark_secret = get_input("dark sucret :");
	} while (!dark_secret.length() && !std::cin.eof());
	if (std::cin.eof())
		return ;
	
	int	index = static_index % 8;
	
	Contact	new_contact(first_name, last_name, nick_name, phone_nbr
		, dark_secret);
	
	this->pb_contact[index] = new_contact;
	static_index++;
}

void	PhoneBook::search_contact()
{
	int			i;
	int			index;
	std::string	str_index;
	
	i = -1;
	while (++i < 8 && !pb_contact[i].contact_empty())
		pb_contact[i].print_pb_contact(i);
	if (pb_contact[0].contact_empty())
	{
		std::cout << "Phone Book empty!" << std::endl;
		return ;
	}
	std::cout << "What is the index of your contact : ";
	getline(std::cin, str_index);
	if ((str_index.length() != 1) || !('1' <= str_index[0] && str_index[0] <= '8'))
	{
		std::cout << "the index shoud be a number between 1 and 8 with no sign." << std::endl;
		return ;
	}
	index = str_index[0] - '0';
	index--;
	if (index >= i)
	{
		std::cout << "there is only " << i << " contact in the phone book!" 
			<< std::endl;
		return ;
	}
	pb_contact[index].print_contact();
}

