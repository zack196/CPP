#ifndef Cure_hpp
#define Cure_hpp

#include "AMateria.hpp"

class Cure : public AMateria
{
public :
    Cure();
    Cure(const Cure &copy);
    ~Cure();
    Cure&   operator=(const Cure &rhs);

    AMateria* clone() const;
     void use(ICharacter& target);
};

#endif