#ifndef AMateria_hpp
#define AMateria_hpp

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria & type);
        AMateria();
        virtual ~AMateria();
        AMateria&   operator=(const AMateria &rhs);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
#endif