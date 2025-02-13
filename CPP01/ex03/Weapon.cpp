#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string w_type) : type(w_type) {}

Weapon::~Weapon() 
{
    std::cout << "Weapon has been destryed!" << std::endl;
}

void    Weapon::setType(std::string w_type)
{
    type = w_type;
}

const std::string&    Weapon::getType() const
{
    return (type);
}
