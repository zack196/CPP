#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
	    std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nbr;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();
		void	display_contact();
		void	creat_contact(std::string first_name , std::string last_name 
			, std::string nickname , std::string phone_nbr 
			, std::string darkest_secret);

};




# endif