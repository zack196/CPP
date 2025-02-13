#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria("ice") 
{
    (void) copy;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice &rhs)
{
    (void) rhs;
    return *this ;
}

AMateria* Ice::clone() const
{
    return new Ice(*this) ;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
