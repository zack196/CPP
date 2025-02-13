#ifndef Character_hpp
#define Character_hpp

#include "ICharacter.hpp"

#define MAX_UNEQUIP 100

class Character ;

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria    *inven[4];
        // AMateria    *uneq[MAX_UNEQUIP];
        // int         nbr_uneq;
    public:
        Character();
        Character(const Character &copy);
        Character(const std::string &name);
        Character&  operator=(const Character &rhs);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif