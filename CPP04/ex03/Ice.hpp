#ifndef Ice_hpp
#define Ice_hpp

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &copy);
    ~Ice();
    Ice &operator=(const Ice &rhs);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif