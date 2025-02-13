#ifndef Cat_hpp
#define Cat_hpp

#include "Animal.hpp"

class Cat : public Animal
{
private:
public:
    Cat();
    Cat(const Cat &src);
    ~Cat();
    Cat &operator=(const Cat &rhs);

    void    makeSound(void) const ;
};



#endif