#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    mind = new Brain();
    for(int i = 0; i < 100; i++)
        mind->put_ith_idea(i , "bark bark !");
    std::cout << "Default Dog is Constructed" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
    this->mind = new Brain();
    for(int i = 0; i < 100; i++)
        mind->put_ith_idea(i , src.mind->get_ith_idea(i));
    std::cout << "Copy Dog has been constructed!" << std::endl;
}

Dog::~Dog()
{
    delete this->mind;
    std::cout << "Dog has been destructed!" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog is barking!!" << std::endl; 
}


Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        delete this->mind;
        this->mind = new Brain();
        for (int i = 0; i < 100; i++)
            this->mind->put_ith_idea(i, rhs.mind->get_ith_idea(i));
        this->type = rhs.type;
    }
    return (*this);
}

void    Dog::change_ith_idea(int i, std::string idea)
{
    if (0 <= i && i < 100)
        mind->put_ith_idea(i, idea);
}

void    Dog::enouce_ith_idea(int i)
{
    if (0 <= i && i < 100)
    std::cout << mind->get_ith_idea(i) << std::endl; 
}