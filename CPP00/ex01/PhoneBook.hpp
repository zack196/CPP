#ifndef Phone_book_hpp
#define Phone_book_hpp

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
private :
    Contact pb_contact[8];
public :
    PhoneBook();
    ~PhoneBook();

    void    add_contact();
    void    search_contact();
    
};

#endif