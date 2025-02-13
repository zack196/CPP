#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong animal")
{
    std::cout << "default Wrong Animal is constructed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string w_type) : type(w_type)
{
    std::cout << "typed Wrong Animal is constructed!" << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
    std::cout << "Wrong Animal is constructed by copy!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal is destructed!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Wrong Animal make's a sound!" << std::endl;
}

std::string    WrongAnimal::getType() const
{
    return type;
}

