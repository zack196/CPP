#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default cat has been constructed" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Copy cat has been constructed" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat has been destructed!" << std::endl; 
}


Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "The cat is Meowing!" << std::endl;
}