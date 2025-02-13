#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "wrong cat";
    std::cout << "Default wrong cat has been constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << "Copy wrong cat has been constructed" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "wrong cat has been destructed!" << std::endl; 
}

void    WrongCat::makeSound(void)const
{
    std::cout << "The cat is Meowing!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

std::string WrongCat::getType() const
{
    return type;
}