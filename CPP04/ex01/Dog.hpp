#ifndef Dog_hpp
#define Dog_hpp

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
private:
    Brain   *mind;
public:
    Dog();
    Dog(const Dog &src);
    ~Dog();
    Dog &operator=(const Dog &rhs);

    void    makeSound(void) const ;

    void    change_ith_idea(int i, std::string idea);
    void    enouce_ith_idea(int i);
};


#endif