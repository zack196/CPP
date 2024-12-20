#include "Contact.hpp"

Contact::Contact() //: first_name("-"), last_name("-"), nickname("-")
	//, phone_nbr("-"), darkest_secret("-")
{
}

Contact::~Contact()
{
}

void	Contact::creat_contact(std::string first_name, std::string last_name
	, std::string nickname, std::string phone_nbr, std::string darkest_secret)
{
	if (first_name.size() > 10)
	{
		first_name.resize(9);
		first_name += '.';
	}
	else
		first_name.resize(10, ' ');

	if (last_name.size() > 10)
	{
		last_name.resize(9);
		last_name += '.';
	}
	else
		last_name.resize(10, ' ');

	if (nickname.size() > 10)
	{
		nickname.resize(9);
		nickname += '.';
	}
	else
		nickname.resize(10, ' ');

	if (phone_nbr.size() > 10)
	{
		phone_nbr.resize(9);
		phone_nbr += '.';
	}
	else
		phone_nbr.resize(10, ' ');

	if (darkest_secret.size() > 10)
	{
		darkest_secret.resize(9);
		darkest_secret += '.';
	}
	else
		darkest_secret.resize(10, ' ');
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_nbr = phone_nbr;
	this->darkest_secret = darkest_secret;
}

void Contact::display_contact()
{
	std::cout << this->first_name << "|" << this->last_name << "|" 
		<< this->nickname << "|" << this->phone_nbr << "|" 
		<< this->darkest_secret << std::endl;
}
