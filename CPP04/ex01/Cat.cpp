#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    mind = new Brain();
    for(int i = 0; i < 100; i++)
        mind->put_ith_idea(i , "miaow zzzzzzz!");
    std::cout << "Default cat has been constructed" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    this->mind = new Brain();
    for(int i = 0; i < 100; i++)
        mind->put_ith_idea(i , src.mind->get_ith_idea(i));
    std::cout << "Copy cat has been constructed" << std::endl;
}

Cat::~Cat() 
{
    delete this->mind;
    std::cout << "Cat has been destructed!" << std::endl; 
}


Cat &Cat::operator=(const Cat &rhs)
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

void    Cat::makeSound(void) const
{
    std::cout << "The cat is Meowing!" << std::endl;
}

void    Cat::change_ith_idea(int i, std::string idea)
{
    if (i <= 0 && i < 100)
        mind->put_ith_idea(i, idea);
}

void    Cat::enouce_ith_idea(int i)
{
    if (0 <= i && i < 100)
        std::cout << mind->get_ith_idea(i) << std::endl; 
}