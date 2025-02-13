#ifndef Cat_hpp
#define Cat_hpp

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain*  mind;   
public:

    Cat();
    Cat(const Cat &src);
    ~Cat();
    Cat &operator=(const Cat &rhs);

    void    makeSound(void) const ;
    void    change_ith_idea(int i, std::string idea);
    void    enouce_ith_idea(int i);
};



#endif