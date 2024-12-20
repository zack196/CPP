#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phone_book;
    std::string cmd;

    while (1)
    {
		std::cout << "enter a command : ";
		getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "end of file reached" << std::endl;
			break ;
		}
		else if (!cmd.compare("ADD"))
			phone_book.add_contact();
		else if (!cmd.compare("SEARCH"))
			phone_book.phone_search();
		else if (!cmd.compare("EXIT"))
			exit(0);
		else
			std::cout << "The program only accepts ADD, SEARCH and EXIT."
				<< std::endl;
    }
    return (0);
}
