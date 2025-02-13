#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "default AAnimal is constructed" << std::endl; 
}

AAnimal::AAnimal(std::string a_type) : type(a_type)
{
    std::cout << "typed AAnimal is constructed!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : type(src.type)
{
    std::cout << "AAnimal constructed by copy!" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal is destructed!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

std::string    AAnimal::getType() const
{
    return (type);
}