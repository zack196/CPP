/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:09:14 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/09 12:28:45 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string	cmd;
    PhoneBook	phone_book;

	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << "end of file reached!" << std::endl;
			return 1;
		}
		std::cout << "enter a command :";
		getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
			phone_book.add_contact();
		else if (!cmd.compare("EXIT"))
			break ;
		else if (!cmd.compare("SEARCH"))
			phone_book.search_contact();
		else
			std::cout << "the disponible commande are : ADD, EXIT, and SEARCH"
				<< std::endl;
	}
	return (0);
}
