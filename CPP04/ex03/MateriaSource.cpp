#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) 
{
    for (int i = 0; i < 4; i++)
        slot[i] = (copy.slot[i])? copy.slot[i]->clone() : NULL;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            delete slot[i];
            slot[i] = (rhs.slot[i])? rhs.slot[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete slot[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!slot[i])
        {
            slot[i] = m->clone();
            break ;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] && slot[i]->getType() == type)
            return slot[i]->clone();
    }
    return NULL;
}
