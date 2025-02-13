#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria("cure") 
{
    (void)copy;
}

Cure::~Cure() {}

Cure&   Cure::operator=(const Cure &rhs)
{
    (void) rhs;
    return *this ;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
