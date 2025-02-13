#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    me->equip(cure);//0
    me->equip(ice);//1
    me->unequip(1);
    me->equip(ice);//1
    me->equip(cure);//2
    me->unequip(2);
    me->unequip(2);
    me->unequip(7);
    ICharacter* bob = new Character("bob");
    // 0 1 
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    delete ice;
    delete cure;

    return 0;
}

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     delete tmp;
    
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     delete tmp;
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }