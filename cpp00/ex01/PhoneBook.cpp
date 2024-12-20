#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	int	i;

	i = 0;
	while (i < 8)
	{
		contacts[i] = Contact();
		i++;
	}
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::phone_search()
{
	int	i = 0;

	while (i < 8)
	{
		contacts[i].display_contact();
		i++;
	}
}

std::string	get_val()
{
	std::string	str;

	getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "end of file reached" <<std::endl;
		exit(0);
	}
	return (str);
}

void PhoneBook::add_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_nbr;
	std::string	darkest_secret;
	static int	i;

	std::cout << "first_name : ";
	first_name = get_val();
	if (first_name.size() == 0)
	{
		std::cout << "A contact can t have an empty field\n";
		return ;
	}
	std::cout << "last_name : ";
	last_name = get_val();
	if (last_name.size() == 0)
	{
		std::cout << "A contact can t have an empty field\n";
		return ;
	}
	std::cout << "nickname : ";
	nickname = get_val();
	if (nickname.size() == 0)
	{
		std::cout << "A contact can t have an empty field\n";
		return ;
	}
	std::cout << "phone_nbr : ";
	phone_nbr = get_val();
	if (phone_nbr.size() == 0)
	{
		std::cout << "A contact can t have an empty field\n";
		return ;
	}
	std::cout << "darkest_secret : ";
	darkest_secret = get_val();
	if (darkest_secret.size() == 0)
	{
		std::cout << "A contact can t have an empty field\n";
		return ;
	}
	contacts[i].creat_contact(first_name, last_name, nickname, phone_nbr
		, darkest_secret);
	i++;
	if (i == 8)
		i = 0;
}
