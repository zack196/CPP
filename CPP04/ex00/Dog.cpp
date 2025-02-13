#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default Dog is Constructed" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Copy Dog has been constructed!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog has been destructed!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog is barking!!" << std::endl; 
}
