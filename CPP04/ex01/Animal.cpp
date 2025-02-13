#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "default Animal is constructed" << std::endl; 
}

Animal::Animal(std::string a_type) : type(a_type)
{
    std::cout << "typed Animal is constructed!" << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
    std::cout << "Animal constructed by copy!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal is destructed!" << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal make a sound!" << std::endl;
}

std::string    Animal::getType() const
{
    return (type);
}