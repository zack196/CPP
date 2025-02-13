#ifndef MateriaSource_hpp
#define MateriaSource_hpp

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    protected :
        AMateria    *slot[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource&  operator=(const MateriaSource &rhs);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif