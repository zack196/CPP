#ifndef Dog_hpp
#define Dog_hpp

#include "Animal.hpp"

class Dog : public Animal
{
private:
    
public:
    Dog();
    Dog(const Dog &src);
    ~Dog();
    Dog     &operator=(const Dog &rhs);

    void    makeSound(void) const ;
};



#endif