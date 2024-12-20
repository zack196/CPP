#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	phone_search();
		void	add_contact();
};




#endif